#include <data/irepository.hpp>
#include <data/models/location.hpp>
#include <repository/location_repository.hpp>

namespace data_core
{
	namespace datacontext
	{			
		LocationsRepository::LocationsRepository(IDataContext<data_model::Location>* datacontext)
			: datacontext_(datacontext)
		{
			if (datacontext_ == nullptr)
				throw std::exception("Datacontext can't be null");
		}

		bool LocationsRepository::get(const data_model::GetRequest& request
			, std::vector<data_model::Location>& entities) 
		{
			return datacontext_->get(request, entities);
		}

		bool LocationsRepository::add(const data_model::Location& entity) {
			return datacontext_->add(entity);
		}
	}
}

