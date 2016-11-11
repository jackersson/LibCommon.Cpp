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

	class FaceCharacteristics
	{
	public:		
		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		}

		void set_person_id(const Key& val) {
			person_id_ = val;
		}

		const Key& person_id() const {
			return person_id_;
		}

		void set_confidence(float val) {
			confidence_ = val;
		}

		float confidence() const {
			return confidence_;
		}

	private:
		Key   id_        ;
		Key   person_id_ ;
		float confidence_;
		//std::string first_name;
		//std::string last_name ;
	};

	class FaceTemplate
	{
		//FaceTemplate(const data_model::Key& key, const std::string& temp_url)
			//: person_id(key), url(temp_url) {}

		Key         person_id;
		std::string url      ;
	};



}

#endif