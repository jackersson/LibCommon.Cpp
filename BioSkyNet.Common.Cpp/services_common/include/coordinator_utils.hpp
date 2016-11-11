#ifndef CoordinatorUtils_Included
#define CoordinatorUtils_Included

#include <services/icoordinator_api.hpp>
#include <string>

namespace data_model{
	enum ServiceType;	
}

namespace services
{
	namespace helpers
	{
		data_model::ConnectMsg 
			generate_connect_msg( uint16_t service_port 
			                    , const std::string& service_id
			                    , data_model::ServiceType service_type);


		data_model::HeartbeatMessage 
			generate_heartbeat_msg( const std::string& service_id
			                      , data_model::ServiceType  service_type );
	
	}
}

#endif