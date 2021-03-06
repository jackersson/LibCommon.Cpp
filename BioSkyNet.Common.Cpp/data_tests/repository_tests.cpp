#include <gtest/gtest.h>
#include <data/irepository.hpp>

#include <database_service/database_client_data_api.hpp>
#include "testable_database_impl.hpp"
#include <database_service/datacontext/datacontext_container.hpp>
#include <repository_container.hpp>
#include "helpers.hpp"
#include <data/models/card.hpp>
#include <data/models/queries.hpp>

namespace repository_tests
{	
	TEST(RepositoryTests, DataContextContainerTest)
	{
		data_tests::TestableDatabaseApi api;
		services_api::datacontext::DataContextContainer container(&api);
		
		check_data_context<Location>   (&container);
		check_data_context<VisitRecord>(&container);
		check_data_context<Person>     (&container);
		check_data_context<Card>       (&container, false);
		
		container.de_init();
	}
	
	TEST(RepositoryTests, RepositoryContainerTest)
	{
		data_tests::TestableDatabaseApi api;
		services_api::datacontext::DataContextContainer dcontainer(&api);

		data_core::RepositoryContainer container(&dcontainer);

		container.init();

		check_repository<Location>   (&container);
		check_repository<VisitRecord>(&container);
		check_repository<Person>     (&container);
		check_repository<Card>       (&container, false);

		container.de_init();
	}

	void full_location_repository_check
	   ( IRepository<Location>* repository )
	{
		//Should return all locations
		GetLocationRequest all_request;
		get_locations_check(repository, all_request);

		//Should return only locations with specified mac_address
		GetLocationRequest macaddress_request;
		macaddress_request.set_macaddress("305a3a47fd51");
		get_locations_check(repository, macaddress_request);
	}

	TEST(RepositoryCoordinatorTests, GetLocationTest)
	{
		data_tests::CoordinatorDatabaseImpl impl("127.0.0.1:53345");
		auto repository = impl.get<Location>();

		full_location_repository_check(repository);

		impl.stop();
	}

	TEST(RepositoryTests, GetLocationTest)
	{
		data_tests::TestableDatabaseImpl impl("127.0.0.1:49065");
		auto repository = impl.get<Location>();

		full_location_repository_check(repository);

		impl.stop();
	}

	void full_person_repository_check(IRepository<Person>* repository)
	{
		GetPersonRequest all_request;
		all_request.set_card(Card(Key("636150787988765224")));
		get_persons_check(repository, all_request);
	}

	TEST(RepositoryTests, GetPersonTest)
	{
		data_tests::TestableDatabaseImpl impl("127.0.0.1:49065");
		auto repository = impl.get<Person>();	

		full_person_repository_check(repository);
		impl.stop();
	}

	TEST(RepositoryCoordinatorTests, GetPersonTest)
	{
		data_tests::CoordinatorDatabaseImpl impl("127.0.0.1:53345");
		auto repository = impl.get<Person>();

		full_person_repository_check(repository);
		impl.stop();
	}

	void full_visit_record_repository_check( IRepository<Location>* locations
	                                       , IRepository<VisitRecord>* repository)
	{
		auto existingLocation = get_any_location(locations);

		//TODO move from here
		VisitRecord visit_record;
		visit_record.set_now();
		visit_record.set_access_state(Granted);
		visit_record.set_location_id(existingLocation.id());

		Card card(Key("1234 6563 3455 34553"));
		card.set_owner_id(get_random_data_key());
		visit_record.set_card(card);

		add_visit_record_check(repository, visit_record);
	}

	TEST(RepositoryTests, AddVisitorTest)
	{
		data_tests::TestableDatabaseImpl impl("127.0.0.1:49065");
		auto locations_repository = impl.get<Location>();		
		
		auto visitrecords_repository = impl.get<VisitRecord>();
		full_visit_record_repository_check( locations_repository
		                                  , visitrecords_repository);		
		impl.stop();
	}

	TEST(RepositoryCoordinatorTests, AddVisitorTest)
	{
		data_tests::CoordinatorDatabaseImpl impl("127.0.0.1:53345");
		auto locations_repository = impl.get<Location>();

		auto visitrecords_repository = impl.get<VisitRecord>();
		full_visit_record_repository_check(locations_repository
			, visitrecords_repository);
		impl.stop();
	}

	void full_faces_repository_check(IRepository<FaceTemplate>* repository)
	{
		GetFacesRequest all_request;
		get_faces_check(repository, all_request);
	}

	TEST(RepositoryTests, GetFacesTest)
	{
		data_tests::TestableDatabaseImpl impl("127.0.0.1:49065");
		auto repository = impl.get<FaceTemplate>();

		full_faces_repository_check(repository);

		impl.stop();
	}
}
