#ifndef CoordinatorClientProtoApi_INCLUDED
#define CoordinatorClientProtoApi_INCLUDED

#include <services/coordinator_service.grpc.pb.h>
#include <services/service_address.hpp>
#include "abstract_client_service.hpp"

namespace DataTypes
{
	class GetResponse  ;
	class GetRequest    ;
	class CommitResponse;
	class CommitRequest ;
}

namespace services_api
{
	//Virtual:
	//add_call_handlers (if we do't want to use other call handlers
	class CoordinatorClientProtoApi : public AbstractClientService				                          
	{
	public:
		explicit CoordinatorClientProtoApi(contracts::services::IServiceAddress& address);
	
		~CoordinatorClientProtoApi();

	protected:
		virtual void add_call_handlers();

	public:
		void init   () override;
		void de_init() override;
		
		bool connect_request(const DataTypes::ConnectMsg& request);	
	
		void heart_beat(const DataTypes::HeartbeatMessage& request) const;		

		//TODO send with guid in metadata
		void update_devices(const DataTypes::DeviceUpdate& request) const;	

		std::shared_ptr<DataTypes::GetResponse>
			get(const DataTypes::GetRequest& request);
	
		//TODO send with guid in metadata
		std::shared_ptr<DataTypes::CommitResponse>
			commit(const DataTypes::CommitRequest& request);		
		
	private:		
		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override	{
			stub_ = Services::CoordinatorService::NewStub(channel);
		}

		std::string class_name() const override {
			return typeid(CoordinatorClientProtoApi).name();
		}
		
		std::unique_ptr<Services::CoordinatorService::Stub> stub_;

		CoordinatorClientProtoApi(const CoordinatorClientProtoApi&) = delete;
		CoordinatorClientProtoApi& operator=(const CoordinatorClientProtoApi&) = delete;
	};
}

#endif