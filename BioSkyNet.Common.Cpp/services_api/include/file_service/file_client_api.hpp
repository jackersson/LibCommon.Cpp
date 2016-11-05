#ifndef FileClientImpl_INCLUDED
#define FileClientImpl_INCLUDED

#include <client_service_base.hpp>
#include <services/file_service.grpc.pb.h>
#include "file_client_calls.hpp"
#include <service_utils.hpp>
#include <services/ifile_storage_api.hpp>

namespace services_api
{
	//TODO add try catch to calls
	class FileClientApi : public AbstractClientService
		                   , public contracts::services::IFileStorageApi
	{
	public:
		explicit FileClientApi(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
		{
			FileClientApi::init();
		}

		~FileClientApi() {
			FileClientApi::de_init();
		}

		void init() override
		{
			connect();

			add_call_handler<AsyncGetFileCall   >();
			add_call_handler<AsyncCreateFileCall>();
			add_call_handler<AsyncDeleteFileCall>();
			add_call_handler<AsyncExistsFileCall>();
		}

		void de_init() override {
			stop();
		}

		std::shared_ptr<std::string>
		  	get(const std::string& url) override
		{			
			auto queue = get_completion_queue<AsyncGetFileCall>();
			if (queue == nullptr)	return nullptr;

			Services::FileMessage request;
			request.set_id(url);

			auto call = new AsyncGetFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncGet(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		std::string create(const char* data) override
		{
			auto queue = get_completion_queue<AsyncCreateFileCall>();
			if (queue == nullptr)	return nullptr;

			Services::FileBytes request;
			request.set_data(data);

			auto call = new AsyncCreateFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncCreate(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		bool delete_file(const std::string& url) override
		{
			auto queue = get_completion_queue<AsyncDeleteFileCall>();
			if (queue == nullptr)	return false;

			Services::FileMessage request;
			request.set_id(url);

			auto call = new AsyncDeleteFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncDelete(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		bool exists(const std::string& url) override
		{
			auto queue = get_completion_queue<AsyncExistsFileCall>();
			if (queue == nullptr)	return false;

			Services::FileMessage request;
			request.set_id(url);

			auto call = new AsyncExistsFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncExists(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

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