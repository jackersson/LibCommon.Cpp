#include "coordinator_service_heartbeat.hpp"
#include <data/models/unit.hpp>
namespace services
{
	namespace helpers
	{
		data_model::HeartbeatMessage CoordinatorHeartbeat::message_;

		CoordinatorHeartbeat::CoordinatorHeartbeat
		(contracts::services::IHeartbeat* context
			, contracts::services::IConnectionState* coordinator_connection
			, const contracts::services::ICoordinatorMessages& messages)
			: connected_(false)
			, context_(context)
			, coordinator_connection_(coordinator_connection)
		{
			message_ = messages.heartbeat_msg();
		}


		void CoordinatorHeartbeat::action() {

			context_->heart_beat(message_);
			logger_.info("Hearbeat");
		}

		void CoordinatorHeartbeat::init() {
			repeatable_action_
				= std::make_unique<utils::threading::RepeatableAction>(this, DELAY);
			repeatable_action_->start();
		}

		void CoordinatorHeartbeat::de_init()
		{
			repeatable_action_->stop();
			logger_.info("Hearbeat stopped");
		}
	}
}