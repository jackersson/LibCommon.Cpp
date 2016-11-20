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
		FaceCharacteristics() : confidence_(0) {}

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

		void set_fir_url(const std::string& fir_url){
			fir_url_ = fir_url;
		}

		const std::string& fir() const {
			return fir_url_;
		}

	private:
		Key         id_        ;
		Key         person_id_ ;
		float       confidence_;
		std::string fir_url_   ;	
	};

	class FaceTemplate
	{
	public:
		FaceTemplate(const Key& key,
			           const std::string& temp_url)
			: person_id_(key), url_(temp_url) {}

		const Key&  person_id() const	{
			return person_id_;
		}

		const std::string&  ir() const {
			return url_;
		}

	private:
		Key         person_id_;
		std::string url_      ;
	};



}

#endif