#ifndef VisitRecordsDataContext_Included
#define VisitRecordsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <logging/logger.hpp>

namespace data_model
{
	class VisitRecord;
}

namespace services_api
{
	namespace datacontext
	{
		class VisitRecordsDataContext
			: public contracts::data::IDataContext<data_model::VisitRecord>
		{
		public:
			explicit VisitRecordsDataContext(contracts::services::IDatabaseApi* api);
			
			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::VisitRecord>& entities) override;
			

			bool add(const data_model::VisitRecord& entity) override;
			
		private:
			bool do_get(const data_model::GetRequest& request
				, std::vector<data_model::VisitRecord>& entities) const;		

			void parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::VisitRecord>& entities) const;
			
			//TODO to utils, common for all 
			bool valid(std::shared_ptr<data_model::CommitResponse> response) const;
	
			mutable contracts::logging::Logger logger_;
			contracts::services::IDatabaseApi* context_;
		};
	}
}

#endif
