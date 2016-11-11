#ifndef PhotoDataModel_INCLUDED
#define PhotoDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{
	class Photo
	{
	public:
		Key           id;
		std::string   url;
	};
}

#endif