#ifndef FaceCharstRepository_Included
#define FaceCharstRepository_Included

#include <data/irepository.hpp>
#include <data/models/face_characteristics.hpp>
//namespace data_model {
	//class FaceTemplate;
//}

namespace data_core
{
	namespace datacontext
	{
		class FaceCharstRepository
			: public contracts::data::IRepository<data_model::FaceTemplate>
		{
		public:
			explicit
				FaceCharstRepository(IDataContext<data_model::FaceTemplate>* datacontext)
				  : datacontext_(datacontext)
			{
				if (datacontext_ == nullptr)
					throw std::exception("Datacontext can't be null");
			}

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::FaceTemplate>& entities) override
			{
				return datacontext_->get(request, entities);
			}
					
			bool add(const data_model::FaceTemplate& entity) override
			{
				return datacontext_->add(entity);
			}
					
			contracts::data::ILocalStorage<data_model::FaceTemplate>&	local() override {
				throw std::exception("Not implemented exception");
			}

		private:
			IDataContext<data_model::FaceTemplate>*    datacontext_;
		};


	}
}

#endif
