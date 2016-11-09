#include "coordinator_utils.hpp"
#include <network_utils.hpp>
#include <services/service_address.hpp>

namespace services
{
	namespace helpers
	{
		data_model::ConnectMsg
			generate_connect_msg(uint16_t service_port
				, const std::string& service_id
				, data_model::ServiceType service_type)
		{
			auto ip_address = utils::network::get_local_ip();
			contracts::services::ServiceAddress sa(ip_address, service_port);

			data_model::ConnectMsg connect_msg;
			connect_msg.ip_address = sa.get();
			connect_msg.type = service_type;
			connect_msg.id = data_model::Key(service_id);

			return connect_msg;
		}

		data_model::HeartbeatMessage
			generate_heartbeat_msg(const std::string& service_id
				, data_model::ServiceType   service_type)
		{
			auto ip_address = utils::network::get_local_ip();

			data_model::HeartbeatMessage message;
			message.type = service_type;
			message.id = data_model::Key(service_id);

			return message;
		}
	}
}