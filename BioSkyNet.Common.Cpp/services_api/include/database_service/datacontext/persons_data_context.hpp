#ifndef PersonsDataContext_Included
#define PersonsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <data/models/person.hpp>
#include <helpers/request_adapters.hpp>
#include <common/logger.hpp>

namespace services_api
{
	namespace datacontext
	{
		class PersonsDataContext
			: public contracts::data::IDataContext<data_model::Person>
		{
		public:
			explicit PersonsDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::Person>& entities) override
			{	
				return get(request.get_person_request, entities);
			}

			bool add(const data_model::Person& entity) override
			{
				throw std::exception("Not implemented");
			}

		private:
			bool get( const data_model::GetPersonRequest& request
			      	, std::vector<data_model::Person>& entities) const
			{			
				auto service_request = helpers::to_proto_get_request(request);
				try
				{
					auto result = context_->get(service_request);
					parse(result, entities);
					return true;
				}
				catch (std::exception& exception) {
					logger_.error(exception.what());
					return false;
				}
			}

			void parse(std::shared_ptr<DataTypes::GetResponse> response
				, std::vector<data_model::Person>& entities) const
			{
				if (response == nullptr)
					return;
				const auto& items = response->items().items();
				for (const auto& item : items)
				{
					if (item.value_type_case()
						!= DataTypes::Entity::ValueTypeCase::kPerson)
					{
						logger_.error("Wrong type in entities. Not location");
						continue;
					}
					entities.push_back(helpers::to_data_person(item.person()));
				}
			}		

			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};		
	}
}

#endif
