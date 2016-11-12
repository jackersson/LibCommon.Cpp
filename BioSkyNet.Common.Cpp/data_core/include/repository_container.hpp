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
			RepositoryContainer(
				       contracts::data::AbstractDataContextContainer* datacontext);
		
		void init   () override;	
		void de_init() override;

	private:		
		std::unique_ptr<ILocationRepository>	   locations_    ;
		std::unique_ptr<IVisitRecordRepository>  visit_records_;
		std::unique_ptr<IPersonRepository>		   persons_      ;
		std::unique_ptr<IFaceCharstRepository>	 face_charst_  ;

		contracts::data::AbstractDataContextContainer* data_context_;
	};
}

#endif
