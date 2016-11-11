#ifndef RequestAdapters_Included
#define RequestAdapters_Included

namespace Services{
	class BiometricResponse;
	class BiometricRequest;
}

namespace data_model
{
	class BiometricResponse;
	class BiometricRequest;
	class DeviceUpdate;
	class ConnectMsg;
	class HeartbeatMessage;
	class Key;
	class CaptureDevice;
	class AccessDevice;
	class Person;
	class Location;
	class DateTime;
	class FaceCharacteristics;
	class Card;
	class VisitRecord;
	class Entity;
	class Mutation;
	class CommitRequest;
	enum AccessState;
	class MutationResult;
	class CommitResponse;
	class GetResponse;
	class GetPersonRequest     ;
	class GetLocationRequest   ;
	class GetRequest           ;
	class GetFaceCharRequest   ;
	class GetVisitRecordRequest;
}

namespace DataTypes{
	class DeviceUpdate;
	class ConnectMsg;
	class HeartbeatMessage;
	class MessageBytes;
	class Key;
	class CaptureDevice;
	class AccessDevice;
	class Person;
	class Location;
	class DateTime;
	class FaceCharacteristic;
	class Card;
	class VisitRecord;
	class Entity;
	class Mutation;
	class CommitRequest;
	enum AccessState;
	class MutationResult;
	class CommitResponse;
	class GetResponse;
	class GetRequest;

}

namespace services_api
{
	namespace helpers
	{
		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetRequest& gr);
	
		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetLocationRequest& gr);	

		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetPersonRequest& gr);
		
		data_model::GetResponse
			to_data_get_response(const DataTypes::GetResponse& gr);
	

		data_model::CommitResponse
			to_data_commit_response(const DataTypes::CommitResponse& gr);

		data_model::MutationResult
			to_data_mutation_result(const DataTypes::MutationResult& gr);

		DataTypes::AccessState to_proto_access_state(data_model::AccessState gr);
	
		DataTypes::CommitRequest
			to_proto_commit_request(const data_model::CommitRequest& gr);

		void to_proto_mutation(const data_model::Mutation& gr
		                    	, DataTypes::Mutation&       target);	

		DataTypes::Entity	to_proto_entity(const data_model::Entity& gr);

		DataTypes::VisitRecord	
			to_proto_visit_record(const data_model::VisitRecord& gr);

		DataTypes::Card
			to_proto_card(const data_model::Card& gr);
		
		DataTypes::FaceCharacteristic
			to_proto_face(const data_model::FaceCharacteristics& gr);

		DataTypes::DateTime
			to_proto_time(const data_model::DateTime& gr);		

		data_model::CommitRequest
			to_data_commit_insert(const data_model::VisitRecord& gr);
	

		data_model::Entity to_data_entity(const DataTypes::Entity&   gr);

		Services::BiometricRequest
			to_proto_biometric_request(const data_model::BiometricRequest& gr);

		data_model::BiometricResponse
			to_data_biometric_response(const Services::BiometricResponse& gr);		

		DataTypes::HeartbeatMessage
			to_proto_heartbeat_msg(const data_model::HeartbeatMessage& gr);
		

		inline DataTypes::ConnectMsg
			to_proto_connect_msg(const data_model::ConnectMsg& gr);
	


		void to_message_bytes(const DataTypes::GetRequest& request
			                    , DataTypes::MessageBytes& message);
		

		void to_message_bytes( const DataTypes::CommitRequest& request
			                   , DataTypes::MessageBytes& message);
		

		data_model::Location to_data_location(const DataTypes::Location& gr);		
		data_model::Person   to_data_person  (const DataTypes::Person&   gr);

		data_model::AccessDevice
			to_data_access_device(const DataTypes::AccessDevice& gr);		

		data_model::CaptureDevice
			to_data_capture_device(const DataTypes::CaptureDevice& gr);

		
		data_model::Key to_data_model_key(const DataTypes::Key& key);

		DataTypes::DeviceUpdate
			to_proto_device_update(const data_model::DeviceUpdate& gr);
			;
		/*

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

		


		/*
		inline DataTypes::Position*
		to_proto_position(float xpos, float ypos)
		{
		auto proto_position = new DataTypes::Position();
		proto_position->set_x(xpos);
		proto_position->set_y(ypos);
		return proto_position;
		}

		inline DataTypes::Position*
		to_proto_position(const contracts::geometries::IPosition& pos)
		{
		return to_proto_position(pos.x(), pos.y());
		}
		*/
		/*
		inline
		DataTypes::Key* to_proto_key(const data_model::Key& key)
		{
		auto target_key = new DataTypes::Key();

		if (key.has_guid())
		contracts::data::set_guid(key.guid(), *target_key);
		else if (key.has_identifier())
		target_key->set_identifier(key.identifier());
		else if (key.has_numeric_id())
		target_key->set_number(key.number());

		return target_key;
		}

		inline
		data_model::Key to_data_key(const DataTypes::Key& key)
		{
		switch (key.id_type_case())
		{
		case DataTypes::Key::kNumber:
		return data_model::Key(key.number());
		case DataTypes::Key::kIdentifier:
		return data_model::Key(key.identifier());
		case DataTypes::Key::kGuid:
		return data_model::Key(key.guid());
		case DataTypes::Key::ID_TYPE_NOT_SET: break;
		default: break;
		}
		return data_model::Key();
		}
		*/
		/*
		inline
		DataTypes::Box* to_service_box(const contracts::geometries::IBox& box)
		{
		const auto& origin = box.origin();
		const auto& end    = box.end();

		auto target_box = new DataTypes::Box();
		target_box->set_allocated_begin(to_proto_position(origin));
		target_box->set_width (std::abs(origin.x() - end.x()));
		target_box->set_height(std::abs(origin.y() - end.y()));

		return target_box;
		}

		inline
		void to_service_faces( const contracts::faces::IFaces& faces
		, DataTypes::Faces& target_faces)
		{
		auto count = faces.size();
		if (count <= 0)
		return;

		auto photo_id = to_proto_key(faces.id());
		for (auto i = 0; i < faces.size(); ++i)
		{
		auto& iface = faces[i];
		auto face = target_faces.add_faces();

		face->set_allocated_id(to_proto_key(iface.id()));
		face->set_allocated_box(to_service_box(iface.bounding_box()));
		face->set_fir_url(iface.template_url());
		face->set_confidence(iface.confidence());

		face->set_allocated_person_id(to_proto_key(iface.person_id()));
		face->set_allocated_photo_id(photo_id);
		}
		}


		*/


	}
}

#endif
