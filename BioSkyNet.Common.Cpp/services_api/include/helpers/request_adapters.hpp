#ifndef RequestAdapters_Included
#define RequestAdapters_Included

#include <datatypes/commands.pb.h>
#include <datatypes/queries.pb.h>
#include <data/models/queries.hpp>
#include <data/models/location.hpp>
#include <data/models/person.hpp>
#include <data/models/visit_record.hpp>
#include <data/models/face_characteristics.hpp>
#include <data/models/datetime.hpp>
#include <thread/lock_algorithms.hpp>
#include <data/data_utils.hpp>

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
			to_commit_insert(const DataTypes::Entity& gr)
		{
			return DataTypes::CommitRequest();
		}

		inline data_model::FaceTemplate
			to_data_face_template(const DataTypes::FaceCharacteristic& gr)
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
			to_visit_record(const DataTypes::VisitRecord& gr)
		{
			return data_model::VisitRecord();
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

	}
}

#endif
