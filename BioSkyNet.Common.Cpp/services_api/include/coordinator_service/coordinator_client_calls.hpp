#ifndef CoordinatorClientCall_INCLUDED
#define CoordinatorClientCall_INCLUDED

#include <helpers/service_heplers.hpp>

namespace services_api
{
	//TODO make interfaces 
	struct AsyncConnectCall       : AsyncEmptyCall {};
	struct AsyncHeartbeatCall     : AsyncEmptyCall {};
	struct AsyncUpdateDevicesCall : AsyncEmptyCall {};	
}

#endif