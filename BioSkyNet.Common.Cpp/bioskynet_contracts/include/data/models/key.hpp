#ifndef KeyDataModel_INCLUDED
#define KeyDataModel_INCLUDED

#include <string>
#include <uuid/uuid.hpp>


namespace data_model
{	
	class Key
	{
	public:
		explicit Key() : numeric_(0)
		{}

		explicit Key(const boost::uuids::uuid& id) : uuid_(id)
			, numeric_(0)
		{}

		explicit Key(const std::string& id) : identifier_(id)
			, numeric_(0)
		{}

		explicit Key(long id) : numeric_(id) {}

		boost::uuids::uuid& guid() {
			return uuid_;
		}

		const boost::uuids::uuid& guid() const {
			return uuid_;
		}

		const std::string& identifier() const {
			return identifier_;
		}

		long numeric_id() const {
			return numeric_;
		}

	private:
		boost::uuids::uuid uuid_;
		std::string        identifier_;
		long               numeric_;

	};	
}

#endif