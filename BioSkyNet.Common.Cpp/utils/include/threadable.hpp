#ifndef Threadable_Included
#define Threadable_Included

#include <asio/io_service.hpp>
#include <thread.hpp>

namespace utils
{
	class Threadable
	{
	public:
		Threadable();

		virtual ~Threadable();
		
		void start();

		virtual void stop();

		bool active() const {
			return active_;
		}

	protected:
		void virtual run() = 0;

		bool cancelation_requested;
	private:
		static void thread_procedure(void* thread_context);
		
		boost::asio::io_service       io_service_;
	  boost::thread_group           threads_   ;
		boost::asio::io_service::work work_ ;

		bool active_;
	};
}

#endif
