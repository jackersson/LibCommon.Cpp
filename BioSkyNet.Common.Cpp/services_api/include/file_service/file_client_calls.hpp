#ifndef FileClientCall_INCLUDED
#define FileClientCall_INCLUDED

#include <helpers/service_heplers.hpp>
#include <future>

namespace services_api
{
	struct AsyncGetFileCall : AbstractAsyncCall<Services::FileBytes> {
		void process() override
		{			
			auto result = std::make_shared<Services::FileBytes>(response);
			promise.set_value(result);
		}

		std::promise<std::shared_ptr<Services::FileBytes>> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::FileBytes>> reader;
	};

	struct AsyncCreateFileCall : AbstractAsyncCall<Services::FileMessage> {
		void process() override
		{
			auto result = std::make_shared<Services::FileMessage>(response);
			promise.set_value(result);
		}

		std::promise<std::shared_ptr<Services::FileMessage>> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::FileMessage>> reader;
	};

	struct AsyncDeleteFileCall : AbstractAsyncCall<Services::EmptyMessage> {
		void process() override	{		
			promise.set_value(true);
		}

		std::promise<bool> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::EmptyMessage>> reader;
	};

	struct AsyncExistsFileCall : AbstractAsyncCall<Services::ExistMessage> {

		void process() override	{	
			promise.set_value(response.result());
		}

		std::promise<bool> promise;
		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::ExistMessage>> reader;
	};
}

#endif