// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datatypes/location.proto

#ifndef PROTOBUF_datatypes_2flocation_2eproto__INCLUDED
#define PROTOBUF_datatypes_2flocation_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "datatypes/devices.pb.h"
#include "datatypes/key.pb.h"
// @@protoc_insertion_point(includes)

namespace DataTypes {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_datatypes_2flocation_2eproto();
void protobuf_AssignDesc_datatypes_2flocation_2eproto();
void protobuf_ShutdownFile_datatypes_2flocation_2eproto();

class Location;
class LocationUpdate;
class LocationUpdates;

// ===================================================================

class Location : public ::google::protobuf::Message {
 public:
  Location();
  virtual ~Location();

  Location(const Location& from);

  inline Location& operator=(const Location& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Location& default_instance();

  void Swap(Location* other);

  // implements Message ----------------------------------------------

  inline Location* New() const { return New(NULL); }

  Location* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Location& from);
  void MergeFrom(const Location& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Location* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .DataTypes.Key id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  const ::DataTypes::Key& id() const;
  ::DataTypes::Key* mutable_id();
  ::DataTypes::Key* release_id();
  void set_allocated_id(::DataTypes::Key* id);

  // optional string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string description = 3;
  void clear_description();
  static const int kDescriptionFieldNumber = 3;
  const ::std::string& description() const;
  void set_description(const ::std::string& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  ::std::string* mutable_description();
  ::std::string* release_description();
  void set_allocated_description(::std::string* description);

  // optional string unit_mac_address = 4;
  void clear_unit_mac_address();
  static const int kUnitMacAddressFieldNumber = 4;
  const ::std::string& unit_mac_address() const;
  void set_unit_mac_address(const ::std::string& value);
  void set_unit_mac_address(const char* value);
  void set_unit_mac_address(const char* value, size_t size);
  ::std::string* mutable_unit_mac_address();
  ::std::string* release_unit_mac_address();
  void set_allocated_unit_mac_address(::std::string* unit_mac_address);

  // optional .DataTypes.AccessDevice access_device = 5;
  bool has_access_device() const;
  void clear_access_device();
  static const int kAccessDeviceFieldNumber = 5;
  const ::DataTypes::AccessDevice& access_device() const;
  ::DataTypes::AccessDevice* mutable_access_device();
  ::DataTypes::AccessDevice* release_access_device();
  void set_allocated_access_device(::DataTypes::AccessDevice* access_device);

  // optional .DataTypes.CaptureDevice capture_device = 6;
  bool has_capture_device() const;
  void clear_capture_device();
  static const int kCaptureDeviceFieldNumber = 6;
  const ::DataTypes::CaptureDevice& capture_device() const;
  ::DataTypes::CaptureDevice* mutable_capture_device();
  ::DataTypes::CaptureDevice* release_capture_device();
  void set_allocated_capture_device(::DataTypes::CaptureDevice* capture_device);

  // @@protoc_insertion_point(class_scope:DataTypes.Location)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::DataTypes::Key* id_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr description_;
  ::google::protobuf::internal::ArenaStringPtr unit_mac_address_;
  ::DataTypes::AccessDevice* access_device_;
  ::DataTypes::CaptureDevice* capture_device_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_datatypes_2flocation_2eproto();
  friend void protobuf_AssignDesc_datatypes_2flocation_2eproto();
  friend void protobuf_ShutdownFile_datatypes_2flocation_2eproto();

  void InitAsDefaultInstance();
  static Location* default_instance_;
};
// -------------------------------------------------------------------

class LocationUpdate : public ::google::protobuf::Message {
 public:
  LocationUpdate();
  virtual ~LocationUpdate();

  LocationUpdate(const LocationUpdate& from);

  inline LocationUpdate& operator=(const LocationUpdate& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LocationUpdate& default_instance();

  enum UpdateTypeCase {
    kInserted = 1,
    kDeleted = 2,
    kUpdated = 3,
    UPDATE_TYPE_NOT_SET = 0,
  };

  void Swap(LocationUpdate* other);

  // implements Message ----------------------------------------------

  inline LocationUpdate* New() const { return New(NULL); }

  LocationUpdate* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LocationUpdate& from);
  void MergeFrom(const LocationUpdate& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(LocationUpdate* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .DataTypes.Location inserted = 1;
  bool has_inserted() const;
  void clear_inserted();
  static const int kInsertedFieldNumber = 1;
  const ::DataTypes::Location& inserted() const;
  ::DataTypes::Location* mutable_inserted();
  ::DataTypes::Location* release_inserted();
  void set_allocated_inserted(::DataTypes::Location* inserted);

  // optional .DataTypes.Location deleted = 2;
  bool has_deleted() const;
  void clear_deleted();
  static const int kDeletedFieldNumber = 2;
  const ::DataTypes::Location& deleted() const;
  ::DataTypes::Location* mutable_deleted();
  ::DataTypes::Location* release_deleted();
  void set_allocated_deleted(::DataTypes::Location* deleted);

  // optional .DataTypes.Location updated = 3;
  bool has_updated() const;
  void clear_updated();
  static const int kUpdatedFieldNumber = 3;
  const ::DataTypes::Location& updated() const;
  ::DataTypes::Location* mutable_updated();
  ::DataTypes::Location* release_updated();
  void set_allocated_updated(::DataTypes::Location* updated);

  UpdateTypeCase update_type_case() const;
  // @@protoc_insertion_point(class_scope:DataTypes.LocationUpdate)
 private:
  inline void set_has_inserted();
  inline void set_has_deleted();
  inline void set_has_updated();

  inline bool has_update_type() const;
  void clear_update_type();
  inline void clear_has_update_type();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  union UpdateTypeUnion {
    UpdateTypeUnion() {}
    ::DataTypes::Location* inserted_;
    ::DataTypes::Location* deleted_;
    ::DataTypes::Location* updated_;
  } update_type_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend void  protobuf_AddDesc_datatypes_2flocation_2eproto();
  friend void protobuf_AssignDesc_datatypes_2flocation_2eproto();
  friend void protobuf_ShutdownFile_datatypes_2flocation_2eproto();

  void InitAsDefaultInstance();
  static LocationUpdate* default_instance_;
};
// -------------------------------------------------------------------

class LocationUpdates : public ::google::protobuf::Message {
 public:
  LocationUpdates();
  virtual ~LocationUpdates();

  LocationUpdates(const LocationUpdates& from);

  inline LocationUpdates& operator=(const LocationUpdates& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LocationUpdates& default_instance();

  void Swap(LocationUpdates* other);

  // implements Message ----------------------------------------------

  inline LocationUpdates* New() const { return New(NULL); }

  LocationUpdates* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LocationUpdates& from);
  void MergeFrom(const LocationUpdates& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(LocationUpdates* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .DataTypes.LocationUpdate items = 1;
  int items_size() const;
  void clear_items();
  static const int kItemsFieldNumber = 1;
  const ::DataTypes::LocationUpdate& items(int index) const;
  ::DataTypes::LocationUpdate* mutable_items(int index);
  ::DataTypes::LocationUpdate* add_items();
  ::google::protobuf::RepeatedPtrField< ::DataTypes::LocationUpdate >*
      mutable_items();
  const ::google::protobuf::RepeatedPtrField< ::DataTypes::LocationUpdate >&
      items() const;

  // @@protoc_insertion_point(class_scope:DataTypes.LocationUpdates)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::DataTypes::LocationUpdate > items_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_datatypes_2flocation_2eproto();
  friend void protobuf_AssignDesc_datatypes_2flocation_2eproto();
  friend void protobuf_ShutdownFile_datatypes_2flocation_2eproto();

  void InitAsDefaultInstance();
  static LocationUpdates* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Location

// optional .DataTypes.Key id = 1;
inline bool Location::has_id() const {
  return !_is_default_instance_ && id_ != NULL;
}
inline void Location::clear_id() {
  if (GetArenaNoVirtual() == NULL && id_ != NULL) delete id_;
  id_ = NULL;
}
inline const ::DataTypes::Key& Location::id() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.id)
  return id_ != NULL ? *id_ : *default_instance_->id_;
}
inline ::DataTypes::Key* Location::mutable_id() {
  
  if (id_ == NULL) {
    id_ = new ::DataTypes::Key;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.id)
  return id_;
}
inline ::DataTypes::Key* Location::release_id() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.id)
  
  ::DataTypes::Key* temp = id_;
  id_ = NULL;
  return temp;
}
inline void Location::set_allocated_id(::DataTypes::Key* id) {
  delete id_;
  id_ = id;
  if (id) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.id)
}

// optional string name = 2;
inline void Location::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Location::name() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DataTypes.Location.name)
}
inline void Location::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DataTypes.Location.name)
}
inline void Location::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DataTypes.Location.name)
}
inline ::std::string* Location::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Location::release_name() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.name)
}

