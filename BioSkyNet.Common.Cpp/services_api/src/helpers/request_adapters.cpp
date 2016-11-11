#include <helpers/request_adapters.hpp>
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

namespace services_api
{
	namespace helpers
	{
		const int UUID_BYTES_SIZE = 16;
		void set_guid(const boost::uuids::uuid& guid, DataTypes::Key& key)
		{
			unsigned char data[UUID_BYTES_SIZE];
			memcpy(&data, guid.data, UUID_BYTES_SIZE);

			std::string str(data, data + sizeof(data) / sizeof(data[0]));
			key.set_guid(str);
		}

		bool get_guid(const DataTypes::Key& key, boost::uuids::uuid& guid)
		{
			if (key.id_type_case() != DataTypes::Key::IdTypeCase::kGuid)
				return false;

			auto key_guid = key.guid();
			memcpy(&guid, key_guid.data(), UUID_BYTES_SIZE);
			return guid.is_nil();
		}
		
		boost::uuids::uuid get_guid_from_key(const DataTypes::Key& key)
		{
			boost::uuids::uuid uuid;
			get_guid(key, uuid);
			return uuid;
		}
		
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

			proto_entity_request.set_mac_address(gr.mac_address());
			proto_request.mutable_location_request()->CopyFrom(proto_entity_request);
			
			return proto_request;
		}

		DataTypes::GetRequest
			to_proto_get_request(const data_model::GetPersonRequest& gr)
		{
			DataTypes::GetRequest proto_request;
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

			throw std::exception("not implemented");
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
			case DataTypes::Entity::kFace       : break;
			case DataTypes::Entity::VALUE_TYPE_NOT_SET: break;
			default: break;
			}

			throw std::exception("not implemented exception");
		}

		data_model::Location
			to_data_location(const DataTypes::Location& gr)
		{
			data_model::Location location;
			location.set_name          (gr.name());
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

			throw std::exception("Not implemented");
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
				return data_model::Key(get_guid_from_key(key));
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
			throw std::exception("Not implemented");
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

			throw std::exception("Not implemented");
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
			throw std::exception("not implemented");
		}

		DataTypes::ConnectMsg
			to_proto_connect_msg(const data_model::ConnectMsg& gr)
		{
			throw std::exception("not implemented");
		}

		DataTypes::DeviceUpdate
			to_proto_device_update(const data_model::DeviceUpdate& gr)
		{
			throw std::exception("not implemented");
		}

		Services::BiometricRequest
			to_proto_biometric_request(const data_model::BiometricRequest& gr)
		{
			throw std::exception("not implemented");
		}

		data_model::BiometricResponse
			to_data_biometric_response(const Services::BiometricResponse& gr)
		{
			throw std::exception("not implemented");
		}
	}
}

