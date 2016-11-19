#include "database_service/database_client_proto_api.hpp"
#include "database_service/database_client_calls.hpp"
#include "abstract_client_service.hpp"

#include <service_utils.hpp>
#include <logging/logger.hpp>
#include <helpers/request_adapters.hpp>


namespace services_api
{	
	DatabaseClientProtoApi::DatabaseClientProtoApi(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
	{
		DatabaseClientProtoApi::init();
	}

	DatabaseClientProtoApi::~DatabaseClientProtoApi() {}

	void DatabaseClientProtoApi::init() 
	{
		connect();

		add_call_handler<AsyncGetRequestCall   >();
		add_call_handler<AsyncCommitRequestCall>();
	}

	void DatabaseClientProtoApi::de_init()  {
		stop();
	}

	std::shared_ptr<DataTypes::GetResponse>
		DatabaseClientProtoApi::get(const DataTypes::GetRequest& request)
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
			auto result = utils::service::get_result(call->promise, std::chrono::milliseconds(5000));
			return result;
		}
		catch (std::exception&) {
			return nullptr;
		}
	}

	std::shared_ptr<DataTypes::CommitResponse>
		DatabaseClientProtoApi::commit(const DataTypes::CommitRequest& request)
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
			auto result = utils::service::get_result(call->promise, std::chrono::milliseconds(5000));
			return result;
		}
		catch (std::exception&) {
			return nullptr;
		}
	}
}
