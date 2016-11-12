#ifndef DatabaseClientAdapted_INCLUDED
#define DatabaseClientAdapted_INCLUDED

#include <services/idatabase_api.hpp>
#include <services/service_address.hpp>
#include "database_client_proto_api.hpp"

namespace services_api
{
	class DatabaseClientDataApi : public DatabaseClientProtoApi
		                          , public contracts::services::IDatabaseApi
	{
	public:
		explicit DatabaseClientDataApi(contracts::services::IServiceAddress& address);
		
		virtual ~DatabaseClientDataApi();
		
		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override;
	

		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override;
		
	private:		
		DatabaseClientDataApi(const DatabaseClientDataApi&) = delete;
		DatabaseClientDataApi& operator=(const DatabaseClientDataApi&) = delete;
	};
}

#endif