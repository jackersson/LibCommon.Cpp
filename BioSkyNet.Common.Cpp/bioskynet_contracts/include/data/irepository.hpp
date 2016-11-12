#ifndef IRepository_Included
#define IRepository_Included

#include <common/ilifecycle.hpp>
#include <any.hpp>
#include <vector>
#include <map>

namespace data_model {
	class GetRequest;
}

namespace contracts
{	
	namespace data
	{		
		template <typename TEntity>
		class IDataContext
		{
		public:
			virtual ~IDataContext() {}

			virtual bool get( const data_model::GetRequest& request
				              , std::vector<TEntity>&) = 0;

			virtual bool add(const TEntity& entity) = 0;
		};
	
		template <typename TEntity>
		class IRepository : public IDataContext<TEntity>
		{
		public:
			virtual ~IRepository() {}
		};

	
		class AbstractRepositoryContainer : public common::IModule
		{
		public:
			virtual ~AbstractRepositoryContainer() {}

			template <typename T>
			IRepository<T>* get()
			{
				auto key = typeid(T).hash_code();
				if (container_.find(key) == container_.end())
					return nullptr;
				try
				{
					auto target = boost::any_cast<IRepository<T>*>(container_[key]);
					return target;
				}
				catch (std::exception& )
				{
					//Can't cast
					//TODO handle
					return nullptr;
				}
			}

		protected:
			std::map<size_t, boost::any> container_;

		};

		class AbstractDataContextContainer : public common::IModule
		{
		public:
			virtual ~AbstractDataContextContainer() {}

			template <typename T>
			IDataContext<T>* get()
			{
				auto key = typeid(T).hash_code();
				if (container_.find(key) == container_.end())
					return nullptr;
				auto target = boost::any_cast<IDataContext<T>*>(container_[key]);
				return target;
			}
		protected:
			std::map<size_t, boost::any> container_;
		};
	}
}

#endif