// optional string description = 3;
inline void Location::clear_description() {
  description_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Location::description() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.description)
  return description_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_description(const ::std::string& value) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DataTypes.Location.description)
}
inline void Location::set_description(const char* value) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DataTypes.Location.description)
}
inline void Location::set_description(const char* value, size_t size) {
  
  description_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DataTypes.Location.description)
}
inline ::std::string* Location::mutable_description() {
  
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.description)
  return description_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Location::release_description() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.description)
  
  return description_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_allocated_description(::std::string* description) {
  if (description != NULL) {
    
  } else {
    
  }
  description_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), description);
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.description)
}

// optional string unit_mac_address = 4;
inline void Location::clear_unit_mac_address() {
  unit_mac_address_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Location::unit_mac_address() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.unit_mac_address)
  return unit_mac_address_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_unit_mac_address(const ::std::string& value) {
  
  unit_mac_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DataTypes.Location.unit_mac_address)
}
inline void Location::set_unit_mac_address(const char* value) {
  
  unit_mac_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DataTypes.Location.unit_mac_address)
}
inline void Location::set_unit_mac_address(const char* value, size_t size) {
  
  unit_mac_address_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DataTypes.Location.unit_mac_address)
}
inline ::std::string* Location::mutable_unit_mac_address() {
  
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.unit_mac_address)
  return unit_mac_address_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Location::release_unit_mac_address() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.unit_mac_address)
  
  return unit_mac_address_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Location::set_allocated_unit_mac_address(::std::string* unit_mac_address) {
  if (unit_mac_address != NULL) {
    
  } else {
    
  }
  unit_mac_address_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), unit_mac_address);
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.unit_mac_address)
}

