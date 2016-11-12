#include "database_service/datacontext/visit_records_datacontext.hpp"


#include <logging/logger.hpp>
#include <data/models/visit_record.hpp>
#include <data/models/commands.hpp>
#include <data/models/queries.hpp>

#include "helpers/request_adapters.hpp"

namespace services_api
{
	namespace datacontext
	{
		  VisitRecordsDataContext::VisitRecordsDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool VisitRecordsDataContext::get(const data_model::GetRequest& request
				, std::vector<data_model::VisitRecord>& entities) 
			{
				return get(request, entities);
			}

			bool VisitRecordsDataContext::add(const data_model::VisitRecord& entity)
			{
				auto request = helpers::to_data_commit_insert(entity);
				auto result = context_->commit(request);

				return valid(result);
			}

			bool VisitRecordsDataContext::do_get(const data_model::GetRequest& request
				, std::vector<data_model::VisitRecord>& entities) const
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

			void VisitRecordsDataContext::parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::VisitRecord>& entities) const
			{
				if (response == nullptr)
					return;
				for (const auto& item : *response)
				{
					if (item.type() == data_model::EntityVisitRecord)
						entities.push_back(item.visit_record());
					else
						logger_.error("Get Response Error : Entity not contain visitrecord");
				}
			}


			//TODO to utils, common for all 
			bool VisitRecordsDataContext::valid(std::shared_ptr<data_model::CommitResponse> response) const
			{
				if (response == nullptr)
					return false;
				for (const auto& item : *response)
				{
					const auto& error_message = item.error();
					if (error_message != "")
					{
						logger_.error("Mutation error {0}", error_message);
						continue;
					}
					const auto& entity = item.id();
					if (item.id().is_empty())
						logger_.error("Mutation error. Id empty");
				}
				return response->size() > 0;
			}
	}
}
