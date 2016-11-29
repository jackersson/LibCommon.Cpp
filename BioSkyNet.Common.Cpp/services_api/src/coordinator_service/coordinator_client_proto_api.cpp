#include "coordinator_service/coordinator_client_proto_api.hpp"

#include <service_utils.hpp>

#include "helpers/request_adapters.hpp"
#include "coordinator_service/coordinator_client_calls.hpp"
#include "database_service/database_client_calls.hpp"

namespace services_api
{
	CoordinatorClientProtoApi::CoordinatorClientProtoApi(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
		{
			CoordinatorClientProtoApi::init();
		}

	CoordinatorClientProtoApi::~CoordinatorClientProtoApi() {
			CoordinatorClientProtoApi::de_init();
		}

		void CoordinatorClientProtoApi::init() 
		{
			connect();

			add_call_handlers();
		}
	
		void CoordinatorClientProtoApi::add_call_handlers()
		{
			add_call_handler<AsyncConnectCall      >();
			add_call_handler<AsyncHeartbeatCall    >();
			//add_call_handler<AsyncUpdateDevicesCall>();
			add_call_handler<AsyncGetRequestCall   >();
			add_call_handler<AsyncCommitRequestCall>();
		}

	
		void CoordinatorClientProtoApi::de_init()  {
			stop();
		}

		bool CoordinatorClientProtoApi::connect_request(const DataTypes::ConnectMsg& request)
		{
			auto queue = get_completion_queue<AsyncConnectCall>();
			if (queue == nullptr)	return false;

			auto call = new AsyncConnectCall;
			set_call_options(call);
			call->reader = stub_->AsyncConnect(&call->context, request, queue);
			call->reader->Finish(&call->response
				, &call->status
				, reinterpret_cast<void*>(call));

			//TODO check if there is a need to handle exception here
			try
			{
				auto result = utils::service::get_result(call->promise
					                                      , std::chrono::seconds(3));
				return result;
			}
			catch (std::exception& exception) {
				logger_.error("Connect request exception : {0}", exception.what());
				return false;
			}
		}

		bool CoordinatorClientProtoApi::heart_beat(const DataTypes::HeartbeatMessage& request) const
		{
			auto queue = get_completion_queue<AsyncHeartbeatCall>();
			if (queue == nullptr)	return false;

			auto call = new AsyncHeartbeatCall;
			set_call_options(call);
			call->reader = stub_->AsyncHeartbeat(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			try {
				utils::service::get_result(call->promise, std::chrono::seconds(1));
				return true;
			}
			catch (std::exception& exception) {
				//TODO handle broken promise as no response from server
				logger_.error("Coordinator client {0}", exception.what());
				return false;
			}
		}

		//TODO send with guid in metadata
		void CoordinatorClientProtoApi::update_devices(const DataTypes::DeviceUpdate& request) const
		{
			auto queue = get_completion_queue<AsyncUpdateDevicesCall>();
			if (queue == nullptr)	return;

			auto call = new AsyncUpdateDevicesCall;
			set_call_options(call);
			call->reader = stub_->AsyncUpdateDevices(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));
		}

		std::shared_ptr<DataTypes::GetResponse>
			CoordinatorClientProtoApi::get(const DataTypes::GetRequest& request)
		{
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

		//TODO send with guid in metadata
		std::shared_ptr<DataTypes::CommitResponse>
			CoordinatorClientProtoApi::commit(const DataTypes::CommitRequest& request)
		{
			DataTypes::MessageBytes message;
			helpers::to_message_bytes(request, message);

			auto queue = get_completion_queue<AsyncCommitRequestCall>();
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
