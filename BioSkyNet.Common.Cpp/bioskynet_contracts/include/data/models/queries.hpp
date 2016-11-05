#ifndef QueriesDataModel_INCLUDED
#define QueriesDataModel_INCLUDED

#include <string>
#include <vector>
#include "commands.hpp"

namespace data_model
{
	struct GetLocationRequest
	{
		std::string mac_address;
	};

	struct GetFaceCharRequest
	{		
	};

	struct GetPersonRequest
	{
		std::string card;
	};

	struct GetVisitRecordRequest
	{
	};

	struct GetRequest
	{
		GetLocationRequest    get_locations_request   ;
		GetFaceCharRequest    get_face_char_request   ;
		GetPersonRequest      get_person_request      ;
		GetVisitRecordRequest get_visit_record_request;
	};

	
	struct GetResponse
	{
		std::vector<Entity> entities;
		int count;
	};
}

#endif