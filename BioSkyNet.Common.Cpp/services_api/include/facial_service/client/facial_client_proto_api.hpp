#ifndef FacialClientProtoApi_INCLUDED
#define FacialClientProtoApi_INCLUDED

#include "abstract_client_service.hpp"
#include <services/facial_service.grpc.pb.h>

namespace services_api
{
	class FacialClientProtoApi : public AbstractClientService			                    
	{
	public:
		explicit
			FacialClientProtoApi(contracts::services::IServiceAddress& address);
	
		~FacialClientProtoApi();

		void init   () override;
		void de_init() override;

		std::shared_ptr<Services::BiometricResponse>
			process(const Services::BiometricRequest& request);
				
	private:		
		std::string class_name() const override {
			return typeid(FacialClientProtoApi).name();
		}

		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::BiometricFacialService::NewStub(channel);
		}

		std::unique_ptr<Services::BiometricFacialService::Stub> stub_;

		FacialClientProtoApi(const FacialClientProtoApi&) = delete;
		FacialClientProtoApi& operator=(const FacialClientProtoApi&) = delete;
	};
}

#endif