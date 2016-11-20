#ifndef FileClientApi_INCLUDED
#define FileClientApi_INCLUDED

#include "abstract_client_service.hpp"
#include <services/file_service.grpc.pb.h>
#include <services/ifile_storage_api.hpp>


namespace services_api
{
	//TODO add try catch to calls
	class FileClientApi : public AbstractClientService
		                  , public contracts::services::IFileStorageApi
	{
	public:
		explicit FileClientApi(contracts::services::IServiceAddress& address);
	
		~FileClientApi();

		void init   () override;	
		void de_init() override;

		std::shared_ptr<std::string>
			get(const std::string& url) override;	

		std::string create(const std::string& data) override;

		bool delete_file(const std::string& url) override;		

		bool exists(const std::string& url) override;	

	private:
		std::string class_name() const override {
			return typeid(FileClientApi).name();
		}

		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::FileService::NewStub(channel);
		}

		std::unique_ptr<Services::FileService::Stub> stub_;

		FileClientApi(const FileClientApi&) = delete;
		FileClientApi& operator=(const FileClientApi&) = delete;
	};
}

#endif