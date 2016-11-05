#ifndef FacialClientAdapted_INCLUDED
#define FacialClientAdapted_INCLUDED

#include <client_service_base.hpp>
#include <services/ifacial_service_api.hpp>
#include <facial_service/client/facial_client_api.hpp>
#include <helpers/request_adapters.hpp>

using grpc::ServerBuilder;

namespace services_api
{
	class FacialClientAdapted : public FacialClientApi
	                        	, public contracts::services::IFacialServiceApi
	{
	public:
		explicit FacialClientAdapted(contracts::services::IServiceAddress& address)
			: FacialClientApi(address)
		{}

		std::shared_ptr<data_model::BiometricResponse>
			process(const data_model::BiometricRequest& request) override
		{
			auto proto_request = helpers::to_proto_biometric_request(request);
			auto response      = FacialClientApi::process(proto_request);

			auto adapted = helpers::to_data_biometric_response(*response);
			return std::make_shared<data_model::BiometricResponse>(adapted);
		}


	private:
		FacialClientAdapted(const FacialClientAdapted&) = delete;
		FacialClientAdapted& operator=(const FacialClientAdapted&) = delete;
	};
}

#endif