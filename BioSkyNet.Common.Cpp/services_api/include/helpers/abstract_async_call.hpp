#ifndef AbstractAsyncClient_INCLUDED
#define AbstractAsyncClient_INCLUDED

#include <future>
#include "service_heplers.hpp"
#include <google/protobuf/empty.pb.h>

namespace services_api
{	
	const int REQUEST_DEADLINE = 2;

	struct IAsyncCall
	{
		IAsyncCall() : deadline(REQUEST_DEADLINE) {}

		virtual ~IAsyncCall() {}

		virtual void               process() = 0;
		virtual const std::string& identifier() const = 0;

		grpc::ClientContext  context;
		grpc::Status         status;
		uint32_t             deadline; //in seconds
		Metadata             metadata;
	};

	//**************************
	template <typename TResponse>
	struct AbstractAsyncCall : IAsyncCall
	{
		AbstractAsyncCall() : IAsyncCall() {}
		virtual ~AbstractAsyncCall() {}
		TResponse            response;
	};

	struct AsyncEmptyCall : AbstractAsyncCall<google::protobuf::Empty>
	{
		void process() override {
			promise.set_value(true);
		}

		std::promise<bool>  promise;
		std::unique_ptr<grpc::ClientAsyncResponseReader<google::protobuf::Empty>> reader;
	};
}

#endif