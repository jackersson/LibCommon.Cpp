#ifndef IFacialServiceApi_INCLUDED
#define IFacialServiceApi_INCLUDED

#include <memory>

namespace data_model {
	class BiometricResponse;
	class BiometricRequest ;	
}

namespace contracts
{
	namespace services
	{
		class IFacialServiceApi
		{
		public:
			virtual ~IFacialServiceApi() {}

			virtual std::shared_ptr<data_model::BiometricResponse>
				process(const data_model::BiometricRequest& request) = 0;
		};

		typedef std::shared_ptr<IFacialServiceApi> IFacialServiceApiPtr;
	}
}

#endif
