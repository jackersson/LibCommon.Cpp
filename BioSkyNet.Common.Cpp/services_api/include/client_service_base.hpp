#ifndef ClientServiceBase_INCLUDED
#define ClientServiceBase_INCLUDED

#include <helpers/service_heplers.hpp>
#include <services/service_address.hpp>
#include <services/iservice.hpp>
#include <src/cpp/server/dynamic_thread_pool.h>
#include <logging/logger.hpp>

namespace services_api
{
	class AbstractClientService : public contracts::services::IService
	{
	public:
		explicit AbstractClientService( contracts::services::IServiceAddress& address)
			                         : active_(false)
			                         , thread_pool_(0)
			                         , address_(address)
		{}

		virtual ~AbstractClientService() {
			AbstractClientService::stop();		
		}

		void connect()
		{
			auto address = address_.get();
			logger_.info("Try create channel {0}", address);

			channel_ = CreateChannel(address, grpc::InsecureChannelCredentials());			
		}
		
		void start() override
		{
			if (active_)
				return;

			active_ = true;
			for (auto handler : handlers_)
				thread_pool_.Add(handler.second.callback);

			logger_.info("{0} connected to {1}", class_name(), address_.get());
		}

		void stop() override
		{
			for (auto it : handlers_)
				it.second.completion_queue->Shutdown();
			handlers_.clear();

			logger_.info("{0} stopped", class_name());
		}

	protected:
		mutable contracts::logging::Logger    logger_;

		template <typename T>
		grpc::CompletionQueue* get_completion_queue() const
		{
			return helpers::get_completion_queue<T>(handlers_);			
		}
			
		void set_call_options(IAsyncCall* call) const {
			do_set_call_options(call);

			helpers::set_deadline(call->context, call->deadline);
			helpers::set_metadata(call->context, call->metadata);	
		}
			
		template<typename T>
		void add_call_handler()
		{
			auto cq = std::make_shared<grpc::CompletionQueue>();

			auto callback
				= std::bind(&AbstractClientService::async_complete_rpc<T>, this, cq.get());
			handlers_.insert(std::pair<std::string, ClientRequestHandler>(
				          	typeid(T).name(), ClientRequestHandler(cq, callback)));
		}

		virtual void do_set_call_options(IAsyncCall* call) const {}

	private:
		virtual void do_create_stub     ( std::shared_ptr<grpc::Channel> channel) = 0;

		template <typename T>
		void async_complete_rpc(grpc::CompletionQueue* queue) const
		{
			void* got_tag;
			auto  ok = false;

			while (queue->Next(&got_tag, &ok))
			{
				auto call = static_cast<T*>(got_tag);
				try
				{
					if (call->status.ok())
						call->process();
				}
				catch (std::exception& ex) {
					logger_.error(ex.what());
				}

				delete call;
			}
		}

		virtual std::string class_name() const = 0;

		bool active_;

		std::shared_ptr<grpc::Channel> channel_    ;
		ClientRequestHandlers          handlers_   ;
		grpc::DynamicThreadPool        thread_pool_;

		contracts::services::IServiceAddress& address_;

		AbstractClientService(const AbstractClientService&) = delete;
		AbstractClientService& operator=(const AbstractClientService&) = delete;
	};
}

#endif