#ifndef LocationsDataContext_Included
#define LocationsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <vector>
#include <data/models/location.hpp>
#include <data/models/queries.hpp>
#include <logging/logger.hpp>

namespace services_api
{
	namespace datacontext
	{
		class LocationsDataContext 
			: public contracts::data::IDataContext<data_model::Location>
		{
			
		public:
			explicit LocationsDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::Location>& entities) override
			{			
			 return do_get(request, entities);
			}

			bool add(const data_model::Location& entity) override
			{
				return false;
			}

		private:
			bool do_get( const data_model::GetRequest& request
				      , std::vector<data_model::Location>& entities)
			{
				try
				{					
					auto result = context_->get(request);
					parse(result, entities);
					return true;
				}
				catch (std::exception& exception)	{
					logger_.error(exception.what());
					return false;
				}				
			}

			void parse(std::shared_ptr<data_model::GetResponse> response
		          	, std::vector<data_model::Location>& entities) const
			{
				if (response == nullptr)
					return;			
				for (const auto& item : *response)
				{
					if (item.type() == data_model::EntityLocation)
						entities.push_back(item.location());
					else
						logger_.error("Get Response Error : Entity not contain location");
				}
			}
		
			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;

		};


	}
}

#endif
