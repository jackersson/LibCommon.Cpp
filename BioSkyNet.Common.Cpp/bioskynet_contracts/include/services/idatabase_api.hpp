#ifndef IDatabaseApi_INCLUDED
#define IDatabaseApi_INCLUDED

#include <memory>
namespace data_model {
	class GetResponse   ;
	class GetRequest    ;
	class CommitResponse;
	class CommitRequest ;
}

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
