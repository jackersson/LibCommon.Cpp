#include "facial_service/client/facial_client_data_api.hpp"

#include <data/models/commands.hpp>

#include "helpers/request_adapters.hpp"


namespace services_api
{
	FacialClientDataApi::FacialClientDataApi(contracts::services::IServiceAddress& address)
		: FacialClientProtoApi(address)
	{}

	std::shared_ptr<data_model::BiometricResponse>
		FacialClientDataApi::process(const data_model::BiometricRequest& request)
	{
		auto proto_request = helpers::to_proto_biometric_request(request);
		auto response = FacialClientProtoApi::process(proto_request);

		auto adapted = helpers::to_data_biometric_response(*response);
		return std::make_shared<data_model::BiometricResponse>(adapted);
	}	
}
