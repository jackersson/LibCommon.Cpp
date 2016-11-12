#include "database_service/database_client_data_api.hpp"


#include "helpers/request_adapters.hpp"
#include <datatypes/queries.pb.h>
#include <data/models/queries.hpp>
#include <datatypes/commands.pb.h>

namespace services_api
{	
	DatabaseClientDataApi::DatabaseClientDataApi(contracts::services::IServiceAddress& address)
			: DatabaseClientProtoApi(address)
		{}

	DatabaseClientDataApi::~DatabaseClientDataApi() {}

	std::shared_ptr<data_model::GetResponse>
		DatabaseClientDataApi::get(const data_model::GetRequest& request)
	{
		auto proto_request = helpers::to_proto_get_request(request);
		auto result = DatabaseClientProtoApi::get(proto_request);

		if (result == nullptr)
			return nullptr;

		auto adapted = helpers::to_data_get_response(*result);
		return std::make_shared<data_model::GetResponse>(adapted);
	}

	std::shared_ptr<data_model::CommitResponse>
		DatabaseClientDataApi::commit(const data_model::CommitRequest& request)
	{
		auto proto_request = helpers::to_proto_commit_request(request);
		auto result = DatabaseClientProtoApi::commit(proto_request);

		if (result == nullptr)
			return nullptr;

		auto adapted = helpers::to_data_commit_response(*result);
		return std::make_shared<data_model::CommitResponse>(adapted);
	}
}
