#ifndef PersonsDataContext_Included
#define PersonsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <logging/logger.hpp>

namespace data_model
{
	class Person;
}

namespace services_api
{
	namespace datacontext
	{
		class PersonsDataContext
			: public contracts::data::IDataContext<data_model::Person>
		{
		public:
			explicit PersonsDataContext(contracts::services::IDatabaseApi* api);
		
			bool get(const data_model::GetRequest& request
				, std::vector<data_model::Person>& entities) override;		

			bool add(const data_model::Person& entity) override;	

		private:
			bool do_get(const data_model::GetRequest& request
				, std::vector<data_model::Person>& entities) const;
		

			void parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::Person>& entities) const;
		
			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};		
	}
}

#endif
