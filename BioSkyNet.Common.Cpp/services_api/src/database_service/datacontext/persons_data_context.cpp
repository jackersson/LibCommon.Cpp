#include "database_service/datacontext/persons_data_context.hpp"

#include <data/models/person.hpp>
#include <logging/logger.hpp>
#include <data/models/entity.hpp>
#include <data/models/queries.hpp>

namespace services_api
{
	namespace datacontext
	{
		PersonsDataContext::PersonsDataContext(contracts::services::IDatabaseApi* api)
				: context_(api)
			{
				if (context_ == nullptr)
					throw std::exception("Database Api cannot be null");
			}

			bool PersonsDataContext::get(const data_model::GetRequest& request
				, std::vector<data_model::Person>& entities)
			{
				return do_get(request, entities);
			}

			bool PersonsDataContext::add(const data_model::Person& entity)
			{
				throw std::exception("Not implemented");
			}

		
			bool PersonsDataContext::do_get(const data_model::GetRequest& request
				, std::vector<data_model::Person>& entities) const
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

			void PersonsDataContext::parse(std::shared_ptr<data_model::GetResponse> response
				, std::vector<data_model::Person>& entities) const
			{
				if (response == nullptr)
					return;
				for (const auto& item : *response)
				{
					if (item.type() == data_model::EntityPerson)
						entities.push_back(item.person());
					else
						logger_.error("Get Response Error : Entity not contain person");
				}
			}
	}
}

