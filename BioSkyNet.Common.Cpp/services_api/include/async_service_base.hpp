#ifndef AsyncServiceBaseImpl_INCLUDED
#define AsyncServiceBaseImpl_INCLUDED

#include <services/unit_service.grpc.pb.h>
#include <services/iservice.hpp>
#include <services/service_address.hpp>
#include <services/facial_service.grpc.pb.h>

#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <include/grpc++/security/server_credentials.h>
#include <common/logger.hpp>
#include <helpers/service_heplers.hpp>

namespace services_api
{
	typedef
		std::function<void(grpc::ServerCompletionQueue*)>	CreateRequestHandlerFunc;

	typedef Services::BiometricFacialService::AsyncService AsyncFacialService;
	typedef Services::UnitService::AsyncService            AsyncUnitService  ;
	
	template <typename TService>
	class AsyncServiceBase : public contracts::services::IService
	{
	public:
		explicit AsyncServiceBase(contracts::services::IServiceAddress& address
			, grpc::ServerBuilder* server_builder)
			: address_(address)
			, server_builder_(server_builder)
			, cancelation_requested_(false)
			, work_(io_service_)
		{
		}

		virtual ~AsyncServiceBase()		{
			AsyncServiceBase<TService>::stop();
		}		

		void connect()
		{
			auto address = address_.get();
			logger_.info("Try open port on {0}", address);

			server_builder_->AddListeningPort(address, grpc::InsecureServerCredentials());
			server_builder_->RegisterService(&service_);
		}		

		void start() override
		{
			cancelation_requested_ = false;
			for (auto handler : handlers_)
				io_service_.post(handler.callback);

			logger_.info("{0} listening on {1}", class_name(), address_.get());
		}

		void stop() override
		{
			try
			{
				cancelation_requested_ = true;
				for (auto& it : handlers_)
					it.completion_queue->Shutdown();
				io_service_.stop();
				threadpool_.join_all();
				handlers_.clear();
			}
			catch (std::exception&) {
				//Not implemented
			}

			logger_.info("{0} stopped", class_name());
		}


	protected:
		template<typename T>
		void add_rpc_handler()
		{
			auto cq_ = server_builder_->AddCompletionQueue();
			std::shared_ptr<grpc::ServerCompletionQueue> sptr(move(cq_));

			threadpool_.create_thread(
				boost::bind(&boost::asio::io_service::run, &io_service_)
			);		
			RpcCallbackFunction callback = [sptr, this]() {
				AsyncServiceBase::handle_rpc<T>(sptr.get());
			};
			//auto callback = std::bind(&AsyncServiceBase::handle_rpc<T>, this, cq_.get());
			handlers_.push_back(ServerRequestHandler(sptr, callback));
		}

		template <typename T>
		void add_handler_factory_method(CreateRequestHandlerFunc func)
		{		
			auto handler_id = typeid(T).name();
			if (items_.find(handler_id) == items_.end())
				items_[typeid(T).name()] = func;
			else
				throw std::exception("Handler create function exists");
		}

		TService service_;

	private:
		template<typename T>
		void handle_rpc(grpc::ServerCompletionQueue* queue)
		{
			create_handler(typeid(T).name(), queue);
			void* tag;
			bool  ok;

			while (true)
			{
				try
				{
					queue->Next(&tag, &ok);
					if (ok)
						static_cast<T*>(tag)->Proceed();
				}
				catch (std::exception& ex) {
					logger_.error(ex.what());
				}

				if (cancelation_requested_)
					break;
			}
		}

		void create_handler( const std::string& handler_id
		                    , grpc::ServerCompletionQueue* queue)
		{
			auto it = items_.find(handler_id);
			if (items_.find(handler_id) != items_.end()) {
				it->second(queue);
			}
			else
				logger_.error("Not found handler creation method");
		}

		virtual std::string class_name() const = 0;			

		AsyncServiceBase(const AsyncServiceBase&) = delete;
		AsyncServiceBase& operator=(const AsyncServiceBase&) = delete;

		contracts::services::IServiceAddress& address_       ;
		grpc::ServerBuilder*                  server_builder_;

		bool cancelation_requested_;
		ServerRequestHandlers handlers_;

		boost::asio::io_service       io_service_;
		boost::thread_group           threadpool_;
		boost::asio::io_service::work work_      ;
		contracts::logging::Logger    logger_    ;

		std::map<std::string, CreateRequestHandlerFunc> items_;
	};
}

#endif