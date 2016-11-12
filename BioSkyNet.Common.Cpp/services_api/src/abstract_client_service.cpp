#include "abstract_client_service.hpp"

#include <helpers/service_heplers.hpp>
#include <logging/logger.hpp>
#include "helpers/abstract_async_call.hpp"

namespace services_api
{

	AbstractClientService::AbstractClientService(contracts::services::IServiceAddress& address)
		: active_(false)
		, thread_pool_(0)
		, address_(address.get())
	{}

	AbstractClientService::~AbstractClientService() {
		AbstractClientService::stop();
	}

	void AbstractClientService::connect()
	{
		//auto address = address_.get();
		logger_.info("Try create channel {0}", address_);

		channel_ = CreateChannel(address_, grpc::InsecureChannelCredentials());
		do_create_stub(channel_);
	}

	void AbstractClientService::start()
	{
		if (active_)
			return;

		active_ = true;
		for (auto handler : handlers_)
			thread_pool_.Add(handler.second.callback);

		logger_.info("{0} connected to {1}", class_name(), address_);
	}

	void AbstractClientService::stop()
	{
		if (handlers_.empty())
			return;

		for (auto it : handlers_)
			it.second.completion_queue->Shutdown();
		handlers_.clear();

		logger_.info("{0} stopped", class_name());
	}

	void AbstractClientService::set_call_options(IAsyncCall* call) const {
		do_set_call_options(call);

		helpers::set_deadline(call->context, call->deadline);
		helpers::set_metadata(call->context, call->metadata);
	}	
}
