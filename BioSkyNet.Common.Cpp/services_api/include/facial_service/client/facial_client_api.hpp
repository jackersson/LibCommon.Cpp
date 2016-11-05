#ifndef FacialClientApi_INCLUDED
#define FacialClientApi_INCLUDED

#include <client_service_base.hpp>
#include <services/facial_service.grpc.pb.h>
#include "facial_client_calls.hpp"
#include <service_utils.hpp>

namespace services_api
{
	class FacialClientApi : public AbstractClientService			                    
	{
	public:
		explicit FacialClientApi(contracts::services::IServiceAddress& address)
			                       : AbstractClientService(address)
		{		
			FacialClientApi::init();
		}

		~FacialClientApi()	{
			FacialClientApi::de_init();
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
			return typeid(FacialClientApi).name();
		}

		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::BiometricFacialService::NewStub(channel);
		}

		std::unique_ptr<Services::BiometricFacialService::Stub> stub_;

		FacialClientApi(const FacialClientApi&) = delete;
		FacialClientApi& operator=(const FacialClientApi&) = delete;
	};
}

#endif