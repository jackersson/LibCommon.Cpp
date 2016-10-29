#ifndef FileClientImpl_INCLUDED
#define FileClientImpl_INCLUDED

#include <grpc++/grpc++.h>
#include <client_service_base.hpp>
#include <services/file_service.grpc.pb.h>
#include "file_client_calls.hpp"
#include <service_utils.hpp>
#include <services/ifile_storage_api.hpp>

using grpc::ServerBuilder;

namespace services_api
{
	//TODO add try catch to calls
	class FileClientImpl : public AbstractClientService
		                   , public contracts::services::IFileStorageApi
	{
	public:
		explicit FileClientImpl(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
		{
			FileClientImpl::init();
		}

		~FileClientImpl() {
			FileClientImpl::de_init();
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

		std::shared_ptr<Services::FileBytes>
		  	get(const Services::FileMessage& request) override
		{
			auto queue = get_completion_queue<AsyncGetFileCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncGetFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncGet(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		std::shared_ptr<Services::FileMessage>
			create(const Services::FileBytes& request) override
		{
			auto queue = get_completion_queue<AsyncCreateFileCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncCreateFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncCreate(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		bool delete_file(const Services::FileMessage& request) override
		{
			auto queue = get_completion_queue<AsyncDeleteFileCall>();
			if (queue == nullptr)	return;

			auto call = new AsyncDeleteFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncDelete(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		bool exists(const Services::FileMessage& request) override
		{
			auto queue = get_completion_queue<AsyncExistsFileCall>();
			if (queue == nullptr)	return;

			auto call = new AsyncExistsFileCall;
			set_call_options(call);
			call->reader = stub_->AsyncExists(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

	private:
		std::string class_name() const override {
			return typeid(FileClientImpl).name();
		}

		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override {
			stub_ = Services::FileService::NewStub(channel);
		}

		std::unique_ptr<Services::FileService::Stub> stub_;

		FileClientImpl(const FileClientImpl&) = delete;
		FileClientImpl& operator=(const FileClientImpl&) = delete;
	};
}

#endif