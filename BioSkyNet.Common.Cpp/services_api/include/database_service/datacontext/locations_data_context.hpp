#ifndef LocationsDataContext_Included
#define LocationsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <vector>
#include <logging/logger.hpp>

namespace data_model
{
	class Location;
}

namespace services_api
{
	namespace datacontext
	{
		class LocationsDataContext 
			: public contracts::data::IDataContext<data_model::Location>
		{			
		public:
			explicit LocationsDataContext(contracts::services::IDatabaseApi* api);
	
			bool get(const data_model::GetRequest& request
				, std::vector<data_model::Location>& entities) override;
		

			bool add(const data_model::Location& entity) override;			

		private:
			bool do_get(const data_model::GetRequest& request
				, std::vector<data_model::Location>& entities);

			void parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::Location>& entities) const;
			
			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};
	}
}

#endif
