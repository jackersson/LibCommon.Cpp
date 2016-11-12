#ifndef FaceCharstRepository_Included
#define FaceCharstRepository_Included

#include <data/irepository.hpp>
namespace data_model {
	class FaceTemplate;
}

namespace data_core
{
	namespace datacontext
	{
		class FaceCharstRepository
			: public contracts::data::IRepository<data_model::FaceTemplate>
		{
		public:
			explicit
				FaceCharstRepository(IDataContext<data_model::FaceTemplate>* datacontext);
			

			bool get( const data_model::GetRequest& request
				      , std::vector<data_model::FaceTemplate>& entities) override;		
					
			bool add(const data_model::FaceTemplate& entity) override;				

		private:
			IDataContext<data_model::FaceTemplate>*    datacontext_;
		};
	}
}

#endif
