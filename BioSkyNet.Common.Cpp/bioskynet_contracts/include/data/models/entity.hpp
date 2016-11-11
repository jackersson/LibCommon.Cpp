#ifndef EntityDataModel_INCLUDED
#define EntityDataModel_INCLUDED

#include "visit_record.hpp"
#include "face_characteristics.hpp"
#include "location.hpp"
#include "person.hpp"

namespace data_model
{
	enum EntityType
	{
	  	NoneEntityType
		, EntityPerson
		, EntityVisitRecord
		, EntityLocation
		, EntityFaceCharacteristics
	};

	class Entity
	{
	public:
		Entity() : type_(NoneEntityType) {}

		explicit Entity(const Location& val) : type_(EntityLocation)
			, location_(val)
		{}

		explicit Entity(const VisitRecord& val) : type_(EntityVisitRecord)
			, visit_record_(val)
		{}

		explicit Entity(const Person& val) : type_(EntityPerson)
			, person_(val)
		{}

		explicit Entity(const FaceCharacteristics& val) : type_(EntityFaceCharacteristics)
			, face_(val)
		{}

		EntityType type() const {
			return type_;
		}

		const VisitRecord& visit_record() const {
			return visit_record_;
		}

		const Location& location() const {
			return location_;
		}

		const Person& person() const {
			return person_;
		}

		const FaceCharacteristics& face() const {
			return face_;
		}

	private:
		EntityType          type_;
		FaceCharacteristics face_;
		Location            location_;
		Person              person_;
		VisitRecord         visit_record_;
	};	
}

#endif