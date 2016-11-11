#ifndef LocationsRepository_Included
#define LocationsRepository_Included

#include <data/irepository.hpp>
//#include <data/models/location.hpp>

namespace data_model {
	class Location;
}

namespace data_core
{
	namespace datacontext
	{
		class LocationsRepository
			: public contracts::data::IRepository<data_model::Location>
		{
		public:
			explicit
				LocationsRepository(IDataContext<data_model::Location>* datacontext);
				//: datacontext_(datacontext)
			//{
			//	if (datacontext_ == nullptr)
			//		throw std::exception("Datacontext can't be null");
			//}

			bool get(const data_model::GetRequest& request
				, std::vector<data_model::Location>& entities) override;
			//{
		//		return datacontext_->get(request, entities);
			//}
						
			bool add(const data_model::Location& entity) override;// {
			//	return datacontext_->add(entity);
			//}					

		private:
			IDataContext<data_model::Location>* datacontext_;
		};


	}
}

#endif
