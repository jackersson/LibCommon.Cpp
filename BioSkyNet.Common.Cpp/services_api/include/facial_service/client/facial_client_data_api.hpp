#ifndef FacialClientDataApi_INCLUDED
#define FacialClientDataApi_INCLUDED

#include <services/ifacial_service_api.hpp>
#include "facial_client_proto_api.hpp"

namespace services_api
{
	class FacialClientDataApi : public FacialClientProtoApi
	                        	, public contracts::services::IFacialServiceApi
	{
	public:
		explicit FacialClientDataApi(contracts::services::IServiceAddress& address);

		std::shared_ptr<data_model::BiometricResponse>
			process(const data_model::BiometricRequest& request) override;
	
	private:
		FacialClientDataApi(const FacialClientDataApi&) = delete;
		FacialClientDataApi& operator=(const FacialClientDataApi&) = delete;
	};
}

#endif