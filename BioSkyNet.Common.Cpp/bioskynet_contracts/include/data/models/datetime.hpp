#ifndef DateTimeDataModel_INCLUDED
#define DateTimeDataModel_INCLUDED

#include <cstdint>
#include <thread/lock_algorithms.hpp>

namespace data_model
{
	//TODO make cpp file
	struct DateTime
	{
		DateTime()
		{
			const auto& now = boost::posix_time::second_clock::local_time();
			const auto& date = now.date();
			set_year (date.year () );
			set_month(date.month() );
			set_day  (date.day  () );
			
			const auto& time_of_date = now.time_of_day();
			set_hours  (time_of_date.hours  ());
			set_minutes(time_of_date.minutes());
			set_seconds(time_of_date.seconds());
		}

		DateTime(  uint32_t year , uint32_t month  , uint32_t day
			       , uint32_t hours, uint32_t minutes, uint32_t seconds
			       , uint32_t miliseconds )
			       : year_ (year) , month_(month)    , day_(day)
			       , hours_(hours), minutes_(minutes), seconds_(seconds)
			       , miliseconds_(miliseconds)
		{			
		}

		void set_year(uint32_t val) {
			year_ = val;
		}

		void set_month(uint32_t val)  {
			month_ = val;
		}

		void set_day(uint32_t val)  {
			day_ = val;
		}

		void set_hours(uint32_t val)  {
			hours_ = val;
		}

		void set_minutes(uint32_t val)  {
			minutes_ = val;
		}

		void set_seconds(uint32_t val)  {
			seconds_ = val;
		}

		void set_miliseconds(uint32_t val) {
			miliseconds_ = val;
		}

		uint32_t year() const {
			return year_;
		}

		uint32_t month() const {
			return month_;
		}

		uint32_t day() const {
			return day_;
		}

		uint32_t hours() const {
			return hours_;
		}

		uint32_t minutes() const {
			return minutes_;
		}

		uint32_t seconds() const {
			return seconds_;
		}

		uint32_t miliseconds() const {
			return miliseconds_;
		}

	private:
		uint32_t year_       ;
		uint32_t month_      ;
		uint32_t day_        ;
		uint32_t hours_      ;
		uint32_t minutes_    ;
		uint32_t seconds_    ;
		uint32_t miliseconds_;
	};



}

#endif