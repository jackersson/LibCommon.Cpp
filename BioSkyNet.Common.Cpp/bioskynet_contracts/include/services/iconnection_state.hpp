#ifndef IConnectionState_Included
#define IConnectionState_Included

namespace contracts
{
	namespace services
	{
		class IConnectionState
		{
		public:
			virtual ~IConnectionState() {}

			virtual bool connected() const = 0;
		};
	}
}

#endif