// optional .DataTypes.AccessDevice access_device = 5;
inline bool Location::has_access_device() const {
  return !_is_default_instance_ && access_device_ != NULL;
}
inline void Location::clear_access_device() {
  if (GetArenaNoVirtual() == NULL && access_device_ != NULL) delete access_device_;
  access_device_ = NULL;
}
inline const ::DataTypes::AccessDevice& Location::access_device() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.access_device)
  return access_device_ != NULL ? *access_device_ : *default_instance_->access_device_;
}
inline ::DataTypes::AccessDevice* Location::mutable_access_device() {
  
  if (access_device_ == NULL) {
    access_device_ = new ::DataTypes::AccessDevice;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.access_device)
  return access_device_;
}
inline ::DataTypes::AccessDevice* Location::release_access_device() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.access_device)
  
  ::DataTypes::AccessDevice* temp = access_device_;
  access_device_ = NULL;
  return temp;
}
inline void Location::set_allocated_access_device(::DataTypes::AccessDevice* access_device) {
  delete access_device_;
  access_device_ = access_device;
  if (access_device) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.access_device)
}

// optional .DataTypes.CaptureDevice capture_device = 6;
inline bool Location::has_capture_device() const {
  return !_is_default_instance_ && capture_device_ != NULL;
}
inline void Location::clear_capture_device() {
  if (GetArenaNoVirtual() == NULL && capture_device_ != NULL) delete capture_device_;
  capture_device_ = NULL;
}
inline const ::DataTypes::CaptureDevice& Location::capture_device() const {
  // @@protoc_insertion_point(field_get:DataTypes.Location.capture_device)
  return capture_device_ != NULL ? *capture_device_ : *default_instance_->capture_device_;
}
inline ::DataTypes::CaptureDevice* Location::mutable_capture_device() {
  
  if (capture_device_ == NULL) {
    capture_device_ = new ::DataTypes::CaptureDevice;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Location.capture_device)
  return capture_device_;
}
inline ::DataTypes::CaptureDevice* Location::release_capture_device() {
  // @@protoc_insertion_point(field_release:DataTypes.Location.capture_device)
  
  ::DataTypes::CaptureDevice* temp = capture_device_;
  capture_device_ = NULL;
  return temp;
}
inline void Location::set_allocated_capture_device(::DataTypes::CaptureDevice* capture_device) {
  delete capture_device_;
  capture_device_ = capture_device;
  if (capture_device) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Location.capture_device)
}

