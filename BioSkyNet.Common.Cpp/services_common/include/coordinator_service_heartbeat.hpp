#ifndef CoordinatorHeartbeat_Included
#define CoordinatorHeartbeat_Included

#include "repeatable_action.hpp"
#include <common/ilifecycle.hpp>
#include <services/icoordinator_api.hpp>
#include <chrono>
#include <common/logger.hpp>
#include <services/iconnection_state.hpp>

namespace services
{
	namespace helpers
	{
		class CoordinatorHeartbeat : public utils::threading::IRepeatableAction
			, public contracts::common::IModule
		{
		public:
			CoordinatorHeartbeat(contracts::services::IHeartbeat*        coordinator
				, contracts::services::IConnectionState* coordinator_connection
				, const contracts::services::ICoordinatorMessages& messages);
			~CoordinatorHeartbeat() {
				CoordinatorHeartbeat::de_init();
			}

			void action() override;

			bool can() override {
				return coordinator_connection_ == nullptr
					? false : coordinator_connection_->connected();
			}

			void init()    override;
			void de_init() override;

		private:
			bool connected_;
			contracts::services::IHeartbeat* context_;

			contracts::services::IConnectionState* coordinator_connection_;
			const std::chrono::seconds DELAY = std::chrono::seconds(5);

			std::unique_ptr<utils::threading::RepeatableAction> repeatable_action_;
			static data_model::HeartbeatMessage message_;

			contracts::logging::Logger logger_;

		};
	}
}

#endif