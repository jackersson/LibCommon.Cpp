#ifndef VisitRecordsDataContext_Included
#define VisitRecordsDataContext_Included

#include <data/irepository.hpp>
#include <services/idatabase_api.hpp>
#include <logging/logger.hpp>
#include <data/models/visit_record.hpp>
#include <helpers/request_adapters.hpp>

namespace services_api
{
	namespace datacontext
	{
		class VisitRecordsDataContext
			: public contracts::data::IDataContext<data_model::VisitRecord>
		{
		public:
			explicit VisitRecordsDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::VisitRecord>& entities) override
			{				
				return get(request, entities);
			}

			bool add(const data_model::VisitRecord& entity) override
			{
				auto service_entity = helpers::to_proto_entity(entity);
				auto request        = helpers::to_commit_insert(service_entity);
				
				auto result = context_->commit(request);
				
				return valid(result, DataTypes::Entity::ValueTypeCase::kVisitRecord);
			}

		private:
			bool get( const data_model::GetVisitRecordRequest& request
				       , std::vector<data_model::VisitRecord>& entities) const
			{				
				auto service_request = helpers::to_proto_get_request(request);
				try
				{
					auto result = context_->get(service_request);
					parse(result, entities);
					return true;
				}
				catch (std::exception& exception) {
					logger_.error(exception.what());
					return false;
				}
			}

			void parse(std::shared_ptr<DataTypes::GetResponse> response
				, std::vector<data_model::VisitRecord>& entities) const
			{
				if (response == nullptr)
					return;
				const auto& items = response->items().items();
				for (const auto& item : items)
				{
					if (item.value_type_case()
						!= DataTypes::Entity::ValueTypeCase::kVisitRecord)
					{
						logger_.error("Wrong type in entities. Not location");
						continue;
					}
					entities.push_back(helpers::to_visit_record(item.visit_record()));
				}
			}

		
			//TODO to utils, common for all 
			bool valid( std::shared_ptr<DataTypes::CommitResponse> response
			          , DataTypes::Entity::ValueTypeCase target_type) const
			{
				if (response == nullptr)
					return false;
				const auto& mutations = response->mutation_results();
				for (const auto& item : mutations)
				{
					const auto& error_message = item.error();
					if (error_message != "")
					{
						logger_.error("Mutation error {0}", error_message);
						continue;
					}
					const auto& entity = item.entity();
					if (entity.value_type_case() != target_type)
						logger_.error("Mutation error. Type mismatch {0} != "
						            	, entity.value_type_case(), target_type );
				}
				return mutations.size() > 0;
			}

			mutable contracts::logging::Logger logger_;
			contracts::services::IDatabaseApi* context_;
		};
	}
}

#endif
