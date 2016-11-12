#ifndef FileClientCall_INCLUDED
#define FileClientCall_INCLUDED

//#include <services/file_service.pb.h>
#include <future>

namespace Services
{
	class FileBytes;
	class FileMessage;
};

namespace services_api
{
	struct AsyncGetFileCall : AbstractAsyncCall<Services::FileBytes> {
		void process() override
		{			
			auto result = std::make_shared<std::string>(response.data());
			promise.set_value(result);
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncGetFileCall).name();
			return class_name;
		}

		std::promise<std::shared_ptr<std::string>> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::FileBytes>> reader;
	};

	struct AsyncCreateFileCall : AbstractAsyncCall<Services::FileMessage> {
		void process() override	{
			promise.set_value(response.id());
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncCreateFileCall).name();
			return class_name;
		}

		std::promise<std::string> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::FileMessage>> reader;
	};

	struct AsyncDeleteFileCall : AbstractAsyncCall<google::protobuf::Empty> {
		void process() override	{		
			promise.set_value(true);
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncDeleteFileCall).name();
			return class_name;
		}

		std::promise<bool> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<google::protobuf::Empty>> reader;
	};

	struct AsyncExistsFileCall : AbstractAsyncCall<Services::ExistMessage> {

		void process() override	{	
			promise.set_value(response.result());
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncExistsFileCall).name();
			return class_name;
		}

		std::promise<bool> promise;
		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::ExistMessage>> reader;
	};
}

#endif