#ifndef FacialClientCalls_INCLUDED
#define FacialClientCalls_INCLUDED

#include <datatypes/queries.pb.h>
#include <datatypes/commands.pb.h>
#include <future>
#include <helpers/service_heplers.hpp>
#include <services/facial_service.pb.h>

namespace services_api
{
	struct AsyncFaceProcessCall : AbstractAsyncCall<Services::BiometricResponse> {
		void process() override
		{		
			auto gr = std::make_shared<Services::BiometricResponse>(response);
			promise.set_value(gr);
		}

		const std::string& identifier() const override
		{
			static std::string class_name = typeid(AsyncFaceProcessCall).name();
			return class_name;
		}

		std::promise<std::shared_ptr<Services::BiometricResponse>> promise;

		std::unique_ptr<grpc::ClientAsyncResponseReader<Services::BiometricResponse>> reader;
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