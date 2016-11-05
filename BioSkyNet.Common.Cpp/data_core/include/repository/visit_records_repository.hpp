#ifndef VisitRecordsRepository_Included
#define VisitRecordsRepository_Included

#include <data/irepository.hpp>
#include <data/models/visit_record.hpp>

namespace data_core
{
	namespace datacontext
	{
		class VisitRecordsRepository
			: public contracts::data::IRepository<data_model::VisitRecord>
		{
		public:
			explicit
				VisitRecordsRepository(IDataContext<data_model::VisitRecord>* datacontext)
				: datacontext_(datacontext)
			{
				if (datacontext_ == nullptr)
					throw std::exception("Datacontext can't be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::VisitRecord>& entities) override
			{
				return datacontext_->get(request, entities);
			}			

			bool add(const data_model::VisitRecord& entity) override
			{
				return datacontext_->add(entity);
			}
			
		private:
			IDataContext<data_model::VisitRecord>* datacontext_;
		};


	}
}

#endif
