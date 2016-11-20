#include "database_service/datacontext/facial_charst_data_context.hpp"

#include <data/models/face_characteristics.hpp>
#include <data/models/entity.hpp>
#include <data/models/queries.hpp>
#include <logging/logger.hpp>

namespace services_api
{
	namespace datacontext
	{		
		FaceCharstDataContext::FaceCharstDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool FaceCharstDataContext::get(const data_model::GetRequest& request
				, std::vector<data_model::FaceTemplate>& entities)
			{
				return do_get(request, entities);
			}

			bool FaceCharstDataContext::add(const data_model::FaceTemplate& entity)
			{
				throw std::exception("Not implemented");
			}

			bool FaceCharstDataContext::do_get( const data_model::GetRequest& request
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

			void FaceCharstDataContext::parse
			(  std::shared_ptr<data_model::GetResponse> response
			,  std::vector<data_model::FaceTemplate>& entities) const
			{
				if (response == nullptr)
					return;
				for (const auto& item : *response)
				{					
					if (item.type() == data_model::EntityFaceCharacteristics)
					{
						const auto& face = item.face();
						entities.push_back(data_model::FaceTemplate( face.person_id()
							                                         , face.fir()));
					}
					else
						logger_.error("Get Response Error : Entity not contain face");
				}
			}		
	}
}
