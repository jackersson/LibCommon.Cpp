#ifndef PersonDataModel_INCLUDED
#define PersonDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{
	struct Person
	{
		Person() {}

		Key id        ;
		//std::string first_name;
		//std::string last_name ;
	};

	struct Card
	{
		Key id      ;
		Key owner_id;
	};


	struct Photo
	{
		Key           id;
		std::string   url;
	};
}

#endif