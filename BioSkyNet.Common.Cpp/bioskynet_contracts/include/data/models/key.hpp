#ifndef KeyDataModel_INCLUDED
#define KeyDataModel_INCLUDED

#include <string>
#include <uuid/uuid.hpp>

namespace data_model
{	
	class Key
	{
	public:
		explicit Key() : number_(0, false)
		{}

		explicit Key(const boost::uuids::uuid& id) : uuid_   (id, true )
			                                         , number_(0 , false)
		{}

		explicit Key(const std::string& id) : identifier_(id, false)
			                                  , number_(0 , false)
		{}

		explicit Key(long id) : number_(id, false) {}

		bool has_guid() const {
			return uuid_.second;
		}

		bool has_identifier() const {
			return identifier_.second;
		}

		bool has_numeric_id() const {
			return number_.second;
		}
		
		const boost::uuids::uuid& guid() const {
			return uuid_.first;
		}

		const std::string& identifier() const {
			return identifier_.first;
		}

		long number() const {
			return number_.first;
		}

		bool is_empty() const	{
			return uuid_.second || identifier_.second || number_.second;
		}

		bool operator==(const Key& val) const
		{
			return   val.uuid_       == this->uuid_
				   &&  val.identifier_ == this->identifier_
				   &&  val.number_     == this->number_;
		}

		static const Key& empty()
		{
			static Key key;
			return key;
		}
	private:
		std::pair<boost::uuids::uuid, bool> uuid_      ;
		std::pair<std::string       , bool> identifier_;
		std::pair<long              , bool> number_    ;

	};	
}

#endif