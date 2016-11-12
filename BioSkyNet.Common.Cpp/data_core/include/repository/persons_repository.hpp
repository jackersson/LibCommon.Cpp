#ifndef PersonsRepository_Included
#define PersonsRepository_Included

#include <data/irepository.hpp>

namespace data_model {
	class Person;
}

namespace data_core
{
	namespace datacontext
	{
		class PersonsRepository
			: public contracts::data::IRepository<data_model::Person>
		{
		public:
			explicit
				PersonsRepository(IDataContext<data_model::Person>* datacontext);		

			bool get( const data_model::GetRequest& request
			      	, std::vector<data_model::Person>& entities) override;
		
			bool add(const data_model::Person& entity) override;		

		private:	
			IDataContext<data_model::Person>*    datacontext_;
		};
	}
}

#endif
