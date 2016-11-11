#ifndef DateTimeDataModel_INCLUDED
#define DateTimeDataModel_INCLUDED

#include <cstdint>
namespace data_model
{	
	class DateTime
	{
	public:
		DateTime();

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

		static DateTime now(){
			return DateTime();
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