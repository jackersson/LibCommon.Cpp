#ifndef CoordinatorClientDataApi_INCLUDED
#define CoordinatorClientDataApi_INCLUDED

#include <services/service_address.hpp>
#include <services/idatabase_api.hpp>
#include <services/icoordinator_api.hpp>
#include "coordinator_client_proto_api.hpp"

namespace services_api
{
	class CoordinatorClientDataApi : public CoordinatorClientProtoApi
		                             , public contracts::services::IDatabaseApi
		                             , public contracts::services::ICoordinatorApi
	{
	public:
		explicit CoordinatorClientDataApi(contracts::services::IServiceAddress& address);
			
		bool connect_request(const data_model::ConnectMsg& request)  override;

		void heart_beat(const data_model::HeartbeatMessage& request) const override;
		//TODO send with guid in metadata
		void update_devices(const data_model::DeviceUpdate& request) const override;
		
		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override;		

		//TODO send with guid in metadata
		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override;
		

	private:		
		CoordinatorClientDataApi(const CoordinatorClientDataApi&) = delete;
		CoordinatorClientDataApi& operator=(const CoordinatorClientDataApi&) = delete;

		DataTypes::ConnectMsg       connect_msg_  ;
		mutable DataTypes::HeartbeatMessage heartbeat_msg_;
	};
}

#endif