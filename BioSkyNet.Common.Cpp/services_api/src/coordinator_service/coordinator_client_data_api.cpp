#include "coordinator_service/coordinator_client_data_api.hpp"

#include <data/models/commands.hpp>
#include <data/models/queries.hpp>

#include "helpers/request_adapters.hpp"
#include <datatypes/commands.pb.h>
#include <datatypes/queries.pb.h>

namespace services_api
{
	CoordinatorClientDataApi::CoordinatorClientDataApi(contracts::services::IServiceAddress& address)
			: CoordinatorClientProtoApi(address)
		{}

		bool CoordinatorClientDataApi::connect_request(const data_model::ConnectMsg& request)
		{
			if (!connect_msg_.has_id())
				connect_msg_ = helpers::to_proto_connect_msg(request);
			return CoordinatorClientProtoApi::connect_request(connect_msg_);
		}

		bool CoordinatorClientDataApi::heart_beat(const data_model::HeartbeatMessage& request) const
		{
			if (!heartbeat_msg_.has_id())
				heartbeat_msg_ = helpers::to_proto_heartbeat_msg(request);
			return CoordinatorClientProtoApi::heart_beat(heartbeat_msg_);
		}

		//TODO send with guid in metadata
		void CoordinatorClientDataApi::update_devices(const data_model::DeviceUpdate& request) const
		{
			auto proto_request = helpers::to_proto_device_update(request);
			return CoordinatorClientProtoApi::update_devices(proto_request);
		}

		std::shared_ptr<data_model::GetResponse>
			CoordinatorClientDataApi::get(const data_model::GetRequest& request) 
		{
			auto proto_request = helpers::to_proto_get_request(request);
			auto result = CoordinatorClientProtoApi::get(proto_request);

			if (result == nullptr)
				return nullptr;
			auto adapted = helpers::to_data_get_response(*result);
			return std::make_shared<data_model::GetResponse>(adapted);
		}

		//TODO send with guid in metadata
		std::shared_ptr<data_model::CommitResponse>
			CoordinatorClientDataApi::commit(const data_model::CommitRequest& request) 
		{
			auto proto_request = helpers::to_proto_commit_request(request);
			auto result = CoordinatorClientProtoApi::commit(proto_request);

			if (result == nullptr)
				return nullptr;
			auto adapted = helpers::to_data_commit_response(*result);
			return std::make_shared<data_model::CommitResponse>(adapted);
		}	
}
