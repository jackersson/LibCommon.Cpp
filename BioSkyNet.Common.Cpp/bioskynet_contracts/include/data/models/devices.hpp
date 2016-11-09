#ifndef DevicesDataModel_INCLUDED
#define DevicesDataModel_INCLUDED

#include <string>
#include <vector>
#include "key.hpp"

namespace data_model
{

	enum DeviceType
	{
	  	None_Type
		, CardReader
		, Capture
	};


	enum DeviceState
	{
		  None_State
		, Active
		, StoppedByUser
		, Paused
		, Stopped
		, Error
	};


	struct DeviceUpdate
	{

	};


	struct Device
	{
		Device( const std::string& name
			    , DeviceType type )
			    : type_(type)
			    , name_(name)
		{}

		const std::string& name() const	{
			return name_;
		}

		DeviceType type() const {
			return type_;
		}

	private:
		DeviceType  type_;
		std::string name_;
	};

	struct Devices
	{
		const Key& location_id() const {
			return location_id_;
		}

		void set_location_id(const Key& val)  {
			location_id_ = val;
		}

		void add(const Device& device){
			devices_.push_back(device);
		}

		void clear(){
			devices_.clear();
		}

	private:
		Key location_id_;
		std::vector<Device> devices_;
	};

	

	struct AccessDevice
	{
		AccessDevice() : serial_number(0) {}
		explicit AccessDevice(uint16_t sn)
			: serial_number(sn)
		{}

		bool operator==(const AccessDevice& r) const
		{
			return r.name          == this->name
			  	&& r.serial_number == this->serial_number;
		}

		uint16_t serial_number;
		std::string name;

	};

	struct CaptureDevice
	{
		CaptureDevice() : name("") {}

		explicit CaptureDevice(const std::string& name)
			: name(name)
		{}

		bool operator==(const CaptureDevice& r) const
		{
			return r.name == this->name;
		}

		std::string name;
	};
}

#endif