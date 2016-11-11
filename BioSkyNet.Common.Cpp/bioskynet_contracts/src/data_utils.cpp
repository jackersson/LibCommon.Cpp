#include <data/data_utils.hpp>
#include <data/models/key.hpp>

//#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/string_generator.hpp>

namespace contracts
{
	namespace data
	{
		bool try_parse_guid( const std::string& value
			                  , boost::uuids::uuid& uid)
		{			
			try
			{
				uid = boost::uuids::string_generator()(value);
				return true;
			}
			catch (std::exception&) {
				return false;
			}			
		}

		data_model::Key to_data_key(const std::string& guid)
		{
			boost::uuids::uuid uuid;
			if (!try_parse_guid(guid, uuid))
				return data_model::Key();

			return data_model::Key(uuid);
		}


		//std::string uuid_to_string(const boost::uuids::uuid& uid)
		//{
		//	return to_string(uid);
		//}

		//std::string get_random_guid()
		//{
		//	auto uuid = boost::uuids::random_generator()();
		//	return to_string(uuid);
	//	}

		//boost::uuids::uuid get_random_boost_guid()
		//{
		//	return boost::uuids::random_generator()();
		//}

		data_model::Key get_random_data_key()
		{
			auto uuid = boost::uuids::random_generator()();
			data_model::Key key(uuid);
			return key;
		}		
	}
}
