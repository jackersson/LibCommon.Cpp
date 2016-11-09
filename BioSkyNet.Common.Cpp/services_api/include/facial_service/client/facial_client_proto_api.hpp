#ifndef FacialClientProtoApi_INCLUDED
#define FacialClientProtoApi_INCLUDED

#include <abstract_client_service.hpp>
#include <services/facial_service.grpc.pb.h>
#include "facial_client_calls.hpp"
#include <service_utils.hpp>

namespace services_api
{
	class FacialClientProtoApi : public AbstractClientService			                    
	{
	public:
		explicit 
			FacialClientProtoApi( contracts::services::IServiceAddress& address)
			                    : AbstractClientService(address)
		{		
			FacialClientProtoApi::init();
		}

		~FacialClientProtoApi()	{
			FacialClientProtoApi::de_init();
		}

		void init() override
		{
			connect();

			add_call_handler<AsyncFaceProcessCall>();
		}

		void de_init() override	{
			stop();
		}

		std::shared_ptr<Services::BiometricResponse>
			process(const Services::BiometricRequest& request)
		{
			auto queue = get_completion_queue<AsyncFaceProcessCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncFaceProcessCall;
			set_call_options(call);
			call->reader = stub_->AsyncProcess(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}
			
		
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