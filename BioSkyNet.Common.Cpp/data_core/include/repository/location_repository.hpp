#ifndef LocationsRepository_Included
#define LocationsRepository_Included

#include <data/irepository.hpp>

namespace data_model {
	class Location;
}

namespace data_core
{
	namespace datacontext
	{
		class LocationsRepository
			: public contracts::data::IRepository<data_model::Location>
		{
		public:
			explicit
				LocationsRepository(IDataContext<data_model::Location>* datacontext);
			

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::Location>& entities) override;			
						
			bool add(const data_model::Location& entity) override;			

		private:
			IDataContext<data_model::Location>* datacontext_;
		};
	}
}

#endif
