#include <gtest/gtest.h>
#include <data/models/key.hpp>
#include <data/data_utils.hpp>
#include <uuid/string_generator.hpp>
#include <datatypes/key.pb.h>
#include <helpers/request_adapters.hpp>

namespace data_key_tests
{
	TEST(DataKeyTests, OperatorsTest)
	{
		auto first  = contracts::data::get_random_data_key();
		auto second = contracts::data::get_random_data_key();

		auto fmores = first  > second;
		auto smoref = second > first ;

		EXPECT_NE(fmores, smoref);
	}

	TEST(DataKeyTests, ConversionsTest)
	{
		boost::uuids::string_generator gen;
		auto u1 = gen("{9e7229b7-c22e-4e67-9d92-95751fdece22}");
		data_model::Key key(u1);

		auto proto_key = services_api::helpers::to_proto_key(key);
		auto adapted   = services_api::helpers::to_data_model_key(proto_key);

		EXPECT_EQ(key, adapted);
	}

	TEST(DataKeyTests, GuidDataTest)
	{
		boost::uuids::string_generator gen;
		auto u1 = gen("9e7229b7-c22e-4e67-9d92-95751fdece22");
		for ( auto i : u1.data)
		{
			std::cout << static_cast<int>(i) << std::endl;
		}
		//EXPECT_EQ(key, adapted);
	}

	TEST(DataKeyTests, InsertInSetTest)
	{
		auto total_count = 10;
		std::set<data_model::Key> target_locations_set;

		for (auto i = 0; i < total_count; ++i)
		{
			auto new_key = contracts::data::get_random_data_key();
			EXPECT_EQ(target_locations_set.find(new_key), target_locations_set.end());
			
			target_locations_set.insert(new_key);
		}

		EXPECT_EQ(total_count, target_locations_set.size());
	}
}
