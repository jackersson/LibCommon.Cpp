#ifndef CommandsDataModel_INCLUDED
#define CommandsDataModel_INCLUDED

#include <string>
#include <vector>
#include "visit_record.hpp"
#include "face_characteristics.hpp"
#include "location.hpp"
#include "person.hpp"

namespace data_model
{
	struct Entity
	{
		FaceCharacteristics face;
		Location            location;
		Person              person;
		VisitRecord         visit_record;

		//TODO implement
		bool has_visit_record() const
		{
			return true;
		}
	};

	struct MutationResult
	{
		Entity      entity;
		std::string error;
	};

	struct Mutation
	{
		Entity inserted;
		Entity updated;
		Entity deleted;
	};

	struct CommitRequest
	{
		std::vector<Mutation> mutations;
	};

	struct CommitResponse
	{
		std::vector<MutationResult> mutations;
	};


	

	struct BiometricRequest
	{

	};

	struct BiometricResponse
	{
	};



}

#endif