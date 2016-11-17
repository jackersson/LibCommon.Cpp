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

	class DeviceId
	{
	public:
		DeviceId() : name_("")
			         , serial_number_(0)
		{}

		DeviceId( const DeviceId& device_id)
		{
			name_          = device_id.name();
			serial_number_ = device_id.serial_number();
		}

		explicit DeviceId( const std::string& name
		                 , uint16_t device_id) 
			               : name_(name)
			               , serial_number_(device_id)
		{}

		explicit DeviceId(uint16_t sn) : name_("")
			, serial_number_(sn)
		{}

		explicit DeviceId(const std::string& name) : name_(name)
			, serial_number_(0)
		{}
		
		void set_name(const std::string& device_name) {
			 name_ = device_name;
		}

		const std::string& name() const {
			return name_;
		}

		uint16_t serial_number() const {
			return serial_number_;
		}

		void set_serial_number(uint16_t serial_number) {
			serial_number_ = serial_number;
		}

		bool is_empty() const {
			return name_ == "" && serial_number_ <= 0;
		}

		bool operator==(const DeviceId& rhs) const
		{
			return this->name()          == rhs.name() 
				  && this->serial_number() == rhs.serial_number();
		}

		bool operator>(const DeviceId& rhs) const
		{
			return  this->name()          > rhs.name()
				   && this->serial_number() > rhs.serial_number();
		}

		bool operator<(const DeviceId& rhs) const
		{
			return  this->name()          < rhs.name()
				   && this->serial_number() < rhs.serial_number();
		}

	private:
		std::string name_         ;
		uint16_t    serial_number_;
	};
	
	class Device : public DeviceId
	{
	public:
		Device( const DeviceId& dev
			     , DeviceType type)
			     : DeviceId(dev)
			     , type_(type)
		{}

		Device( const std::string& name
			    , DeviceType type )
			    : DeviceId(name)
			    , type_(type)			   
		{}

		Device( uint16_t serial_number
			    , DeviceType type)
			    : DeviceId(serial_number)
			    , type_(type)
		{}

		DeviceType type() const {
			return type_;
		}

	private:
		DeviceType  type_;		
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

	class AccessDevice : public DeviceId
	{
	public:
		AccessDevice(){}

		explicit AccessDevice(uint16_t sn)
			: DeviceId(sn){}

		explicit AccessDevice(const std::string& name)
			: DeviceId(name){}		
	};

	class CaptureDevice : public DeviceId
	{
	public:
		CaptureDevice() : DeviceId() {}

		explicit CaptureDevice(const std::string& name)
			: DeviceId(name)
		{}
	};
}

#endif