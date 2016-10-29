#ifndef IFacialServiceApi_INCLUDED
#define IFacialServiceApi_INCLUDED

#include <memory>
#include <services/facial_service.pb.h>

namespace contracts
{
	namespace services
	{
		class IFacialServiceApi
		{
		public:
			virtual ~IFacialServiceApi() {}

			virtual std::shared_ptr<Services::BiometricResponse>
				process(const Services::BiometricRequest& request) = 0;
		};
	}
}

#endif
