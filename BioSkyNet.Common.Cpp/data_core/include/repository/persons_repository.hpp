#ifndef PersonsRepository_Included
#define PersonsRepository_Included

#include <data/irepository.hpp>
#include <data/models/person.hpp>

namespace data_core
{
	namespace datacontext
	{
		class PersonsRepository
			: public contracts::data::IRepository<data_model::Person>
		{
		public:
			explicit
				PersonsRepository(IDataContext<data_model::Person>* datacontext)
				: datacontext_(datacontext)
			{
				if (datacontext_ == nullptr)
					throw std::exception("Datacontext can't be null");
			}

			bool get( const data_model::GetRequest& request
				       , std::vector<data_model::Person>& entities) override
			{
				return datacontext_->get(request, entities);
			}

			bool add(const data_model::Person& entity) override
			{
				return datacontext_->add(entity);
			}		

			contracts::data::ILocalStorage<data_model::Person>&	local() override {
				throw std::exception("Not implemented");
			}

		private:	
			IDataContext<data_model::Person>*    datacontext_;
		};


	}
}

#endif
