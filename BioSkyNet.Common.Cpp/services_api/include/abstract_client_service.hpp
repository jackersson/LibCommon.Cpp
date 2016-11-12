#ifndef ClientServiceBase_INCLUDED
#define ClientServiceBase_INCLUDED

#include <helpers/service_heplers.hpp>
#include <services/service_address.hpp>
#include <services/iservice.hpp>
#include <src/cpp/server/dynamic_thread_pool.h>
#include <logging/logger.hpp>
#include "helpers/abstract_async_call.hpp"

namespace services_api
{
	//Virtual : 
	// do_set_call_options ( metadata)
	// do_create_stub ( for each client)
	class AbstractClientService : public contracts::services::IService
	{
	public:
		explicit AbstractClientService(contracts::services::IServiceAddress& address);
			   
		virtual ~AbstractClientService();

		void connect();
	
		void start() override;		
		void stop () override;	

	protected:
		mutable contracts::logging::Logger    logger_;

		template <typename T>
		grpc::CompletionQueue* get_completion_queue() const
		{
			return helpers::get_completion_queue<T>(handlers_);			
		}
			
		void set_call_options(IAsyncCall* call) const;
			
		template<typename T>
		void add_call_handler()
		{
			auto cq = std::make_shared<grpc::CompletionQueue>();

			RpcCallbackFunction callback = [cq, this]()	{				
				AbstractClientService::async_complete_rpc<T>(cq.get());
			};		
			
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

		std::string address_;
		//contracts::services::IServiceAddress& address_;

		AbstractClientService(const AbstractClientService&) = delete;
		AbstractClientService& operator=(const AbstractClientService&) = delete;
	};
}

#endif