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
				auto request = helpers::to_data_commit_insert(entity);				
				auto result  = context_->commit(request);
				
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
				for (const auto& item : *response)
				{
					if (item.type() == data_model::EntityVisitRecord)
						entities.push_back(item.visit_record());
					else
						logger_.error("Get Response Error : Entity not contain visitrecord");
				}
			}

		
			//TODO to utils, common for all 
			bool valid( std::shared_ptr<data_model::CommitResponse> response ) const
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

			mutable contracts::logging::Logger logger_;
			contracts::services::IDatabaseApi* context_;
		};
	}
}

#endif
