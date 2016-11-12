#include "facial_service/client/facial_client_proto_api.hpp"

#include "abstract_client_service.hpp"
#include <service_utils.hpp>
#include "facial_service/client/facial_client_calls.hpp"

namespace services_api
{	
	FacialClientProtoApi::FacialClientProtoApi(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
	{
		FacialClientProtoApi::init();
	}

	FacialClientProtoApi::~FacialClientProtoApi() {
		FacialClientProtoApi::de_init();
	}

	void FacialClientProtoApi::init()
	{
		connect();

		add_call_handler<AsyncFaceProcessCall>();
	}

	void FacialClientProtoApi::de_init()  {
		stop();
	}

	std::shared_ptr<Services::BiometricResponse>
		FacialClientProtoApi::process(const Services::BiometricRequest& request)
	{
		auto queue = get_completion_queue<AsyncFaceProcessCall>();
		if (queue == nullptr)	return nullptr;

		auto call = new AsyncFaceProcessCall;
		set_call_options(call);
		call->reader = stub_->AsyncProcess(&call->context, request, queue);
		call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

		return utils::service::get_result(call->promise);
	}
}

