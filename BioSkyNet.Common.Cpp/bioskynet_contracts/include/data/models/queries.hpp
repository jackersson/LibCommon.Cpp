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

	class GetPersonRequest
	{
	public:
		void set_card(const Card& card) {
			card_ = card;
		}

		const Card& card() const {
			return card_;
		}

	private:
		Card card_;
	};

	struct GetVisitRecordRequest
	{
	};

	class GetRequest
	{
	public:
		explicit GetRequest(const GetPersonRequest& get_person_request)
			: get_person_request_(get_person_request, true)
		{}

		bool has_person_request() const	{
			return get_person_request_.second;
		}

		const GetPersonRequest& person_request() const{
			return get_person_request_.first;
		}

	private:
		std::pair<GetLocationRequest   , bool> get_locations_request_   ;
		std::pair<GetFaceCharRequest   , bool> get_face_char_request_   ;
		std::pair<GetPersonRequest     , bool> get_person_request_      ;
		std::pair<GetVisitRecordRequest, bool> get_visit_record_request_;
	};

	
	struct GetResponse
	{
		std::vector<Entity> entities;
		int count;
	};
}

#endif