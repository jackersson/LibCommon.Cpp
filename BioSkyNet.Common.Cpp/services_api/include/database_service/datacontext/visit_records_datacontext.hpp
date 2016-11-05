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
				auto request        = helpers::to_data_commit_insert(service_entity);
				
				auto result = context_->commit(request);
				
				return valid(result);
			}

		private:
			bool do_get( const data_model::GetRequest& request
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

			void parse( std::shared_ptr<data_model::GetResponse> response
				        , std::vector<data_model::VisitRecord>& entities   ) const
			{
				if (response == nullptr)
					return;
				const auto& items = response->entities;
				for (const auto& item : items)					
					entities.push_back(item.visit_record);				
			}

		
			//TODO to utils, common for all 
			bool valid( std::shared_ptr<data_model::CommitResponse> response ) const
			{
				if (response == nullptr)
					return false;
				const auto& mutations = response->mutations;
				for (const auto& item : mutations)
				{
					const auto& error_message = item.error;
					if (error_message != "")
					{
						logger_.error("Mutation error {0}", error_message);
						continue;
					}
					const auto& entity = item.entity;
					if (!entity.has_visit_record())
						logger_.error("Mutation error. Type mismatch");
				}
				return mutations.size() > 0;
			}

			mutable contracts::logging::Logger logger_;
			contracts::services::IDatabaseApi* context_;
		};
	}
}

#endif
