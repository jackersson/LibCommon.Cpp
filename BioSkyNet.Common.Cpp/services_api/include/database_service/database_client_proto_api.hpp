#ifndef DatabaseClientProtoApi_INCLUDED
#define DatabaseClientProtoApi_INCLUDED

#include <services/database_service.grpc.pb.h>
#include "database_service/database_client_calls.hpp"
#include <service_utils.hpp>
#include <services/service_address.hpp>
#include <logging/logger.hpp>
#include <helpers/request_adapters.hpp>
#include "abstract_client_service.hpp"

namespace services_api
{
	class DatabaseClientProtoApi : public AbstractClientService		                       
	{
	public:
		explicit DatabaseClientProtoApi( contracts::services::IServiceAddress& address)
			                             : AbstractClientService(address)
		{
			DatabaseClientProtoApi::init();
		}

		virtual ~DatabaseClientProtoApi() {}	

		void init() override
		{
			connect();

			add_call_handler<AsyncGetRequestCall   >();
			add_call_handler<AsyncCommitRequestCall>();
		}

		void de_init() override	{
			stop();
		}
		
		std::shared_ptr<DataTypes::GetResponse>
			get(const DataTypes::GetRequest& request)
		{
			logger_.info("{0} Get request ", class_name());

			DataTypes::MessageBytes message;		
			helpers::to_message_bytes(request, message);

			auto queue = get_completion_queue<AsyncGetRequestCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncGetRequestCall;
			set_call_options(call);
			call->reader = stub_->AsyncGet(&call->context, message, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			try
			{
				auto result = utils::service::get_result(call->promise, std::chrono::milliseconds(300));
				return result;
			}
			catch (std::exception&) {
				return nullptr;
			}
		}

		std::shared_ptr<DataTypes::CommitResponse>
			commit(const DataTypes::CommitRequest& request) 
		{
			DataTypes::MessageBytes message;
			helpers::to_message_bytes(request, message);

			auto queue = get_completion_queue<AsyncGetRequestCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncCommitRequestCall;
			set_call_options(call);
			call->reader = stub_->AsyncCommit(&call->context, message, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			try
			{
				auto result = utils::service::get_result(call->promise, std::chrono::milliseconds(300));
				return result;
			}
			catch (std::exception&) {
				return nullptr;
			}
		}

	private:
		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::DatabaseService::NewStub(channel);
		}
	
		std::string class_name() const override {
			return typeid(DatabaseClientProtoApi).name();
		}
				
		std::unique_ptr<Services::DatabaseService::Stub> stub_;
		
		DatabaseClientProtoApi(const DatabaseClientProtoApi&) = delete;
		DatabaseClientProtoApi& operator=(const DatabaseClientProtoApi&) = delete;
	};
}

#endif