// -------------------------------------------------------------------

// LocationUpdate

// optional .DataTypes.Location inserted = 1;
inline bool LocationUpdate::has_inserted() const {
  return update_type_case() == kInserted;
}
inline void LocationUpdate::set_has_inserted() {
  _oneof_case_[0] = kInserted;
}
inline void LocationUpdate::clear_inserted() {
  if (has_inserted()) {
    delete update_type_.inserted_;
    clear_has_update_type();
  }
}
inline  const ::DataTypes::Location& LocationUpdate::inserted() const {
  // @@protoc_insertion_point(field_get:DataTypes.LocationUpdate.inserted)
  return has_inserted()
      ? *update_type_.inserted_
      : ::DataTypes::Location::default_instance();
}
inline ::DataTypes::Location* LocationUpdate::mutable_inserted() {
  if (!has_inserted()) {
    clear_update_type();
    set_has_inserted();
    update_type_.inserted_ = new ::DataTypes::Location;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.LocationUpdate.inserted)
  return update_type_.inserted_;
}
inline ::DataTypes::Location* LocationUpdate::release_inserted() {
  // @@protoc_insertion_point(field_release:DataTypes.LocationUpdate.inserted)
  if (has_inserted()) {
    clear_has_update_type();
    ::DataTypes::Location* temp = update_type_.inserted_;
    update_type_.inserted_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void LocationUpdate::set_allocated_inserted(::DataTypes::Location* inserted) {
  clear_update_type();
  if (inserted) {
    set_has_inserted();
    update_type_.inserted_ = inserted;
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.LocationUpdate.inserted)
}

// optional .DataTypes.Location deleted = 2;
inline bool LocationUpdate::has_deleted() const {
  return update_type_case() == kDeleted;
}
inline void LocationUpdate::set_has_deleted() {
  _oneof_case_[0] = kDeleted;
}
inline void LocationUpdate::clear_deleted() {
  if (has_deleted()) {
    delete update_type_.deleted_;
    clear_has_update_type();
  }
}
inline  const ::DataTypes::Location& LocationUpdate::deleted() const {
  // @@protoc_insertion_point(field_get:DataTypes.LocationUpdate.deleted)
  return has_deleted()
      ? *update_type_.deleted_
      : ::DataTypes::Location::default_instance();
}
inline ::DataTypes::Location* LocationUpdate::mutable_deleted() {
  if (!has_deleted()) {
    clear_update_type();
    set_has_deleted();
    update_type_.deleted_ = new ::DataTypes::Location;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.LocationUpdate.deleted)
  return update_type_.deleted_;
}
inline ::DataTypes::Location* LocationUpdate::release_deleted() {
  // @@protoc_insertion_point(field_release:DataTypes.LocationUpdate.deleted)
  if (has_deleted()) {
    clear_has_update_type();
    ::DataTypes::Location* temp = update_type_.deleted_;
    update_type_.deleted_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void LocationUpdate::set_allocated_deleted(::DataTypes::Location* deleted) {
  clear_update_type();
  if (deleted) {
    set_has_deleted();
    update_type_.deleted_ = deleted;
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.LocationUpdate.deleted)
}

// optional .DataTypes.Location updated = 3;
inline bool LocationUpdate::has_updated() const {
  return update_type_case() == kUpdated;
}
inline void LocationUpdate::set_has_updated() {
  _oneof_case_[0] = kUpdated;
}
inline void LocationUpdate::clear_updated() {
  if (has_updated()) {
    delete update_type_.updated_;
    clear_has_update_type();
  }
}
inline  const ::DataTypes::Location& LocationUpdate::updated() const {
  // @@protoc_insertion_point(field_get:DataTypes.LocationUpdate.updated)
  return has_updated()
      ? *update_type_.updated_
      : ::DataTypes::Location::default_instance();
}
inline ::DataTypes::Location* LocationUpdate::mutable_updated() {
  if (!has_updated()) {
    clear_update_type();
    set_has_updated();
    update_type_.updated_ = new ::DataTypes::Location;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.LocationUpdate.updated)
  return update_type_.updated_;
}
inline ::DataTypes::Location* LocationUpdate::release_updated() {
  // @@protoc_insertion_point(field_release:DataTypes.LocationUpdate.updated)
  if (has_updated()) {
    clear_has_update_type();
    ::DataTypes::Location* temp = update_type_.updated_;
    update_type_.updated_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void LocationUpdate::set_allocated_updated(::DataTypes::Location* updated) {
  clear_update_type();
  if (updated) {
    set_has_updated();
    update_type_.updated_ = updated;
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.LocationUpdate.updated)
}

inline bool LocationUpdate::has_update_type() const {
  return update_type_case() != UPDATE_TYPE_NOT_SET;
}
inline void LocationUpdate::clear_has_update_type() {
  _oneof_case_[0] = UPDATE_TYPE_NOT_SET;
}
inline LocationUpdate::UpdateTypeCase LocationUpdate::update_type_case() const {
  return LocationUpdate::UpdateTypeCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// LocationUpdates

// repeated .DataTypes.LocationUpdate items = 1;
inline int LocationUpdates::items_size() const {
  return items_.size();
}
inline void LocationUpdates::clear_items() {
  items_.Clear();
}
inline const ::DataTypes::LocationUpdate& LocationUpdates::items(int index) const {
  // @@protoc_insertion_point(field_get:DataTypes.LocationUpdates.items)
  return items_.Get(index);
}
inline ::DataTypes::LocationUpdate* LocationUpdates::mutable_items(int index) {
  // @@protoc_insertion_point(field_mutable:DataTypes.LocationUpdates.items)
  return items_.Mutable(index);
}
inline ::DataTypes::LocationUpdate* LocationUpdates::add_items() {
  // @@protoc_insertion_point(field_add:DataTypes.LocationUpdates.items)
  return items_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::DataTypes::LocationUpdate >*
LocationUpdates::mutable_items() {
  // @@protoc_insertion_point(field_mutable_list:DataTypes.LocationUpdates.items)
  return &items_;
}
inline const ::google::protobuf::RepeatedPtrField< ::DataTypes::LocationUpdate >&
LocationUpdates::items() const {
  // @@protoc_insertion_point(field_list:DataTypes.LocationUpdates.items)
  return items_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace DataTypes

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_datatypes_2flocation_2eproto__INCLUDED
