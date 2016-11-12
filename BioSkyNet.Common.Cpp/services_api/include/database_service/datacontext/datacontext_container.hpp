#ifndef DataContextContainer_Included
#define DataContextContainer_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>

namespace data_model
{
	class Location    ;
	class VisitRecord ;
	class Person      ;
	class FaceTemplate;
}

namespace services_api
{
	namespace datacontext
	{		
		class DataContextContainer : public contracts::data::AbstractDataContextContainer
		{
		public:
			explicit DataContextContainer(contracts::services::IDatabaseApi* api);
			
			void init   () override;			
			void de_init() override;			

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
