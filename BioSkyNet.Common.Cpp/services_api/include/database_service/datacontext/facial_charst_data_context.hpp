#ifndef FaceCharstDataContext_Included
#define FaceCharstDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <vector>
#include <logging/logger.hpp>

namespace data_model
{
	class FaceTemplate;
}

namespace services_api
{
	namespace datacontext
	{
		class FaceCharstDataContext
			: public contracts::data::IDataContext<data_model::FaceTemplate>
		{

		public:
			explicit FaceCharstDataContext(contracts::services::IDatabaseApi* api);
		
			bool get(const data_model::GetRequest& request
				, std::vector<data_model::FaceTemplate>& entities) override;
		
			bool add(const data_model::FaceTemplate& entity) override;		

		private:
			bool do_get(const data_model::GetRequest& request
				, std::vector<data_model::FaceTemplate>& entities) const;
			
			void parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::FaceTemplate>& entities) const;
		
			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};
	}
}

#endif
