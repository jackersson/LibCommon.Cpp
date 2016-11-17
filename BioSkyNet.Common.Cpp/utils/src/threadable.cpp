#include "threadable.hpp"

#include <boost/thread.hpp>
#include <boost/asio/io_service.hpp>

namespace utils
{	
	Threadable::Threadable() 
		 : cancelation_requested(false)
		 , work_(io_service_)
		 , active_(false)
	{}

	Threadable::~Threadable()
	{
		Threadable::stop();
	}

	void Threadable::start()
	{
		if (active_)
			return;
		active_ = true;
		cancelation_requested = false;
		threads_.create_thread(boost::bind(&boost::asio::io_service::run
			, &io_service_));
		io_service_.reset();
		io_service_.post(boost::bind(thread_procedure, this));
	}

	void Threadable::stop()
	{
		try
		{
			cancelation_requested = true;
			active_ = false;
			io_service_.stop();
			threads_.join_all();
		}
		catch (std::exception&)
		{
			//Not implemented
		}
	}

	void Threadable::thread_procedure(void* thread_context)
	{
		auto instance = static_cast<Threadable*>(thread_context);

		if (instance == nullptr)
			return;
		instance->active_ = true;
		instance->run();
		instance->active_ = false;
	}
}
