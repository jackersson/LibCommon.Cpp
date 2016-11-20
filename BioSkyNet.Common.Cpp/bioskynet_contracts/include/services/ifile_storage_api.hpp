#ifndef IFileStorageApi_INCLUDED
#define IFileStorageApi_INCLUDED

#include <memory>
#include <string>

namespace contracts
{
	namespace services
	{
		class IFileStorageApi
		{
		public:
			virtual ~IFileStorageApi() {}

			virtual std::shared_ptr<std::string>
				get(const std::string& url) = 0;			

			virtual	std::string	create(const std::string& data) = 0;

			virtual	bool delete_file(const std::string& url) = 0;
			virtual bool exists     (const std::string& url) = 0;
	
		};
		typedef std::shared_ptr<IFileStorageApi> IFileStorageApiPtr;

	}
}

#endif
