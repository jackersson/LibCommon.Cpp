#ifndef FaceCharstDataContext_Included
#define FaceCharstDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <vector>
#include <data/models/face_characteristics.hpp>
#include <helpers/request_adapters.hpp>
#include <logging/logger.hpp>

namespace services_api
{
	namespace datacontext
	{
		class FaceCharstDataContext
			: public contracts::data::IDataContext<data_model::FaceTemplate>
		{

		public:
			explicit FaceCharstDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::FaceTemplate>& entities) override
			{			
				return do_get(request, entities);
			}

			bool add(const data_model::FaceTemplate& entity) override
			{
				throw std::exception("Not implemented");
			}

		private:
			bool do_get( const data_model::GetRequest& request
				         , std::vector<data_model::FaceTemplate>& entities) const
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
				        , std::vector<data_model::FaceTemplate>& entities) const
			{
				if (response == nullptr)
					return;
				for (const auto& item : *response)
				{
					if (item.type() == data_model::EntityFaceCharacteristics)
						entities.push_back(helpers::to_data_face_template(item.face()));
					else
						logger_.error("Get Response Error : Entity not contain face");
				}
			}

			contracts::services::IDatabaseApi* context_;
			mutable contracts::logging::Logger logger_ ;
		};
	}
}

#endif
