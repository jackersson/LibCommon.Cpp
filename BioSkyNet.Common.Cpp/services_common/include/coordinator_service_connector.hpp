#ifndef CoordinatorConnector_Included
#define CoordinatorConnector_Included

#include <services/icoordinator_api.hpp>
#include "repeatable_action.hpp"
#include <common/ilifecycle.hpp>
#include <chrono>
#include <common/logger.hpp>
#include <services/iconnection_state.hpp>

namespace services
{
	namespace helpers
	{
		class CoordinatorConnector : public utils::threading::IRepeatableAction
			                         , public contracts::common::IModule
			                         , public contracts::services::IConnectionState
		{
		public:
			explicit
				CoordinatorConnector( contracts::services::ICoordinatorApi*
					                  , const contracts::services::ICoordinatorMessages&);

			~CoordinatorConnector() {
				CoordinatorConnector::de_init();
			}

			void action() override;

			bool can() override {
				return !connected_;
			}

			void init() override;

			void de_init() override;

			bool connected() const override {
				return connected_;
			}

		private:			
			bool connected_;
			contracts::services::ICoordinatorApi* coordinator_;		

			std::unique_ptr<utils::threading::RepeatableAction> repeatable_action_;

			//TODO maybe to config
			const std::chrono::seconds DELAY = std::chrono::seconds(3);
			static data_model::ConnectMsg connect_message_;

			contracts::logging::Logger logger_;
		};
	}
}

#endif