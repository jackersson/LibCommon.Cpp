#ifndef CoordinatorClientDataApi_INCLUDED
#define CoordinatorClientDataApi_INCLUDED

#include <services/service_address.hpp>
#include <data/models/commands.hpp>
#include <data/models/queries.hpp>
#include <services/idatabase_api.hpp>
#include <services/icoordinator_api.hpp>
#include <helpers/request_adapters.hpp>
#include "coordinator_client_proto_api.hpp"

namespace services_api
{
	class CoordinatorClientDataApi : public CoordinatorClientProtoApi
		                             , public contracts::services::IDatabaseApi
		                             , public contracts::services::ICoordinatorApi
	{
	public:
		explicit CoordinatorClientDataApi(contracts::services::IServiceAddress& address)
			: CoordinatorClientProtoApi(address)
		{}

		bool connect_request(const data_model::ConnectMsg& request) override
		{
			if (!connect_msg_.has_id())
				connect_msg_ = helpers::to_proto_connect_msg(request);
			return CoordinatorClientProtoApi::connect_request(connect_msg_);
		}

		void heart_beat(const data_model::HeartbeatMessage& request) const override
		{
			if (!heartbeat_msg_.has_id())
				heartbeat_msg_ = helpers::to_proto_heartbeat_msg(request);
			return CoordinatorClientProtoApi::heart_beat(heartbeat_msg_);
		}

		//TODO send with guid in metadata
		void update_devices(const data_model::DeviceUpdate& request) const override
		{
			auto proto_request = helpers::to_proto_device_update(request);
			return CoordinatorClientProtoApi::update_devices(proto_request);
		}

		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override
		{
			auto proto_request = helpers::to_proto_get_request(request);
			auto result        = CoordinatorClientProtoApi::get(proto_request);

			auto adapted      = helpers::to_data_get_response(*result);
			return std::make_shared<data_model::GetResponse>(adapted);		
		}

		//TODO send with guid in metadata
		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override
		{
			auto proto_request = helpers::to_proto_commit_request(request);
			auto result        = CoordinatorClientProtoApi::commit(proto_request);

			auto adapted = helpers::to_data_commit_response(*result);
			return std::make_shared<data_model::CommitResponse>(adapted);
		}

	private:		
		CoordinatorClientDataApi(const CoordinatorClientDataApi&) = delete;
		CoordinatorClientDataApi& operator=(const CoordinatorClientDataApi&) = delete;

		DataTypes::ConnectMsg       connect_msg_  ;
		mutable DataTypes::HeartbeatMessage heartbeat_msg_;
	};
}

#endif