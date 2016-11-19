#ifndef RequestHandler_Included
#define RequestHandler_Included

#include <include/grpc++/impl/codegen/completion_queue.h>
#include <include/grpc++/impl/codegen/server_context.h>
#include <logging/logger.hpp>

namespace grpc_services
{
	template <typename T>
	class RequestHandler
	{
	public:	
		RequestHandler( T* service
			            , grpc::ServerCompletionQueue* completion_queue	)
			            : service_(service)
			            , server_completion_queue_(completion_queue)
			            , status_(CREATE)
		{}

		virtual ~RequestHandler() {	}

		virtual void create_request_handler() = 0;
		virtual void create_request()         = 0;
		virtual void process_request()        = 0;

		void proceed()
		{
			if (status_ == CREATE)
			{
				next();
				try_create_request();
			}
			else if (status_ == PROCESS)
			{
				create_request_handler();
				try_process_request();
			}
			else
			{
				//GPR_ASSERT(status_ == FINISH);
				delete this;
			}
		}		

		void try_create_request()
		{
			try
			{
				create_request();
			}
			catch (std::exception& exception)	{
				logger_.error(exception.what());
			}
		}
		
		void try_process_request()
		{
			process_request();
		}

		void next()
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
		enum RequestStatus { CREATE, PROCESS, FINISH };
		
		T* service_;
		grpc::ServerCompletionQueue* server_completion_queue_;	
		grpc::ServerContext          server_context_;

		contracts::logging::Logger logger_;
		RequestStatus              status_;

	private:
		RequestHandler(const RequestHandler&) = delete;
		RequestHandler& operator=(const RequestHandler&) = delete;

	};

}
#endif