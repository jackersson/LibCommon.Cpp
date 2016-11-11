#ifndef PersonDataModel_INCLUDED
#define PersonDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{
	class Person
	{
	public:
		Person() {}

		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		}

		void set_first_name(const std::string& val) {
			first_name_ = val;
		}

		const std::string& first_name() const {
			return first_name_;
		}


		void set_last_name(const std::string& val) {
			last_name_ = val;
		}

		const std::string& last_name() const {
			return last_name_;
		}

	private:
		Key id_;
		std::string first_name_;
		std::string last_name_ ;
	};	
}

#endif