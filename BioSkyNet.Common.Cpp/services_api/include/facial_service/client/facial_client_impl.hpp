#ifndef FacialClientImpl_INCLUDED
#define FacialClientImpl_INCLUDED

#include <grpc++/grpc++.h>
#include <client_service_base.hpp>
#include <services/facial_service.grpc.pb.h>
#include "facial_client_calls.hpp"
#include <service_utils.hpp>
#include <services/ifacial_service_api.hpp>

using grpc::ServerBuilder;

namespace services_api
{
	class FacialClientImpl : public AbstractClientService	
		                     , public contracts::services::IFacialServiceApi
	{
	public:
		explicit FacialClientImpl(contracts::services::IServiceAddress& address)
			                       : AbstractClientService(address)
		{		
			FacialClientImpl::init();
		}

		~FacialClientImpl()	{
			FacialClientImpl::de_init();
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
			process(const Services::BiometricRequest& request) override
		{
			auto queue = get_completion_queue<AsyncFaceProcessCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncFaceProcessCall;
			do_set_call_options(call);
			set_call_options(call);
			call->reader = stub_->AsyncProcess(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}
			
		
	private:		
		std::string class_name() const override {
			return typeid(FacialClientImpl).name();
		}

		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::BiometricFacialService::NewStub(channel);
		}

		std::unique_ptr<Services::BiometricFacialService::Stub> stub_;

		FacialClientImpl(const FacialClientImpl&) = delete;
		FacialClientImpl& operator=(const FacialClientImpl&) = delete;
	};
}

#endif