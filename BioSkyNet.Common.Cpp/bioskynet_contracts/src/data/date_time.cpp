#include <data/models/datetime.hpp>
#include <thread/lock_algorithms.hpp>

namespace data_model
{
	DateTime::DateTime()
	{
		const auto& now  = boost::posix_time::second_clock::local_time();
		const auto& date = now.date();
		set_year (date.year());
		set_month(date.month());
		set_day  (date.day());

		const auto& time_of_date = now.time_of_day();
		set_hours  (time_of_date.hours());
		set_minutes(time_of_date.minutes());
		set_seconds(time_of_date.seconds());
	}

	std::string DateTime::to_string() const
	{
		std::stringstream st;
	
		st << hours() << ":" << minutes() << ":" << seconds() << " "
		   << day() << "/" << month() << "/" << year();

		return st.str();
	} 
	
}
