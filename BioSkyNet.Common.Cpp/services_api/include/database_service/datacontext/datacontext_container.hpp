#ifndef DataContextContainer_Included
#define DataContextContainer_Included

#include <data/irepository.hpp>
#include <any.hpp>
#include <services/idatabase_api.hpp>
#include "locations_data_context.hpp"
#include "visit_records_datacontext.hpp"
#include "persons_data_context.hpp"
#include <data/models/face_characteristics.hpp>
#include "facial_charst_data_context.hpp"

namespace services_api
{
	namespace datacontext
	{		
		class DataContextContainer : public contracts::data::AbstractDataContextContainer
		{
		public:
			explicit DataContextContainer(contracts::services::IDatabaseApi* api)
				: api_(api)
			{}

			void init() override
			{
				locations_ = std::make_unique<LocationsDataContext>(api_);
				container_[typeid(data_model::Location).hash_code()] = locations_.get();

				visit_records_ = std::make_unique<VisitRecordsDataContext>(api_);
				container_[typeid(data_model::VisitRecord).hash_code()] = visit_records_.get();

				persons_ = std::make_unique<PersonsDataContext>(api_);
				container_[typeid(data_model::Person).hash_code()] = persons_.get();

				face_templates_ = std::make_unique<FaceCharstDataContext>(api_);
				container_[typeid(data_model::FaceTemplate).hash_code()] = face_templates_.get();
			}

			void de_init() override
			{}

		private:
			contracts::services::IDatabaseApi* api_;
			std::unique_ptr<
				contracts::data::IDataContext<data_model::Location>> locations_;
			std::unique_ptr<
				contracts::data::IDataContext<data_model::VisitRecord>> visit_records_;
			std::unique_ptr<
				contracts::data::IDataContext<data_model::Person>> persons_;
			std::unique_ptr<
				contracts::data::IDataContext<data_model::FaceTemplate>> face_templates_;
		};
	}
}

#endif
