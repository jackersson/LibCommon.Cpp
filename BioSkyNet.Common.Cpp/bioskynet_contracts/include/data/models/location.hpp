#ifndef LocationDataModel_INCLUDED
#define LocationDataModel_INCLUDED

#include <string>
#include "key.hpp"
#include "devices.hpp"
namespace data_model
{
	class Location
	{	
	public:
		void set_id(const Key& val) {
			id_ = val;
		}

		const Key& id() const {
			return id_;
		}

		void set_name(const std::string& val) {
			name_ = val;
		}

		const std::string& name() const {
			return name_;
		}

		void set_unit_mac_address(const std::string& val) {
			unit_mac_address_ = val;
		}

		const std::string& unit_mac_address() const {
			return unit_mac_address_;
		}

		void set_access_device(const AccessDevice& val) {
			access_device_ = val;
		}

		const AccessDevice& access_device() const {
			return access_device_;
		}

		void set_capture_device(const CaptureDevice& val) {
			capture_device_ = val;
		}

		const CaptureDevice& capture_device() const {
			return capture_device_;
		}

		bool operator==(const Location& r) const
		{
			return r.name()             == this->name()
				  && r.unit_mac_address() == this->unit_mac_address()
				  && r.id()               == this->id()
				  && r.access_device()    == this->access_device()
				  && r.capture_device()   == this->capture_device();
		}

	private:
		Key           id_  ;
		std::string   name_;

		std::string   unit_mac_address_;
		AccessDevice  access_device_   ;
		CaptureDevice capture_device_  ;
	};
}

#endif