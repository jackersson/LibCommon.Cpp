#ifndef DatabaseClientAdapted_INCLUDED
#define DatabaseClientAdapted_INCLUDED

#include "database_service/database_client_calls.hpp"
#include <services/idatabase_api.hpp>
#include <services/service_address.hpp>
#include <helpers/request_adapters.hpp>
#include "database_client_proto_api.hpp"

namespace services_api
{
	class DatabaseClientDataApi : public DatabaseClientProtoApi
		                          , public contracts::services::IDatabaseApi
	{
	public:
		explicit DatabaseClientDataApi(contracts::services::IServiceAddress& address)
			: DatabaseClientProtoApi(address)
		{}
		
		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override
		{
			auto proto_request = helpers::to_proto_get_request(request);
			auto result        = DatabaseClientProtoApi::get(proto_request);

			auto adapted = helpers::to_data_get_response(*result);
			return std::make_shared<data_model::GetResponse>(adapted);
		}

		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override
		{
			auto proto_request = helpers::to_proto_commit_request(request);
			auto result  = DatabaseClientProtoApi::commit(proto_request);

			auto adapted = helpers::to_data_commit_response(*result);
			return std::make_shared<data_model::CommitResponse>(adapted);
		}

	private:		
		DatabaseClientDataApi(const DatabaseClientDataApi&) = delete;
		DatabaseClientDataApi& operator=(const DatabaseClientDataApi&) = delete;
	};
}

#endif