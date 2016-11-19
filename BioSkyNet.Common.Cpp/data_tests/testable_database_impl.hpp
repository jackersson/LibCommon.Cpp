#ifndef TestableDatabaseImpl_Included
#define TestableDatabaseImpl_Included

#include <services/service_address.hpp>
#include <database_service/database_client_data_api.hpp>
#include <repository_container.hpp>
#include <database_service/datacontext/datacontext_container.hpp>
#include <coordinator_service/coordinator_client_data_api.hpp>

namespace data_tests
{
	class TestableDatabaseImpl
	{
	public:
		explicit TestableDatabaseImpl(const std::string& address)	
		{		
			contracts::services::ServiceAddress database_address(address);
		
			impl_ 
				= std::make_unique<services_api::DatabaseClientDataApi>(database_address);
			impl_->start();

			datacontext_ 
				= std::make_unique<services_api::datacontext::DataContextContainer>(impl_.get());
			datacontext_->init();

			repositories_ 
				= std::make_unique<data_core::RepositoryContainer>(datacontext_.get());
			repositories_->init();
		}

		template <typename T>
		contracts::data::IRepository<T>* get(){
			return repositories_->get<T>();
		}

		void stop()	{
			impl_->stop();
		}

	private:
		std::unique_ptr<services_api::DatabaseClientDataApi> impl_;
		std::unique_ptr<contracts::data::AbstractDataContextContainer> datacontext_;
		std::unique_ptr<contracts::data::AbstractRepositoryContainer> repositories_;
	};

	class TestableDatabaseApi : public contracts::services::IDatabaseApi
	{

	public:
		std::shared_ptr<data_model::GetResponse>
			get(const data_model::GetRequest& request) override {
			return nullptr;
		}

		std::shared_ptr<data_model::CommitResponse>
			commit(const data_model::CommitRequest& request) override
		{
			return nullptr;
		}
	};

	class CoordinatorDatabaseImpl
	{
	public:
		explicit CoordinatorDatabaseImpl(const std::string& address)
		{
			contracts::services::ServiceAddress addr(address);

			impl_
				= std::make_unique<services_api::CoordinatorClientDataApi>(addr);
			impl_->start();

			datacontext_
				= std::make_unique<services_api::datacontext::DataContextContainer>(impl_.get());
			datacontext_->init();

			repositories_
				= std::make_unique<data_core::RepositoryContainer>(datacontext_.get());
			repositories_->init();
		}

		template <typename T>
		contracts::data::IRepository<T>* get() {
			return repositories_->get<T>();
		}

		void stop() {
			impl_->stop();
		}

	private:
		std::unique_ptr<services_api::CoordinatorClientDataApi> impl_;
		std::unique_ptr<contracts::data::AbstractDataContextContainer> datacontext_;
		std::unique_ptr<contracts::data::AbstractRepositoryContainer> repositories_;
	};
}

#endif
