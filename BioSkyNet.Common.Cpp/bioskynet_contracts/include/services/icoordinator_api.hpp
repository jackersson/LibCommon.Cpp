#ifndef ICoordinatorApi_INCLUDED
#define ICoordinatorApi_INCLUDED

#include <memory>

namespace data_model{
	class ConnectMsg;
	class HeartbeatMessage;
	class DeviceUpdate;
}

namespace contracts
{
	namespace services
	{
		class IHeartbeat
		{
		public:
			virtual ~IHeartbeat() {}

			virtual bool
				heart_beat(const data_model::HeartbeatMessage& request) const = 0;

		};

		class ICoordinatorApi : public IHeartbeat
		{
		public:
			virtual ~ICoordinatorApi() {}

			virtual bool 
				connect_request (const data_model::ConnectMsg& request) = 0;														     
		
			virtual void
				update_devices (const data_model::DeviceUpdate& request) const = 0;
		};
			
		typedef std::shared_ptr<ICoordinatorApi> ICoordinatorApiPtr;
	}
}

#endif
