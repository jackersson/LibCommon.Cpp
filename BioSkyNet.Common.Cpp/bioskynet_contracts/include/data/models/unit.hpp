#ifndef UnitDataModel_INCLUDED
#define UnitDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{	
	enum ServiceType
	{
	  	NoneServiceType
		, ClientService
		, UnitService
		, FacialService
	};

	struct HeartbeatMessage
	{
		Key         id;
		ServiceType type;
	};

	struct ConnectMsg
	{
		Key         id  ;
		ServiceType type;

		std::string ip_address;
	};
}

#endif