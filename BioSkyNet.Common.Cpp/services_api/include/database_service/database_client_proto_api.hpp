#ifndef DatabaseClientProtoApi_INCLUDED
#define DatabaseClientProtoApi_INCLUDED

#include <services/database_service.grpc.pb.h>
#include <services/service_address.hpp>
#include "abstract_client_service.hpp"

namespace DataTypes
{
	class GetRequest    ;
	class GetResponse   ;
	class CommitResponse;
	class CommitRequest ;
}

namespace services_api
{
	class DatabaseClientProtoApi : public AbstractClientService		                       
	{
	public:
		explicit DatabaseClientProtoApi(contracts::services::IServiceAddress& address);
		
		virtual ~DatabaseClientProtoApi();

		void init   () override;
		void de_init() override;
		
		std::shared_ptr<DataTypes::GetResponse>
			get(const DataTypes::GetRequest& request);
	
		std::shared_ptr<DataTypes::CommitResponse>
			commit(const DataTypes::CommitRequest& request);
		
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