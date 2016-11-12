#include "repository/persons_repository.hpp"

#include <data/models/person.hpp>

namespace data_core
{
	namespace datacontext
	{		
		PersonsRepository::PersonsRepository( IDataContext<data_model::Person>* datacontext)
				                                : datacontext_(datacontext)
		{
			if (datacontext_ == nullptr)
				throw std::exception("Datacontext can't be null");
		}

		bool PersonsRepository::get(const data_model::GetRequest& request
			, std::vector<data_model::Person>& entities) 
		{
			return datacontext_->get(request, entities);
		}

		bool PersonsRepository::add(const data_model::Person& entity)
		{
			return datacontext_->add(entity);
		}
	}
}