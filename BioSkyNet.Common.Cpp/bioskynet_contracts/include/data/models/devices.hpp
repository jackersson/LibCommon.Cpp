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
	
	class DeviceUpdate
	{

	};
	
	class Device
	{
	public:
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

	class Devices
	{
	public:
		std::vector<Device>::const_iterator begin() const
		{
			return devices_.cbegin();
		}

		std::vector<Device>::const_iterator end() const
		{
			return devices_.cend();
		} 
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

		size_t size() const {
			return devices_.size();
		}

	private:
		Key location_id_;
		std::vector<Device> devices_;
	};	

	class AccessDevice
	{
	public:
		AccessDevice(): serial_number_(0)
		{}

		explicit AccessDevice(uint16_t sn)
			: serial_number_(sn)
		{}

		explicit AccessDevice(const std::string& name)
			: serial_number_(0), name_(name)
		{}

		bool operator==(const AccessDevice& r) const
		{
			return r.name()          == this->name()
			  	&& r.serial_number() == this->serial_number();
		}

		uint16_t serial_number() const {
			return serial_number_;
		}

		const std::string& name() const {
			return name_;
		}

	private:
		uint16_t    serial_number_;
		std::string name_         ;
	};

	class CaptureDevice
	{
	public:
		CaptureDevice() : name_("") {}

		explicit CaptureDevice(const std::string& name)
			: name_(name)
		{}

		bool operator==(const CaptureDevice& r) const
		{
			return r.name() == this->name();
		}

		const std::string& name() const {
			return name_;
		}

	private:
		std::string name_;
	};
}

#endif