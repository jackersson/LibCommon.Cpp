#include "file_service/file_client_api.hpp"

#include <service_utils.hpp>

#include "file_service/file_client_calls.hpp"
#include "abstract_client_service.hpp"

namespace services_api
{
	FileClientApi::FileClientApi(contracts::services::IServiceAddress& address)
			: AbstractClientService(address)
	{
		FileClientApi::init();
	}

	FileClientApi::~FileClientApi() {
		FileClientApi::de_init();
	}

	void FileClientApi::init() 
	{
		connect();

		add_call_handler<AsyncGetFileCall   >();
		add_call_handler<AsyncCreateFileCall>();
		add_call_handler<AsyncDeleteFileCall>();
		add_call_handler<AsyncExistsFileCall>();
	}

	void FileClientApi::de_init()  {
		stop();
	}

	std::shared_ptr<std::string>
		FileClientApi::get(const std::string& url)
	{
		auto queue = get_completion_queue<AsyncGetFileCall>();
		if (queue == nullptr)	return nullptr;

		Services::FileMessage request;
		request.set_id(url);

		auto call = new AsyncGetFileCall;
		set_call_options(call);
		call->reader = stub_->AsyncGet(&call->context, request, queue);
		call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

		try
		{
			return utils::service::get_result(call->promise, std::chrono::seconds(20));
		}
		catch (std::exception&)
		{
			return nullptr;
		}
	}

	std::string FileClientApi::create(const std::string& data)
	{
		auto queue = get_completion_queue<AsyncCreateFileCall>();
		if (queue == nullptr)	return nullptr;

		Services::FileBytes request;
		request.set_data(data);

		auto call = new AsyncCreateFileCall;
		set_call_options(call);
		call->reader = stub_->AsyncCreate(&call->context, request, queue);
		call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

		try
		{
			return utils::service::get_result(call->promise, std::chrono::seconds(20));
		}
		catch (std::exception&)
		{
			return "";
		}
	}

	bool FileClientApi::delete_file(const std::string& url)
	{
		auto queue = get_completion_queue<AsyncDeleteFileCall>();
		if (queue == nullptr)	return false;

		Services::FileMessage request;
		request.set_id(url);

		auto call = new AsyncDeleteFileCall;
		set_call_options(call);
		call->reader = stub_->AsyncDelete(&call->context, request, queue);
		call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));
		try
		{
			return utils::service::get_result(call->promise, std::chrono::seconds(5));
		}
		catch (std::exception&)
		{
			return "";
		}
	}

	bool FileClientApi::exists(const std::string& url)
	{
		auto queue = get_completion_queue<AsyncExistsFileCall>();
		if (queue == nullptr)	return false;

		Services::FileMessage request;
		request.set_id(url);

		auto call = new AsyncExistsFileCall;
		set_call_options(call);
		call->reader = stub_->AsyncExists(&call->context, request, queue);
		call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

		try
		{
			return utils::service::get_result(call->promise, std::chrono::seconds(5));
		}
		catch (std::exception&)
		{
			return "";
		}
	}
}
