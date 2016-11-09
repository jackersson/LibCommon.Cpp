#ifndef IFileIO_Included
#define IFileIO_Included
#include <string>

namespace contracts
{
	namespace common
	{
		class IFileIO
		{
		public:
			virtual ~IFileIO() {}

			virtual bool save(const std::string &filename) const = 0;
			virtual bool load(const std::string &filename) = 0;
		};
	}
}

#endif