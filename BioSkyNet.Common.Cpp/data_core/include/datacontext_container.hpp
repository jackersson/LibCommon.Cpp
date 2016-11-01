#ifndef DataContextContainer_Included
#define DataContextContainer_Included

#include <data/irepository.hpp>

#include "datacontext/locations_data_context.hpp"
#include "datacontext/visit_records_datacontext.hpp"
#include "datacontext/persons_data_context.hpp"
#include <any.hpp>

namespace data_core
{
	class DataContextContainer : public contracts::data::AbstractDataContextContainer	
	{		
	public:
		explicit DataContextContainer(contracts::services::IDatabaseApi* api)
			: api_(api)
		{}

		void init() override
		{
			locations_     = std::make_unique<datacontext::LocationsDataContext>(api_);
			container_[typeid(DataTypes::Location).hash_code()] = locations_.get();

			visit_records_ = std::make_unique<datacontext::VisitRecordsDataContext>(api_);
			container_[typeid(DataTypes::VisitRecord).hash_code()] = visit_records_.get();

			persons_       = std::make_unique<datacontext::PersonsDataContext>(api_);
			container_[typeid(DataTypes::Person).hash_code()] = persons_.get();
		}

		void de_init() override
		{}		
		
	private:
		contracts::services::IDatabaseApi* api_;
		std::unique_ptr<contracts::data::IDataContext<DataTypes::Location>> locations_;
		std::unique_ptr<contracts::data::IDataContext<DataTypes::VisitRecord>> visit_records_;
		std::unique_ptr<contracts::data::IDataContext<DataTypes::Person>> persons_;
		
		//std::map<size_t, boost::any> container_;

	};
}

#endif
