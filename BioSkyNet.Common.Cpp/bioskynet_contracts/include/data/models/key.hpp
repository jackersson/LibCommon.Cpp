#ifndef KeyDataModel_INCLUDED
#define KeyDataModel_INCLUDED

#include <string>
#include <uuid/uuid.hpp>
#include <sstream>
#include <uuid/uuid_io.hpp>

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

		explicit Key(const std::string& id) : identifier_(id, true)
			                                  , number_(0 , false)
		{}

		explicit Key(long id) : number_(id, true) {}

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
			return !( ( uuid_.second     && !uuid_.first.is_nil()   )
				     || ( identifier_.second && identifier_.first != "" )
				     || ( number_.second     && number_.first > 0       ) );
		}

		std::string to_string() const
		{			
			if (uuid_.second)
				return boost::uuids::to_string(uuid_.first);
			if (identifier_.second)
				return identifier_.first;
			if (number_.second)
				return " " + number_.first;
			return "";
		}

		bool operator==(const Key& val) const
		{
			return   val.uuid_       == this->uuid_
				   &&  val.identifier_ == this->identifier_
				   &&  val.number_     == this->number_;
		}

		bool operator<(const Key& val) const
		{
			return  val.uuid_      .first < this->uuid_      .first
				  ||  val.identifier_.first < this->identifier_.first
				  ||  val.number_    .first < this->number_    .first;
		}

		bool operator>(const Key& val) const
		{
				return  val.uuid_      .first > this->uuid_      .first
				    ||  val.identifier_.first > this->identifier_.first
				    ||  val.number_    .first > this->number_    .first;
		}

		bool operator!=(const Key& val) const
		{
			return !(*this == val);
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