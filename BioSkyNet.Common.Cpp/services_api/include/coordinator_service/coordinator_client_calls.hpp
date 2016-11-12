#ifndef CoordinatorClientCall_INCLUDED
#define CoordinatorClientCall_INCLUDED

#include "helpers/abstract_async_call.hpp"

namespace services_api
{ 
	struct AsyncConnectCall       : AsyncEmptyCall
	{
		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncConnectCall).name();
			return class_name;
		}
	};

	struct AsyncHeartbeatCall     : AsyncEmptyCall
	{
		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncHeartbeatCall).name();
			return class_name;
		}
	};

	struct AsyncUpdateDevicesCall : AsyncEmptyCall
	{
		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncUpdateDevicesCall).name();
			return class_name;
		}
	};	
}

#endif