/*#include <coordinator_service_connector.hpp>
#include <data/models/unit.hpp>

namespace services
{
	namespace helpers
	{
		data_model::ConnectMsg CoordinatorConnector::connect_message_;
		data_model::HeartbeatMessage CoordinatorConnector::heartbeat_message_;
		CoordinatorConnector::CoordinatorConnector(
			  contracts::services::ICoordinatorApi* coordinator
			, const contracts::services::ICoordinatorMessages& messages)
			: connected_  (false)
			, coordinator_(coordinator)
		{
			if (coordinator_ == nullptr)
				throw std::exception("Coordinator can't be null");

			connect_message_   = messages.connect_msg();
			heartbeat_message_ = messages.heartbeat_msg();
		}
		
		void CoordinatorConnector::action()
		{
			if (connected_)
			{
				 auto ok = coordinator_->heart_beat(heartbeat_message_);
				 logger_.info("Hearbeat {0}", ok);
				 if (!ok)
					 try_connect();
			}
			else
			{
				auto ok = try_connect();
				if (!ok)
			  	logger_.info("Coordinator client can't connect. {0}");
			}
		}

		bool CoordinatorConnector::try_connect()
		{
			if (coordinator_ == nullptr)
				return false;

			try
			{
				connected_ = coordinator_->connect_request(connect_message_);
				if  (connected_)
			  	logger_.info("Connected to coordinator successfully");
			}
			catch (std::exception& exception)
			{
				logger_.info("Coordinator connection error {0}"
					, exception.what());
			}
			return connected_;
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
			if (repeatable_action_ != nullptr)
		  	repeatable_action_->stop();
		}		
	}
}
*/