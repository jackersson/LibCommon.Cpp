#include "repository/face_charst_repository.hpp"

#include <data/models/face_characteristics.hpp>

using namespace data_model;
using namespace contracts::data;

namespace data_core
{
	namespace datacontext
	{		
		FaceCharstRepository::FaceCharstRepository(IDataContext<FaceTemplate>* datacontext)
			: datacontext_(datacontext)
		{
			if (datacontext_ == nullptr)
				throw std::exception("Datacontext can't be null");
		}

		bool FaceCharstRepository::get(const GetRequest& request
			, std::vector<FaceTemplate>& entities) 
		{
			return datacontext_->get(request, entities);
		}

		bool FaceCharstRepository::add(const FaceTemplate& entity) 
		{
			return datacontext_->add(entity);
		}
	}
}

