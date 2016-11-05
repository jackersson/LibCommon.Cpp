#ifndef FaceCharacteristicsDataModel_INCLUDED
#define FaceCharacteristicsDataModel_INCLUDED

#include "key.hpp"
#include "common/geometries.hpp"

namespace data_model
{
	class IFaceCharacteristics
	{
	public:
		virtual ~IFaceCharacteristics() {}

		virtual float confidence() const = 0;

		virtual const contracts::geometries::IBox& bounding_box() const = 0;
	};

	struct FaceCharacteristics
	{
		//FaceCharacteristics() {}

		Key   id        ;
		float confidence;
		//std::string first_name;
		//std::string last_name ;
	};

	struct FaceTemplate
	{
		Key         person_id;
		std::string url      ;
	};



}

#endif