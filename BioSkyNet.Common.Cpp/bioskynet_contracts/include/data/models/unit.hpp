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

	class HeartbeatMessage
	{
	public:
		Key         id;
		ServiceType type;
	};

	class ConnectMsg
	{
	public:
		Key         id  ;
		ServiceType type;

		std::string ip_address;
	};
}

#endif