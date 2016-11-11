#ifndef QueriesDataModel_INCLUDED
#define QueriesDataModel_INCLUDED

#include <vector>
#include "commands.hpp"
#include "card.hpp"

namespace data_model
{
	class GetLocationRequest
	{
	public:
		void set_macaddress(const std::string& val) {
			mac_address_ = val;
		}

		const std::string& mac_address() const {
			return mac_address_;
		}

		bool has_mac_address() const {
			return mac_address_ != "";
		}

	private:
		std::string mac_address_;
	};

	class GetFaceCharRequest
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

	class GetVisitRecordRequest
	{
	};

	class GetRequest
	{
	public:
		explicit GetRequest(const GetPersonRequest& get_person_request)
			: get_person_request_(get_person_request, true)
		{}

		explicit GetRequest(const GetLocationRequest& get_location_request)
			: get_locations_request_(get_location_request, true)
		{}

		bool has_person_request() const	{
			return get_person_request_.second;
		}

		const GetPersonRequest& person_request() const{
			return get_person_request_.first;
		}

		bool has_location_request() const {
			return get_locations_request_.second;
		}

		const GetLocationRequest& location_request() const {
			return get_locations_request_.first;
		}

	private:
		std::pair<GetLocationRequest   , bool> get_locations_request_   ;
		std::pair<GetFaceCharRequest   , bool> get_face_char_request_   ;
		std::pair<GetPersonRequest     , bool> get_person_request_      ;
		std::pair<GetVisitRecordRequest, bool> get_visit_record_request_;
	};

	
	class GetResponse
	{
	public:
		void add(const Entity& entity)
		{
			entities.push_back(entity);
		}

		std::vector<Entity>::const_iterator begin() const
		{
			return entities.cbegin();
		}

		std::vector<Entity>::const_iterator end() const
		{
			return entities.cend();
		}

		void clear() {
			entities.clear();
		}

	private:
		std::vector<Entity> entities;
	};
}

#endif