#ifndef RepositoryContainer_Included
#define RepositoryContainer_Included

#include <data/irepository.hpp>
#include <memory>

namespace data_model {
	class VisitRecord ;
	class Location    ;
	class Person      ;
	class FaceTemplate;
}

namespace data_core
{		
	class RepositoryContainer	: public contracts::data::AbstractRepositoryContainer
	{
		typedef contracts::data::IRepository<data_model::VisitRecord> IVisitRecordRepository;
		typedef contracts::data::IRepository<data_model::Location>  	ILocationRepository;
		typedef contracts::data::IRepository<data_model::Person>	    IPersonRepository;
		typedef 
			contracts::data::IRepository<data_model::FaceTemplate>  IFaceCharstRepository;
	public:	
		explicit
			RepositoryContainer(contracts::data::AbstractDataContextContainer* datacontext);
			//: data_context_(datacontext)
	//	{
		//	if (data_context_ == nullptr)
		//		throw std::exception("Datacontext can't be null");
	//	}

		void init() override;
	/*	{	
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
			container_[typeid(data_model::FaceTemplate).hash_code()] = persons_.get();
		}
		*/
		void de_init() override;// {}

	private:		
		std::unique_ptr<ILocationRepository>	   locations_    ;
		std::unique_ptr<IVisitRecordRepository>  visit_records_;
		std::unique_ptr<IPersonRepository>		   persons_      ;
		std::unique_ptr<IFaceCharstRepository>	 face_charst_  ;

		contracts::data::AbstractDataContextContainer* data_context_;
	};
}

#endif
