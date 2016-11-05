#include <coordinator_service_connector.hpp>

namespace services
{
	namespace helpers
	{
		data_model::ConnectMsg CoordinatorConnector::connect_message_;

		CoordinatorConnector::CoordinatorConnector(
			  contracts::services::ICoordinatorApi* coordinator
			, const contracts::services::ICoordinatorMessages& messages)
			: connected_  (false)
			, coordinator_(coordinator)
		{
			if (coordinator_ == nullptr)
				throw std::exception("Coordinator can't be null");

			connect_message_ = messages.connect_msg();
		}

		void CoordinatorConnector::action()
		{
			if (coordinator_ == nullptr)
				return;
			try
			{
				connected_ = coordinator_->connect_request(connect_message_);
			}
			catch (std::exception& exception)
			{
				logger_.info("Coordinator connection error {0}"
					, exception.what());
			}
			if (connected_)
			{
				logger_.info("Connected to coordinator successfully");
				repeatable_action_->stop();
			}
			else
				logger_.info("Coordinator client can't connect. {0}");
		}


		void CoordinatorConnector::init()
		{
			if (repeatable_action_ != nullptr)
				return;

			repeatable_action_
				= std::make_unique<utils::threading::RepeatableAction>(this, DELAY);
			repeatable_action_->start();
		}

		void CoordinatorConnector::de_init()
		{
			repeatable_action_->stop();
		}		
	}
}