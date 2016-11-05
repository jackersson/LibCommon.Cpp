#ifndef LocationDataModel_INCLUDED
#define LocationDataModel_INCLUDED

#include <string>
#include "key.hpp"

namespace data_model
{
	struct AccessDevice
	{
		AccessDevice() : serial_number(0) {}
		explicit AccessDevice(uint16_t sn)
			: serial_number(sn)
		{}
		
		uint16_t serial_number;
	};

	struct CaptureDevice
	{
		CaptureDevice() : device_name("") {}

		explicit CaptureDevice(const std::string& name)
			: device_name(name)
		{}

		std::string device_name;
	};


	struct Location
	{	
		Key           id  ;
		std::string   name;

		std::string   unit_mac_address;
		AccessDevice  access_device   ;
		CaptureDevice capture_device  ;
	};
}

#endif