#ifndef RequestAdapters_Included
#define RequestAdapters_Included

#include <datatypes/commands.pb.h>
#include <datatypes/queries.pb.h>
#include <data/models/queries.hpp>
#include <data/models/location.hpp>
#include <data/models/person.hpp>
#include <data/models/visit_record.hpp>
#include <data/models/face_characteristics.hpp>
#include <data/models/devices.hpp>
#include <data/models/unit.hpp>
#include <datatypes/unit.pb.h>
#include <services/facial_service.pb.h>

//TODO -> use forward declaration instead of "include"
//TODO -> RequestAdapters->use cpp file
namespace services_api
{
	namespace helpers
	{
		inline DataTypes::GetRequest
			to_proto_get_request(const data_model::GetRequest& gr)
		{
			return DataTypes::GetRequest();
		}

		inline DataTypes::GetRequest
			to_proto_get_request(const data_model::GetFaceCharRequest& gr)
		{
			return DataTypes::GetRequest();
		}

		inline DataTypes::GetRequest
			to_proto_get_request(const data_model::GetLocationRequest& gr)
		{
			return DataTypes::GetRequest();
		}

		inline DataTypes::GetRequest
			to_proto_get_request(const data_model::GetPersonRequest& gr)
		{
			return DataTypes::GetRequest();
		}

		inline DataTypes::GetRequest
			to_proto_get_request(const data_model::GetVisitRecordRequest& gr)
		{
			return DataTypes::GetRequest();
		}

		inline data_model::GetResponse
			to_data_get_response(const DataTypes::GetResponse& gr)
		{
			return data_model::GetResponse();
		}

		inline data_model::CommitResponse
			to_data_commit_response(const DataTypes::CommitResponse& gr)
		{
			return data_model::CommitResponse();
		}

		inline DataTypes::CommitRequest
			to_proto_commit_request(const data_model::CommitRequest& gr)
		{
			return DataTypes::CommitRequest();
		}

		inline DataTypes::Entity
			to_proto_entity(const data_model::Person& gr)
		{
			return DataTypes::Entity();
		}

		inline DataTypes::Entity
			to_proto_entity(const data_model::VisitRecord& gr)
		{
			return DataTypes::Entity();
		}

		inline DataTypes::CommitRequest
			to_proto_commit_insert(const DataTypes::Entity& gr)
		{
			return DataTypes::CommitRequest();
		}

		inline data_model::CommitRequest
			to_data_commit_insert(const DataTypes::Entity& gr)
		{
			return data_model::CommitRequest();
		}


		inline Services::BiometricRequest
			to_proto_biometric_request(const data_model::BiometricRequest& gr)
		{
			return Services::BiometricRequest();
		}

		inline data_model::BiometricResponse
			to_data_biometric_response(const Services::BiometricResponse& gr)
		{
			return data_model::BiometricResponse();
		}

		inline data_model::FaceTemplate
			to_data_face_template(const DataTypes::FaceCharacteristic& gr)
		{
			return data_model::FaceTemplate();
		}

		inline data_model::FaceTemplate
			to_data_face_template(const data_model::FaceCharacteristics& gr)
		{
			return data_model::FaceTemplate();
		}

		inline data_model::Location
			to_data_location(const DataTypes::Location& gr)
		{
			return data_model::Location();
		}

		inline data_model::Person
			to_data_person(const DataTypes::Person& gr)
		{
			return data_model::Person();
		}

		inline data_model::VisitRecord
			to_data_visit_record(const DataTypes::VisitRecord& gr)
		{
			return data_model::VisitRecord();
		}

		inline DataTypes::DeviceUpdate
			to_proto_device_update(const data_model::DeviceUpdate& gr)
		{
			return DataTypes::DeviceUpdate();
		}

		inline DataTypes::HeartbeatMessage
			to_proto_heartbeat_msg(const data_model::HeartbeatMessage& gr)
		{
			return DataTypes::HeartbeatMessage();
		}

		inline DataTypes::ConnectMsg
			to_proto_connect_msg(const data_model::ConnectMsg& gr)
		{
			return DataTypes::ConnectMsg();
		}

		const int UUID_BYTES_SIZE = 16;
		inline void set_guid(const boost::uuids::uuid& guid, DataTypes::Key& key)
		{
			unsigned char data[UUID_BYTES_SIZE];
			memcpy(&data, guid.data, UUID_BYTES_SIZE);

			std::string str(data, data + sizeof(data) / sizeof(data[0]));
			key.set_guid(str);
		}

		inline bool get_guid(const DataTypes::Key& key, boost::uuids::uuid& guid)
		{
			if (key.id_type_case() != DataTypes::Key::IdTypeCase::kGuid)
				return false;

			auto key_guid = key.guid();
			memcpy(&guid, key_guid.data(), UUID_BYTES_SIZE);
			return guid.is_nil();
		}

		inline bool guid_empty(const DataTypes::Key& key)
		{
			boost::uuids::uuid guid;
			return get_guid(key, guid);
		}

		inline
			DataTypes::Key to_proto_key(const data_model::Key& key)
		{
			DataTypes::Key target_key;

			if (key.has_guid())
				set_guid(key.guid(), target_key);
			else if (key.has_identifier())
				target_key.set_identifier(key.identifier());
			else if (key.has_numeric_id())
				target_key.set_number(key.number());

			return target_key;
		}

		inline
			data_model::Key to_data_key(const DataTypes::Key& key)
		{
			switch (key.id_type_case())
			{
			case DataTypes::Key::kNumber:
				return data_model::Key(static_cast<long>(key.number()));
			case DataTypes::Key::kIdentifier:
				return data_model::Key(key.identifier());
			case DataTypes::Key::kGuid:
				return data_model::Key(key.guid());
			case DataTypes::Key::ID_TYPE_NOT_SET: break;
			default: break;
			}
			return data_model::Key();
		}

		inline DataTypes::Position
			to_proto_position(float xpos, float ypos)
		{
			DataTypes::Position proto_position;
			proto_position.set_x(static_cast<int32_t>(xpos));
			proto_position.set_y(static_cast<int32_t>(ypos));
			return proto_position;
		}

		inline DataTypes::Position
			to_proto_position(const contracts::geometries::IPosition& pos)
		{
			return to_proto_position(pos.x(), pos.y());
		}


		inline
			DataTypes::Box to_service_box(const contracts::geometries::IBox& box)
		{
			const auto& origin = box.origin();
			const auto& end    = box.end();

			auto begin_position = to_proto_position(origin);

			DataTypes::Box target_box;
			target_box.set_allocated_begin(&begin_position);
			target_box.set_width (static_cast<uint32_t>(abs(origin.x() - end.x())));
			target_box.set_height(static_cast<uint32_t>(abs(origin.y() - end.y())));

			return target_box;
		}

		inline void to_message_bytes( const DataTypes::GetRequest& request
			                          , DataTypes::MessageBytes& message)
		{
			std::string bytes;
			request.SerializeToString(&bytes);
			message.set_data(bytes);
			message.set_type(DataTypes::DataType::GetRequestType);
		}

		inline void to_message_bytes( const DataTypes::CommitRequest& request
		                            , DataTypes::MessageBytes& message)
		{
			std::string bytes;
			request.SerializeToString(&bytes);
			message.set_data(bytes);
			message.set_type(DataTypes::DataType::CommitRequestType);
		}

	}
}

#endif
