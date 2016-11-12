#ifndef DataUtils_Included
#define DataUtils_Included

#include <string>
namespace data_model{
	class Key;
}

namespace contracts
{
	namespace data
	{			
		data_model::Key to_data_key(const std::string& guid);	
		data_model::Key get_random_data_key();
	}
}

#endif
