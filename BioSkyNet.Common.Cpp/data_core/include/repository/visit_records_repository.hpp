#ifndef VisitRecordsRepository_Included
#define VisitRecordsRepository_Included

#include <data/irepository.hpp>

namespace data_model {
	class VisitRecord;
}

namespace data_core
{
	namespace datacontext
	{
		class VisitRecordsRepository
			: public contracts::data::IRepository<data_model::VisitRecord>
		{
		public:
			explicit
				VisitRecordsRepository(IDataContext<data_model::VisitRecord>* datacontext);
		
			bool get(const data_model::GetRequest& request
				, std::vector<data_model::VisitRecord>& entities) override;	

			bool add(const data_model::VisitRecord& entity) override;
						
		private:
			IDataContext<data_model::VisitRecord>* datacontext_;
		};		
	}
}

#endif
