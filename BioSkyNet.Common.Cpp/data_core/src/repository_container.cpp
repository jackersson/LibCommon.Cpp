#include "repository_container.hpp"

#include "repository/location_repository.hpp"
#include "repository/visit_records_repository.hpp"
#include "repository/persons_repository.hpp"
#include "repository/face_charst_repository.hpp"

namespace data_core
{	
	RepositoryContainer::RepositoryContainer(contracts::data::AbstractDataContextContainer* datacontext)
			: data_context_(datacontext)
	{
		if (data_context_ == nullptr)
			throw std::exception("Datacontext can't be null");
	}

	void RepositoryContainer::init()
	{
		auto location_context = data_context_->get<data_model::Location>();
		locations_
			= std::make_unique<datacontext::LocationsRepository>(location_context);
		container_[typeid(data_model::Location).hash_code()] = locations_.get();

		auto visrecor_context = data_context_->get<data_model::VisitRecord>();
		visit_records_
			= std::make_unique<datacontext::VisitRecordsRepository>(visrecor_context);
		container_[typeid(data_model::VisitRecord).hash_code()] = visit_records_.get();

		auto person_context = data_context_->get<data_model::Person>();
		persons_ = std::make_unique<datacontext::PersonsRepository>(person_context);
		container_[typeid(data_model::Person).hash_code()] = persons_.get();

		auto facechars_context = data_context_->get<data_model::FaceTemplate>();
		face_charst_ = std::make_unique<datacontext::FaceCharstRepository>(facechars_context);
		container_[typeid(data_model::FaceTemplate).hash_code()] = face_charst_.get();
	}

	void RepositoryContainer::de_init() {}
}

