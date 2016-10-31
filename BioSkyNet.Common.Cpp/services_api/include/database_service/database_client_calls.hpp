#ifndef DatabaseClientCall_INCLUDED
#define DatabaseClientCall_INCLUDED

#include <datatypes/queries.pb.h>
#include <datatypes/commands.pb.h>
#include <future>
#include <helpers/service_heplers.hpp>

namespace services_api
{	
	struct AsyncGetRequestCall : AbstractAsyncCall<DataTypes::MessageBytes> {
		void process() override
		{
			if (response.type() != DataTypes::DataType::GetResponseType)
			{
				promise.set_exception(std::make_exception_ptr("Invalid data type"));
				return;
			}
			auto gr = std::make_shared<DataTypes::GetResponse>();
			gr->ParseFromString(response.data());
			promise.set_value(gr);
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncGetRequestCall).name();
			return class_name;
		}

		std::promise<std::shared_ptr<DataTypes::GetResponse>> promise;
	
		std::unique_ptr<grpc::ClientAsyncResponseReader<DataTypes::MessageBytes>> reader;
	};

	struct AsyncCommitRequestCall : AbstractAsyncCall<DataTypes::MessageBytes> {

		void process() override
		{
			if (response.type() != DataTypes::DataType::CommitResponseType)
			{
				promise.set_exception(std::make_exception_ptr("Invalid data type"));
				return;
			}

			auto gr = std::make_shared<DataTypes::CommitResponse>();
			gr->ParseFromString(response.data());
			promise.set_value(gr);
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncCommitRequestCall).name();
			return class_name;
		}

		std::promise<std::shared_ptr<DataTypes::CommitResponse>> promise;
		std::unique_ptr<grpc::ClientAsyncResponseReader<DataTypes::MessageBytes>> reader;
	};
}

#endif