#ifndef RequestHandler_Included
#define RequestHandler_Included

#include <memory>
#include <include/grpc++/impl/codegen/completion_queue.h>
#include <include/grpc++/impl/codegen/server_context.h>
#include <common/logger.hpp>

namespace grpc_services
{
	template <typename T>
	class RequestHandler
	{
		enum RequestStatus { CREATE, PROCESS, FINISH };
	public:
	
		RequestHandler( T* service
			            , grpc::ServerCompletionQueue* completion_queue	)
			            : service_(service)
			            , server_completion_queue_(completion_queue)
			            , status_(CREATE)
		{}

		virtual ~RequestHandler() {	}

		virtual void CreateRequestHandler() = 0;
		virtual void CreateRequest()        = 0;
		virtual void ProcessRequest()       = 0;

		void Proceed()
		{
			if (status_ == CREATE)
			{
				Next();
				TryCreateRequest();
			}
			else if (status_ == PROCESS)
			{
				CreateRequestHandler();
				TryProcessRequest();
			}
			else
			{
				//GPR_ASSERT(status_ == FINISH);
				delete this;
			}
		}		

		void TryCreateRequest()
		{
			try
			{
				CreateRequest();
			}
			catch (std::exception& exception)	{
				logger_.error(exception.what());
			}
		}
		
		void TryProcessRequest()
		{
			Next();
			ProcessRequest();
		}

		void Next()
		{
			switch (status_)
			{
			case CREATE:
				status_ = PROCESS;
				break;
			case PROCESS: 
				status_ = FINISH;
				break;			
			default: break;
			}
		}

	protected:
		T* service_;
		grpc::ServerCompletionQueue* server_completion_queue_;	
		grpc::ServerContext          server_context_;

		contracts::logging::Logger logger_;
	private:
		RequestHandler(const RequestHandler&) = delete;
		RequestHandler& operator=(const RequestHandler&) = delete;

		RequestStatus status_;
	};

}
#endif