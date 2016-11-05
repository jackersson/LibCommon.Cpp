#ifndef IDatabaseApi_INCLUDED
#define IDatabaseApi_INCLUDED

#include <memory>
#include <data/models/commands.hpp>
#include <data/models/queries.hpp>

namespace contracts
{
	namespace services
	{
		class IDatabaseApi
		{
		public:
			virtual ~IDatabaseApi() {}

			virtual std::shared_ptr<data_model::GetResponse>
				get(const data_model::GetRequest& request) = 0;

			virtual std::shared_ptr<data_model::CommitResponse>
				commit(const data_model::CommitRequest& request) = 0;
		};

		typedef std::shared_ptr<IDatabaseApi> IDatabaseApiPtr;
	}
}

#endif
