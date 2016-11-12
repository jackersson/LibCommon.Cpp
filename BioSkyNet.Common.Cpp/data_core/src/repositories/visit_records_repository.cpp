#include "repository/visit_records_repository.hpp"

#include <data/models/visit_record.hpp>

namespace data_core
{
	namespace datacontext
	{
		VisitRecordsRepository::VisitRecordsRepository(IDataContext<data_model::VisitRecord>* datacontext)
			: datacontext_(datacontext)
		{
			if (datacontext_ == nullptr)
				throw std::exception("Datacontext can't be null");
		}

		bool VisitRecordsRepository::get(const data_model::GetRequest& request
			, std::vector<data_model::VisitRecord>& entities) 
		{
			return datacontext_->get(request, entities);
		}

		bool VisitRecordsRepository::add(const data_model::VisitRecord& entity) 
		{
			return datacontext_->add(entity);
		}
	}
}

