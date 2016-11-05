#ifndef ServiceHelpers_INCLUDED
#define ServiceHelpers_INCLUDED

#include <include/grpc++/impl/codegen/completion_queue.h>
#include <grpc++/grpc++.h>
#include <future>
#include <google/protobuf/empty.pb.h>

namespace services_api
{

	typedef std::function<void()> RpcCallbackFunction;
	typedef std::vector<std::pair<std::string, std::string>> Metadata;

	const int REQUEST_DEADLINE = 1;

	struct IAsyncCall
	{
		IAsyncCall() : deadline(REQUEST_DEADLINE) {}

		virtual ~IAsyncCall() {}

		virtual void               process   ()       = 0;
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
		virtual ~AbstractAsyncCall(){}
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

	//************************
	template<typename TQueue>
	struct RequestHandlerBase
	{
		RequestHandlerBase() {}

		RequestHandlerBase( std::shared_ptr<TQueue> cq
			                 , RpcCallbackFunction callback_)
			                 : completion_queue(cq), callback(callback_)
		{	}
		std::shared_ptr<TQueue> completion_queue;
		RpcCallbackFunction callback;
	};

	struct ServerRequestHandler : RequestHandlerBase<grpc::ServerCompletionQueue>
	{
		ServerRequestHandler(std::shared_ptr<grpc::ServerCompletionQueue> cq
			, RpcCallbackFunction callback_)
			: RequestHandlerBase(cq, callback_)
		{	}
	};
	typedef std::list<ServerRequestHandler>              ServerRequestHandlers;

	struct ClientRequestHandler : RequestHandlerBase<grpc::CompletionQueue>
	{
		ClientRequestHandler(std::shared_ptr<grpc::CompletionQueue> cq
			, RpcCallbackFunction callback_)
			: RequestHandlerBase(cq, callback_)
		{	}
	};
	typedef std::map<std::string, ClientRequestHandler> ClientRequestHandlers;

	//*****************************
	namespace helpers
	{
		inline void set_deadline(grpc::ClientContext& context, uint32_t seconds)
		{
			auto deadline =
				std::chrono::system_clock::now() + std::chrono::seconds(seconds);
			context.set_deadline(deadline);
		}

		inline std::pair<std::string, std::string>
			               get_metadata_pair( const std::string& id
											                , const std::string& value ) 
		{
			return std::pair<std::string, std::string>(id, value);
		}

		inline
			void set_metadata( grpc::ClientContext& context
				                , const Metadata& metadata)
		{
			if (metadata.size() <= 0)
				return;
			for (auto item : metadata)
				context.AddMetadata(item.first, item.second);
		}

		inline
			void set_metadata(grpc::ClientContext& context
				, const std::pair<std::string, std::string>& metadata)
		{
			context.AddMetadata(metadata.first, metadata.second);
		}

		template <typename T>
		grpc::CompletionQueue* get_completion_queue(const ClientRequestHandlers& handlers)
		{
			auto it = handlers.find(typeid(T).name());
			if (it == handlers.end())
				return nullptr;
			return it->second.completion_queue.get();
		}
	}
}

#endif