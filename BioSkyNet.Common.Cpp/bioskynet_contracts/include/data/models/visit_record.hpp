#ifndef VisitRecordDataModel_INCLUDED
#define VisitRecordDataModel_INCLUDED

#include "key.hpp"
#include "datetime.hpp"
#include "face_characteristics.hpp"
#include <data/data_utils.hpp>
#include "card.hpp"

namespace data_model
{

	enum AccessState
	{
		  NoneState
		, Granted
		, Denied
	};

	class VisitRecord
	{
	public:
		VisitRecord()		{
			set_id(contracts::data::get_random_data_key());
		}

		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		}

		void set_person_id(const Key& val) {
			person_id_ = val;
		}

		const Key& person_id() const {
			return person_id_;
		}

		void set_location_id(const Key& val) {
			location_id_ = val;
		}

		const Key& location_id() const {
			return location_id_;
		}

		void set_card(const Card& card){
			card_ = card;
		}

		const Card& card() const {
			return card_;
		}

		void set_time(const DateTime& val) {
			time_ = val;
		}

		void set_now() {
			time_ = DateTime::now();
		}

		const DateTime& time() const {
			return time_;
		}

		void set_face(const FaceCharacteristics& val) {
			face_ = val;
		}

		const FaceCharacteristics& face() const {
			return face_;
		}

		void set_access_state(AccessState val) {
			state_ = val;
		}

		AccessState access_state() const {
			return state_;
		}

	private:
		Key                 id_         ;
		Key                 person_id_  ;
		Key                 location_id_;
		Card                card_       ;
		DateTime            time_       ;
		FaceCharacteristics face_       ;
		AccessState         state_      ;		
	};


}

#endif