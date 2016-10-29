#ifndef IService_Included
#define IService_Included

#include <common/ilifecycle.hpp>

namespace contracts
{
	namespace services
	{
		class IService : public common::IModule
		               , public common::ILifecycle
		{
		public:
			virtual ~IService() {}
		};
	}
}

#endif
