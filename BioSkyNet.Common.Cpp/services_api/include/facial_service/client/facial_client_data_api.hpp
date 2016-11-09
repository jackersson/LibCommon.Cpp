#ifndef FacialClientDataApi_INCLUDED
#define FacialClientDataApi_INCLUDED

#include <services/ifacial_service_api.hpp>
#include <helpers/request_adapters.hpp>
#include "facial_client_proto_api.hpp"

using grpc::ServerBuilder;

namespace services_api
{
	class FacialClientDataApi : public FacialClientProtoApi
	                        	, public contracts::services::IFacialServiceApi
	{
	public:
		explicit FacialClientDataApi(contracts::services::IServiceAddress& address)
			: FacialClientProtoApi(address)
		{}

		std::shared_ptr<data_model::BiometricResponse>
			process(const data_model::BiometricRequest& request) override
		{
			auto proto_request = helpers::to_proto_biometric_request(request);
			auto response      = FacialClientProtoApi::process(proto_request);

			auto adapted = helpers::to_data_biometric_response(*response);
			return std::make_shared<data_model::BiometricResponse>(adapted);
		}
		
	private:
		FacialClientDataApi(const FacialClientDataApi&) = delete;
		FacialClientDataApi& operator=(const FacialClientDataApi&) = delete;
	};
}

#endif