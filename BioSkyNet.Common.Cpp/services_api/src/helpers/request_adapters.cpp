#include "helpers/request_adapters.hpp"

#include <datatypes/commands.pb.h>
#include <datatypes/queries.pb.h>
#include <data/models/queries.hpp>
#include <data/models/location.hpp>
#include <data/models/person.hpp>
#include <data/models/visit_record.hpp>
#include <data/models/face_characteristics.hpp>
#include <data/models/devices.hpp>

#include <datatypes/unit.pb.h>
#include <data/models/unit.hpp>
#include <services/facial_service.grpc.pb.h>

#include <boost/uuid/uuid_io.hpp>

namespace services_api
{
	namespace helpers
	{
		
		//const int UUID_BYTES_SIZE = 16;
		void set_guid(const boost::uuids::uuid& guid, DataTypes::Key& key)
		{
			key.set_guid(to_string(guid));
			//unsigned char data[UUID_BYTES_SIZE];
			//memcpy(&data, guid.data, UUID_BYTES_SIZE);

			//std::string str(data, data + sizeof(data) / sizeof(data[0]));
			//key.set_guid(str);
		}

		/*
		bool get_guid(const DataTypes::Key& key, boost::uuids::uuid& guid)
		{
			
			if (key.id_type_case() != DataTypes::Key::IdTypeCase::kGuid)
				return false;

			key.guid() to_string(guid));
			to_data_key()
			auto key_guid = key.guid();
			memcpy(&guid, key_guid.data(), UUID_BYTES_SIZE);
			return guid.is_nil();
		}
		*/
		/*
		boost::uuids::uuid get_guid_from_key(const DataTypes::Key& key)
		{
			boost::uuids::uuid uuid;
			get_guid(key, uuid);
			return uuid;
		}
		*/
		
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

		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetLocationRequest& gr)
		{
			DataTypes::GetRequest proto_request;
			DataTypes::GetLocationRequest proto_entity_request;

			if (gr.has_mac_address())
			  proto_entity_request.set_mac_address(gr.mac_address());

			if (gr.has_person_id())
				proto_entity_request.mutable_person()->CopyFrom(to_proto_key(gr.person_id()));

			if (gr.has_location_id())
				proto_entity_request.mutable_id()->CopyFrom(to_proto_key(gr.location_id()));

			proto_request.mutable_location_request()->CopyFrom(proto_entity_request);
			
			return proto_request;
		}

		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetFacesRequest& gr)
		{
			DataTypes::GetRequest         proto_request;
			DataTypes::GetFaceCharRequest proto_entity_request;

			proto_request.mutable_facial_template_request()->CopyFrom(proto_entity_request);
			return proto_request;
		}

		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetPersonRequest& gr)
		{
			DataTypes::GetRequest       proto_request       ;
			DataTypes::GetPersonRequest proto_entity_request;

			const auto& card_id = gr.card().id();
			if (!card_id.is_empty() || card_id.has_identifier())
		  	proto_entity_request.set_card(card_id.identifier());
			proto_request.mutable_person_request()->CopyFrom(proto_entity_request);

			return proto_request;
		}
		
		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetRequest& gr)
		{			
			if (gr.has_location_request())
				return to_proto_get_request(gr.location_request());
			if (gr.has_person_request())
				return to_proto_get_request(gr.person_request());
			if (gr.has_faces_request())
				return to_proto_get_request(gr.faces_request());

			throw std::exception("to_proto_get_request not implemented");
		}

		data_model::GetResponse
			to_data_get_response(const DataTypes::GetResponse& gr)
		{
			data_model::GetResponse response;
			const auto& items = gr.items().items();
			for (const auto& entity : items)			
				response.add(to_data_entity(entity));
			
			return response;
		}

		data_model::Entity to_data_entity(const DataTypes::Entity& gr)
		{
			switch (gr.value_type_case())
			{
			case DataTypes::Entity::kCard       : break;
			case DataTypes::Entity::kPerson     : 
				return data_model::Entity(to_data_person(gr.person()));
			case DataTypes::Entity::kVisitRecord: break;
			case DataTypes::Entity::kLocation   :
				return data_model::Entity(to_data_location(gr.location()));
			case DataTypes::Entity::kPhoto      : break;
			case DataTypes::Entity::kGroup      : break;
			case DataTypes::Entity::kFace       : 
				return data_model::Entity(to_data_face_characteristics(gr.face()));
			case DataTypes::Entity::VALUE_TYPE_NOT_SET: break;
			default: break;
			}

			throw std::exception("to_data_entity not implemented exception");
		}

		data_model::FaceCharacteristics
			to_data_face_characteristics(const DataTypes::FaceCharacteristic& key)
		{
			data_model::FaceCharacteristics face;

			face.set_id        (to_data_model_key(key.id()));
			face.set_confidence(key.confidence());
			face.set_fir_url   (key.fir_url   ());
			face.set_person_id (to_data_model_key(key.person_id()));
			return face;
		}

		data_model::Location
			to_data_location(const DataTypes::Location& gr)
		{
			data_model::Location location;
			location.set_name            (gr.name());
			location.set_unit_mac_address(gr.unit_mac_address());
		  location.set_id            (to_data_model_key(gr.id()));
			location.set_access_device (to_data_access_device(gr.access_device()));
			location.set_capture_device(to_data_capture_device(gr.capture_device()));
			
			return location;
		}

		data_model::Person
			to_data_person(const DataTypes::Person& gr)
		{
			data_model::Person person;
			person.set_id(to_data_model_key(gr.id()));
			person.set_first_name(gr.first_name());
			person.set_last_name (gr.last_name ());
			return person;
		}

		data_model::AccessDevice
			to_data_access_device(const DataTypes::AccessDevice& gr)
		{
			return data_model::AccessDevice(static_cast<uint16_t>(gr.serial_number()));
		}

		data_model::CaptureDevice
			to_data_capture_device(const DataTypes::CaptureDevice& gr)
		{
			return data_model::CaptureDevice(gr.name());
		}

		data_model::CommitRequest
			to_data_commit_insert(const data_model::VisitRecord& gr)
		{
			data_model::CommitRequest request;
			data_model::Mutation mutation( data_model::Entity(gr)
				                           , data_model::InsertMutation);
			request.add(mutation);
			return request;
		}

		DataTypes::CommitRequest
			to_proto_commit_request(const data_model::CommitRequest& gr)
		{
			DataTypes::CommitRequest request;
			for ( const auto& item : gr)
			{
				auto mutation = request.add_mutations();
				to_proto_mutation(item, *mutation);
			}
			return request;
		}

		void to_proto_mutation( const data_model::Mutation& gr
				                  , DataTypes::Mutation&        target )
		{
			switch (gr.type())
			{
			case data_model::NoneMutationType: break;
			case data_model::InsertMutation:
				target.mutable_insert()->CopyFrom(to_proto_entity(gr.inserted()));
				break;
			case data_model::UpdateMutation:
				target.mutable_update()->CopyFrom(to_proto_entity(gr.updated()));
				break;
			case data_model::DeleteMutation:
				target.mutable_delete_()->CopyFrom(to_proto_entity(gr.deleted()));
				break;
			default: break;
			}			
		}

		DataTypes::Entity
			to_proto_entity(const data_model::Entity& gr)
		{
			DataTypes::Entity entity;
			switch ( gr.type() )
			{
			case data_model::NoneEntityType: break;
			case data_model::EntityPerson: 			
				break;
			case data_model::EntityVisitRecord: 
				entity.mutable_visit_record()
					->CopyFrom(to_proto_visit_record(gr.visit_record()));
				return entity;
			case data_model::EntityLocation: 
				
				break;
			case data_model::EntityFaceCharacteristics:	
				break;
			default: break;
			}

			throw std::exception("to_proto_entity Not implemented");
		}

		data_model::Key to_data_model_key(const DataTypes::Key& key)
		{
			switch (key.id_type_case())
			{
			case DataTypes::Key::kNumber:
				return data_model::Key(static_cast<long>(key.number()));
			case DataTypes::Key::kIdentifier:
				return data_model::Key(key.identifier());
			case DataTypes::Key::kGuid:
				return contracts::data::to_data_key(key.guid());
			case DataTypes::Key::ID_TYPE_NOT_SET: break;
			default: break;
			}
			return data_model::Key();
		}

		DataTypes::VisitRecord
			to_proto_visit_record(const data_model::VisitRecord& gr)
		{
			DataTypes::VisitRecord vr;
			vr.mutable_id()         ->CopyFrom(to_proto_key(gr.id()));
			vr.mutable_location_id()->CopyFrom(to_proto_key(gr.location_id()));
			vr.mutable_person_id  ()->CopyFrom(to_proto_key(gr.person_id()  ));
			vr.mutable_card()->CopyFrom(to_proto_card(gr.card()));
			vr.set_state(to_proto_access_state(gr.access_state()));
			//Not implemented
			//vr.mutable_face()->CopyFrom(to_proto_face(gr.face()));
			vr.mutable_time()->CopyFrom(to_proto_time(gr.time()));

			return vr;
		}

		DataTypes::Card
			to_proto_card(const data_model::Card& gr)
		{
			DataTypes::Card card;
			card.mutable_owner_id()->CopyFrom(to_proto_key(gr.owner_id()));
			card.mutable_unique_identifier()->CopyFrom(to_proto_key(gr.id()));
			return card;
		}

		DataTypes::FaceCharacteristic
			to_proto_face(const data_model::FaceCharacteristics& gr)
		{
			throw std::exception("to_proto_face Not implemented");
		}

		DataTypes::AccessState
			to_proto_access_state(data_model::AccessState gr)
		{
			switch (gr)
			{
			case data_model::NoneState: 
				return DataTypes::NoneState;
			case data_model::Granted:
				return DataTypes::Granted;
			case data_model::Denied: 
				return DataTypes::Denied;
			default: break;
			}

			throw std::exception("to_proto_access_state Not implemented");
		}

		DataTypes::DateTime
			to_proto_time(const data_model::DateTime& gr)
		{
			DataTypes::DateTime date_time;
			date_time.set_year       (gr.year       ());
			date_time.set_month      (gr.month      ());
			date_time.set_day        (gr.day        ());
			date_time.set_hours      (gr.hours      ());
			date_time.set_minutes    (gr.minutes    ());
			date_time.set_seconds    (gr.seconds    ());
			date_time.set_miliseconds(gr.miliseconds());
			return date_time;
		}

		data_model::CommitResponse
			to_data_commit_response(const DataTypes::CommitResponse& gr)
		{
			data_model::CommitResponse response;
			const auto& results = gr.mutation_results();
			for ( const auto& item : results)			
				response.add(to_data_mutation_result(item));			
			return response;
		}

		data_model::MutationResult
			to_data_mutation_result(const DataTypes::MutationResult& gr)
		{
			return data_model::MutationResult( to_data_model_key(gr.id())
				                               , gr.error());
		}

		void to_message_bytes( const DataTypes::GetRequest& request
			                   , DataTypes::MessageBytes& message)
		{
			request.SerializeToString(message.mutable_data());
			message.set_type(DataTypes::DataType::GetRequestType);
		}

		void to_message_bytes(const DataTypes::CommitRequest& request
			                   , DataTypes::MessageBytes& message)
		{
			std::string bytes;
			request.SerializeToString(&bytes);
			message.set_data(bytes);
			message.set_type(DataTypes::DataType::CommitRequestType);
		}

		DataTypes::HeartbeatMessage
			to_proto_heartbeat_msg(const data_model::HeartbeatMessage& gr)
		{
			DataTypes::HeartbeatMessage heartbeat;
			heartbeat.mutable_id()->CopyFrom(to_proto_key(gr.id));
			heartbeat.set_service_type(to_proto_service_type(gr.type));		
			return heartbeat;
		}

		DataTypes::ServiceType
			to_proto_service_type(data_model::ServiceType service_type)
		{
			switch (service_type)
			{	
			case data_model::ClientService: 
				return DataTypes::ServiceType::Client_Service;			
			case data_model::UnitService:
				return DataTypes::ServiceType::Unit_Service;
			case data_model::FacialService:
				return DataTypes::ServiceType::Facial_Service;
			default: 
				throw std::exception("Argument exception to_proto_service_type");
			}
		}

		DataTypes::ConnectMsg
			to_proto_connect_msg(const data_model::ConnectMsg& gr)
		{
			DataTypes::ConnectMsg cn_msg;
			cn_msg.set_service_type(to_proto_service_type(gr.type));
			cn_msg.mutable_id()->CopyFrom(to_proto_key(gr.id));
			cn_msg.set_ip_address(gr.ip_address);

			return cn_msg;
		}

		DataTypes::DeviceUpdate
			to_proto_device_update(const data_model::DeviceUpdate& gr)
		{
			throw std::exception(" to_proto_device_update not implemented");
		}

		Services::BiometricRequest
			to_proto_biometric_request(const data_model::BiometricRequest& gr)
		{
			throw std::exception(" to_proto_biometric_request not implemented");
		}

		data_model::BiometricResponse
			to_data_biometric_response(const Services::BiometricResponse& gr)
		{
			throw std::exception(" to_data_biometric_response not implemented");
		}

		data_model::FaceTemplate
			to_data_face_template(const DataTypes::FaceCharacteristic& key)
		{
			throw std::exception(" to_data_face_template not implemented");
		}

		DataTypes::Devices
			to_proto_devices(const data_model::Devices& gr)
		{
			DataTypes::Devices devices;
			for (const auto& dev : gr)
			{
				auto proto_dev = devices.add_devices();
				to_proto_device(*proto_dev, dev);
			}
			return devices;
		}


		void to_proto_device( DataTypes::Device& device
			                  , const data_model::Device& dev)
		{
			device.set_serial_number(dev.serial_number());
			device.set_device_type(to_proto_device_type(dev.type()));
			device.set_device_name(dev.name());
		}

		DataTypes::DeviceType 
			to_proto_device_type(data_model::DeviceType dev_type)
		{
			switch (dev_type)
			{
			case data_model::CardReader:
				return DataTypes::DeviceType::CardReader;
			case data_model::Capture: 
				return DataTypes::DeviceType::Capture;
			case data_model::DeviceType::None_Type:
				return DataTypes::DeviceType::None_Type;
			default: 
				throw std::exception("to_proto_device_type argument exception");
			}
		}

		data_model::DeviceType
			to_data_device_type(DataTypes::DeviceType dev_type)
		{
			switch (dev_type)
			{
			case DataTypes::CardReader:
				return data_model::DeviceType::CardReader;
			case DataTypes::Capture:
				return data_model::DeviceType::Capture;
			case DataTypes::DeviceType::None_Type:
				return data_model::DeviceType::None_Type;
			default:
				throw std::exception("to_data_device_type argument exception");
			}
		}

		data_model::FaceTemplate
			to_face_template(const data_model::FaceCharacteristics& item)
		{
			return data_model::FaceTemplate(item.person_id(), item.fir());
		}

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

