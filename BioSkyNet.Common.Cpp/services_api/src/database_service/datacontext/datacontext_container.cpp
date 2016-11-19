#include "database_service/datacontext/datacontext_container.hpp"

#include <any.hpp>
#include <data/models/face_characteristics.hpp>
#include <data/models/location.hpp>
#include <data/models/visit_record.hpp>
#include <data/models/person.hpp>

#include "database_service/datacontext/facial_charst_data_context.hpp"
#include "database_service/datacontext/locations_data_context.hpp"
#include "database_service/datacontext/persons_data_context.hpp"
#include "database_service/datacontext/visit_records_datacontext.hpp"

using namespace data_model;
using namespace contracts::services;

namespace services_api
{
	namespace datacontext
	{
		DataContextContainer::DataContextContainer(IDatabaseApi* api)
				: api_(api)
		{
			if (api == nullptr)
				throw std::exception("IDatabase Api can't be null");

			DataContextContainer::init();
		}

		void DataContextContainer::init()
		{
			locations_ = std::make_unique<LocationsDataContext>(api_);
			container_[typeid(Location).hash_code()] = locations_.get();

			visit_records_ = std::make_unique<VisitRecordsDataContext>(api_);
			container_[typeid(VisitRecord).hash_code()] = visit_records_.get();

			persons_ = std::make_unique<PersonsDataContext>(api_);
			container_[typeid(Person).hash_code()] = persons_.get();

			face_templates_ = std::make_unique<FaceCharstDataContext>(api_);
			container_[typeid(FaceTemplate).hash_code()] = face_templates_.get();
		}

		void DataContextContainer::de_init()
		{
			container_.clear();
		}
	}
}


