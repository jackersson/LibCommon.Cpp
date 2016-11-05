#ifndef DatabaseClientAdapted_INCLUDED
#define DatabaseClientAdapted_INCLUDED

#include "database_service/database_client_calls.hpp"
#include <services/idatabase_api.hpp>
#include <services/service_address.hpp>
#include <helpers/request_adapters.hpp>
#include "database_client_api.hpp"

namespace services_api
{
	class DatabaseClientAdapted : public DatabaseClientApi
		                          , public contracts::services::IDatabaseApi
	{
	public:
		explicit DatabaseClientAdapted(contracts::services::IServiceAddress& address)
			: DatabaseClientApi(address)
		{}
		
		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override
		{
			auto proto_request = helpers::to_proto_get_request(request);
			auto result        = DatabaseClientApi::get(proto_request);

			auto adapted = helpers::to_data_get_response(*result);
			return std::make_shared<data_model::GetResponse>(adapted);
		}

		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override
		{
			auto proto_request = helpers::to_proto_commit_request(request);
			auto result  = DatabaseClientApi::commit(proto_request);

			auto adapted = helpers::to_data_commit_response(*result);
			return std::make_shared<data_model::CommitResponse>(adapted);
		}

	private:		
		DatabaseClientAdapted(const DatabaseClientAdapted&) = delete;
		DatabaseClientAdapted& operator=(const DatabaseClientAdapted&) = delete;
	};
}

#endif