#ifndef PersonsDataContext_Included
#define PersonsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <data/models/person.hpp>
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
				return do_get(request, entities);
			}

			bool add(const data_model::Person& entity) override
			{
				throw std::exception("Not implemented");
			}

		private:
			bool do_get( const data_model::GetRequest& request
			      	   , std::vector<data_model::Person>& entities) const
			{			
				try
				{
					auto result = context_->get(request);
					parse(result, entities);
					return true;
				}
				catch (std::exception& exception) {
					logger_.error(exception.what());
					return false;
				}
			}

			void parse( std::shared_ptr<data_model::GetResponse> response
				        , std::vector<data_model::Person>& entities) const
			{
				if (response == nullptr)
					return;
				const auto& items = response->entities;
				for (const auto& item : items)									
					entities.push_back(item.person);				
			}		

			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};		
	}
}

#endif
