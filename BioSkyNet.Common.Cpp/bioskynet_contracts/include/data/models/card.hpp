#ifndef CardDataModel_INCLUDED
#define CardDataModel_INCLUDED

#include "key.hpp"

namespace data_model
{	
	class Card
	{
	public:
		Card() {}
		explicit Card(const Key& val) : id_(val) {}

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
		Key id_;
		Key owner_id_;
	};
}

#endif