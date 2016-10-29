#ifndef IFileStorageApi_INCLUDED
#define IFileStorageApi_INCLUDED

#include <memory>
#include <services/file_service.pb.h>

namespace contracts
{
	namespace services
	{
		class IFileStorageApi
		{
		public:
			virtual ~IFileStorageApi() {}

			virtual std::shared_ptr<Services::FileBytes>
				get(const Services::FileMessage& request) = 0;
			

			virtual	std::shared_ptr<Services::FileMessage>
				create(const Services::FileBytes& request) = 0;

			virtual	bool delete_file(const Services::FileMessage& request) = 0;
			virtual bool exists     (const Services::FileMessage& request) = 0;
	
		};
	}
}

#endif
