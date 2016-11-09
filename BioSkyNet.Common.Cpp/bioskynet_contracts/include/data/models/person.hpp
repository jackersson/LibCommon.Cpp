#ifndef PersonDataModel_INCLUDED
#define PersonDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{
	struct Person
	{
		Person() {}

		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		}

	private:
		Key id_;
		//std::string first_name;
		//std::string last_name ;
	};

	class Card
	{
	public:
		void set_owner_id(const Key& val) {
			owner_id_ = val;
		}

		const Key& owner_id() const {
			return owner_id_;
		}

		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		} 

	private:
		Key id_      ;
		Key owner_id_;
	};


	struct Photo
	{
		Key           id;
		std::string   url;
	};
}

#endif