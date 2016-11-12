#ifndef RequestAdapters_Included
#define RequestAdapters_Included

namespace Services{
	class BiometricResponse;
	class BiometricRequest;
}

namespace data_model
{
	class Devices;
	class FaceTemplate;
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
	class Devices;
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

		data_model::FaceTemplate 
			to_data_face_template(const DataTypes::FaceCharacteristic& key);

		DataTypes::Devices
			to_proto_devices(const data_model::Devices& gr);
	}
}

#endif
