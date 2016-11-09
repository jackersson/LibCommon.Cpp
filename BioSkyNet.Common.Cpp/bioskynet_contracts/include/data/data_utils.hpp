#ifndef DataUtils_Included
#define DataUtils_Included

#include <data/models/key.hpp>
#include <boost/uuid/uuid.hpp>
#include <common/ifile_io.hpp>

namespace contracts
{
	namespace data
	{	
		bool try_parse_guid( const std::string& value
			                  , boost::uuids::uuid& uid);

		data_model::Key to_data_key(const std::string& guid);		

		std::string uuid_to_string(const boost::uuids::uuid& uid);
	
		std::string get_random_guid();

		boost::uuids::uuid get_random_boost_guid();

		data_model::Key get_random_data_key();

		bool try_load_config(common::IFileIO&);
	
	}
}

#endif
