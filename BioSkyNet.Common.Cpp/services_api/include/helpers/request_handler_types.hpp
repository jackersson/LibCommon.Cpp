#ifndef RequestHandlerTypes_INCLUDED
#define RequestHandlerTypes_INCLUDED

#include <include/grpc++/impl/codegen/completion_queue.h>
#include <grpc++/grpc++.h>

namespace services_api
{
	typedef std::function<void()> RpcCallbackFunction;

	template<typename TQueue>
	struct RequestHandlerBase
	{
		RequestHandlerBase() {}

		RequestHandlerBase(std::shared_ptr<TQueue> cq
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

}

#endif