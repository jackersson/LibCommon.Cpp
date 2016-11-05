#ifndef LocationsDataContext_Included
#define LocationsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <vector>
#include <data/models/location.hpp>
#include <data/models/queries.hpp>
#include <helpers/request_adapters.hpp>
#include <common/logger.hpp>

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
			 return get(request.get_locations_request, entities);
			}

			bool add(const data_model::Location& entity) override
			{
				return false;
			}

		private:
			bool get( const data_model::GetLocationRequest& request
				      , std::vector<data_model::Location>& entities)
			{
				auto service_request = helpers::to_proto_get_request(request);
				try
				{					
					auto result = context_->get(service_request);
					parse(result, entities);
					return true;
				}
				catch (std::exception& exception)	{
					logger_.error(exception.what());
					return false;
				}				
			}

			void parse(std::shared_ptr<DataTypes::GetResponse> response
		          	, std::vector<data_model::Location>& entities) const
			{
				if (response == nullptr)
					return;			
				const auto& items = response->items().items();
				for (const auto& item : items)
				{
					if (item.value_type_case()
						!= DataTypes::Entity::ValueTypeCase::kLocation)
					{
						logger_.error("Wrong type in entities. Not location");
						continue;
					}
					entities.push_back(helpers::to_data_location(item.location()));
				}
			}
		
			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;

		};


	}
}

#endif
