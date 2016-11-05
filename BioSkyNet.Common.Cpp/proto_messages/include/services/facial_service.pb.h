// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: services/facial_service.proto

#ifndef PROTOBUF_services_2ffacial_5fservice_2eproto__INCLUDED
#define PROTOBUF_services_2ffacial_5fservice_2eproto__INCLUDED

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
#include "datatypes/photo.pb.h"
#include "datatypes/key.pb.h"
#include "datatypes/biometrics.pb.h"
#include <google/protobuf/empty.pb.h>
// @@protoc_insertion_point(includes)

namespace Services {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_services_2ffacial_5fservice_2eproto();
void protobuf_AssignDesc_services_2ffacial_5fservice_2eproto();
void protobuf_ShutdownFile_services_2ffacial_5fservice_2eproto();

class BiometricRequest;
class BiometricResponse;
class BiometricUpdate;

// ===================================================================

class BiometricRequest : public ::google::protobuf::Message {
 public:
  BiometricRequest();
  virtual ~BiometricRequest();

  BiometricRequest(const BiometricRequest& from);

  inline BiometricRequest& operator=(const BiometricRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BiometricRequest& default_instance();

  void Swap(BiometricRequest* other);

  // implements Message ----------------------------------------------

  inline BiometricRequest* New() const { return New(NULL); }

  BiometricRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BiometricRequest& from);
  void MergeFrom(const BiometricRequest& from);
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
  void InternalSwap(BiometricRequest* other);
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

  // optional .DataTypes.FrameBytes frame = 1;
  bool has_frame() const;
  void clear_frame();
  static const int kFrameFieldNumber = 1;
  const ::DataTypes::FrameBytes& frame() const;
  ::DataTypes::FrameBytes* mutable_frame();
  ::DataTypes::FrameBytes* release_frame();
  void set_allocated_frame(::DataTypes::FrameBytes* frame);

  // optional .DataTypes.Key person = 2;
  bool has_person() const;
  void clear_person();
  static const int kPersonFieldNumber = 2;
  const ::DataTypes::Key& person() const;
  ::DataTypes::Key* mutable_person();
  ::DataTypes::Key* release_person();
  void set_allocated_person(::DataTypes::Key* person);

  // optional .DataTypes.BioActionType action = 3;
  void clear_action();
  static const int kActionFieldNumber = 3;
  ::DataTypes::BioActionType action() const;
  void set_action(::DataTypes::BioActionType value);

  // optional .DataTypes.BiometricType type = 4;
  void clear_type();
  static const int kTypeFieldNumber = 4;
  ::DataTypes::BiometricType type() const;
  void set_type(::DataTypes::BiometricType value);

  // @@protoc_insertion_point(class_scope:Services.BiometricRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::DataTypes::FrameBytes* frame_;
  ::DataTypes::Key* person_;
  int action_;
  int type_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_AssignDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_ShutdownFile_services_2ffacial_5fservice_2eproto();

  void InitAsDefaultInstance();
  static BiometricRequest* default_instance_;
};
// -------------------------------------------------------------------

class BiometricResponse : public ::google::protobuf::Message {
 public:
  BiometricResponse();
  virtual ~BiometricResponse();

  BiometricResponse(const BiometricResponse& from);

  inline BiometricResponse& operator=(const BiometricResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BiometricResponse& default_instance();

  void Swap(BiometricResponse* other);

  // implements Message ----------------------------------------------

  inline BiometricResponse* New() const { return New(NULL); }

  BiometricResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BiometricResponse& from);
  void MergeFrom(const BiometricResponse& from);
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
  void InternalSwap(BiometricResponse* other);
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

  // optional .DataTypes.Photo photo = 1;
  bool has_photo() const;
  void clear_photo();
  static const int kPhotoFieldNumber = 1;
  const ::DataTypes::Photo& photo() const;
  ::DataTypes::Photo* mutable_photo();
  ::DataTypes::Photo* release_photo();
  void set_allocated_photo(::DataTypes::Photo* photo);

  // optional .DataTypes.Matches matches = 2;
  bool has_matches() const;
  void clear_matches();
  static const int kMatchesFieldNumber = 2;
  const ::DataTypes::Matches& matches() const;
  ::DataTypes::Matches* mutable_matches();
  ::DataTypes::Matches* release_matches();
  void set_allocated_matches(::DataTypes::Matches* matches);

  // optional .DataTypes.Faces faces = 3;
  bool has_faces() const;
  void clear_faces();
  static const int kFacesFieldNumber = 3;
  const ::DataTypes::Faces& faces() const;
  ::DataTypes::Faces* mutable_faces();
  ::DataTypes::Faces* release_faces();
  void set_allocated_faces(::DataTypes::Faces* faces);

  // optional bool success = 4;
  void clear_success();
  static const int kSuccessFieldNumber = 4;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:Services.BiometricResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::DataTypes::Photo* photo_;
  ::DataTypes::Matches* matches_;
  ::DataTypes::Faces* faces_;
  bool success_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_AssignDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_ShutdownFile_services_2ffacial_5fservice_2eproto();

  void InitAsDefaultInstance();
  static BiometricResponse* default_instance_;
};
// -------------------------------------------------------------------

class BiometricUpdate : public ::google::protobuf::Message {
 public:
  BiometricUpdate();
  virtual ~BiometricUpdate();

  BiometricUpdate(const BiometricUpdate& from);

  inline BiometricUpdate& operator=(const BiometricUpdate& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BiometricUpdate& default_instance();

  enum UpdateTypeCase {
    kInsert = 1,
    kRemove = 2,
    UPDATE_TYPE_NOT_SET = 0,
  };

  void Swap(BiometricUpdate* other);

  // implements Message ----------------------------------------------

  inline BiometricUpdate* New() const { return New(NULL); }

  BiometricUpdate* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BiometricUpdate& from);
  void MergeFrom(const BiometricUpdate& from);
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
  void InternalSwap(BiometricUpdate* other);
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

  // optional .DataTypes.FaceCharacteristic insert = 1;
  bool has_insert() const;
  void clear_insert();
  static const int kInsertFieldNumber = 1;
  const ::DataTypes::FaceCharacteristic& insert() const;
  ::DataTypes::FaceCharacteristic* mutable_insert();
  ::DataTypes::FaceCharacteristic* release_insert();
  void set_allocated_insert(::DataTypes::FaceCharacteristic* insert);

  // optional .DataTypes.FaceCharacteristic remove = 2;
  bool has_remove() const;
  void clear_remove();
  static const int kRemoveFieldNumber = 2;
  const ::DataTypes::FaceCharacteristic& remove() const;
  ::DataTypes::FaceCharacteristic* mutable_remove();
  ::DataTypes::FaceCharacteristic* release_remove();
  void set_allocated_remove(::DataTypes::FaceCharacteristic* remove);

  UpdateTypeCase update_type_case() const;
  // @@protoc_insertion_point(class_scope:Services.BiometricUpdate)
 private:
  inline void set_has_insert();
  inline void set_has_remove();

  inline bool has_update_type() const;
  void clear_update_type();
  inline void clear_has_update_type();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  union UpdateTypeUnion {
    UpdateTypeUnion() {}
    ::DataTypes::FaceCharacteristic* insert_;
    ::DataTypes::FaceCharacteristic* remove_;
  } update_type_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend void  protobuf_AddDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_AssignDesc_services_2ffacial_5fservice_2eproto();
  friend void protobuf_ShutdownFile_services_2ffacial_5fservice_2eproto();

  void InitAsDefaultInstance();
  static BiometricUpdate* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// BiometricRequest

// optional .DataTypes.FrameBytes frame = 1;
inline bool BiometricRequest::has_frame() const {
  return !_is_default_instance_ && frame_ != NULL;
}
inline void BiometricRequest::clear_frame() {
  if (GetArenaNoVirtual() == NULL && frame_ != NULL) delete frame_;
  frame_ = NULL;
}
inline const ::DataTypes::FrameBytes& BiometricRequest::frame() const {
  // @@protoc_insertion_point(field_get:Services.BiometricRequest.frame)
  return frame_ != NULL ? *frame_ : *default_instance_->frame_;
}
inline ::DataTypes::FrameBytes* BiometricRequest::mutable_frame() {
  
  if (frame_ == NULL) {
    frame_ = new ::DataTypes::FrameBytes;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricRequest.frame)
  return frame_;
}
inline ::DataTypes::FrameBytes* BiometricRequest::release_frame() {
  // @@protoc_insertion_point(field_release:Services.BiometricRequest.frame)
  
  ::DataTypes::FrameBytes* temp = frame_;
  frame_ = NULL;
  return temp;
}
inline void BiometricRequest::set_allocated_frame(::DataTypes::FrameBytes* frame) {
  delete frame_;
  frame_ = frame;
  if (frame) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricRequest.frame)
}

// optional .DataTypes.Key person = 2;
inline bool BiometricRequest::has_person() const {
  return !_is_default_instance_ && person_ != NULL;
}
inline void BiometricRequest::clear_person() {
  if (GetArenaNoVirtual() == NULL && person_ != NULL) delete person_;
  person_ = NULL;
}
inline const ::DataTypes::Key& BiometricRequest::person() const {
  // @@protoc_insertion_point(field_get:Services.BiometricRequest.person)
  return person_ != NULL ? *person_ : *default_instance_->person_;
}
inline ::DataTypes::Key* BiometricRequest::mutable_person() {
  
  if (person_ == NULL) {
    person_ = new ::DataTypes::Key;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricRequest.person)
  return person_;
}
inline ::DataTypes::Key* BiometricRequest::release_person() {
  // @@protoc_insertion_point(field_release:Services.BiometricRequest.person)
  
  ::DataTypes::Key* temp = person_;
  person_ = NULL;
  return temp;
}
inline void BiometricRequest::set_allocated_person(::DataTypes::Key* person) {
  delete person_;
  person_ = person;
  if (person) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricRequest.person)
}

// optional .DataTypes.BioActionType action = 3;
inline void BiometricRequest::clear_action() {
  action_ = 0;
}
inline ::DataTypes::BioActionType BiometricRequest::action() const {
  // @@protoc_insertion_point(field_get:Services.BiometricRequest.action)
  return static_cast< ::DataTypes::BioActionType >(action_);
}
inline void BiometricRequest::set_action(::DataTypes::BioActionType value) {
  
  action_ = value;
  // @@protoc_insertion_point(field_set:Services.BiometricRequest.action)
}

// optional .DataTypes.BiometricType type = 4;
inline void BiometricRequest::clear_type() {
  type_ = 0;
}
inline ::DataTypes::BiometricType BiometricRequest::type() const {
  // @@protoc_insertion_point(field_get:Services.BiometricRequest.type)
  return static_cast< ::DataTypes::BiometricType >(type_);
}
inline void BiometricRequest::set_type(::DataTypes::BiometricType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:Services.BiometricRequest.type)
}

// -------------------------------------------------------------------

// BiometricResponse

// optional .DataTypes.Photo photo = 1;
inline bool BiometricResponse::has_photo() const {
  return !_is_default_instance_ && photo_ != NULL;
}
inline void BiometricResponse::clear_photo() {
  if (GetArenaNoVirtual() == NULL && photo_ != NULL) delete photo_;
  photo_ = NULL;
}
inline const ::DataTypes::Photo& BiometricResponse::photo() const {
  // @@protoc_insertion_point(field_get:Services.BiometricResponse.photo)
  return photo_ != NULL ? *photo_ : *default_instance_->photo_;
}
inline ::DataTypes::Photo* BiometricResponse::mutable_photo() {
  
  if (photo_ == NULL) {
    photo_ = new ::DataTypes::Photo;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricResponse.photo)
  return photo_;
}
inline ::DataTypes::Photo* BiometricResponse::release_photo() {
  // @@protoc_insertion_point(field_release:Services.BiometricResponse.photo)
  
  ::DataTypes::Photo* temp = photo_;
  photo_ = NULL;
  return temp;
}
inline void BiometricResponse::set_allocated_photo(::DataTypes::Photo* photo) {
  delete photo_;
  photo_ = photo;
  if (photo) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricResponse.photo)
}

// optional .DataTypes.Matches matches = 2;
inline bool BiometricResponse::has_matches() const {
  return !_is_default_instance_ && matches_ != NULL;
}
inline void BiometricResponse::clear_matches() {
  if (GetArenaNoVirtual() == NULL && matches_ != NULL) delete matches_;
  matches_ = NULL;
}
inline const ::DataTypes::Matches& BiometricResponse::matches() const {
  // @@protoc_insertion_point(field_get:Services.BiometricResponse.matches)
  return matches_ != NULL ? *matches_ : *default_instance_->matches_;
}
inline ::DataTypes::Matches* BiometricResponse::mutable_matches() {
  
  if (matches_ == NULL) {
    matches_ = new ::DataTypes::Matches;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricResponse.matches)
  return matches_;
}
inline ::DataTypes::Matches* BiometricResponse::release_matches() {
  // @@protoc_insertion_point(field_release:Services.BiometricResponse.matches)
  
  ::DataTypes::Matches* temp = matches_;
  matches_ = NULL;
  return temp;
}
inline void BiometricResponse::set_allocated_matches(::DataTypes::Matches* matches) {
  delete matches_;
  matches_ = matches;
  if (matches) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricResponse.matches)
}

// optional .DataTypes.Faces faces = 3;
inline bool BiometricResponse::has_faces() const {
  return !_is_default_instance_ && faces_ != NULL;
}
inline void BiometricResponse::clear_faces() {
  if (GetArenaNoVirtual() == NULL && faces_ != NULL) delete faces_;
  faces_ = NULL;
}
inline const ::DataTypes::Faces& BiometricResponse::faces() const {
  // @@protoc_insertion_point(field_get:Services.BiometricResponse.faces)
  return faces_ != NULL ? *faces_ : *default_instance_->faces_;
}
inline ::DataTypes::Faces* BiometricResponse::mutable_faces() {
  
  if (faces_ == NULL) {
    faces_ = new ::DataTypes::Faces;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricResponse.faces)
  return faces_;
}
inline ::DataTypes::Faces* BiometricResponse::release_faces() {
  // @@protoc_insertion_point(field_release:Services.BiometricResponse.faces)
  
  ::DataTypes::Faces* temp = faces_;
  faces_ = NULL;
  return temp;
}
inline void BiometricResponse::set_allocated_faces(::DataTypes::Faces* faces) {
  delete faces_;
  faces_ = faces;
  if (faces) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricResponse.faces)
}

// optional bool success = 4;
inline void BiometricResponse::clear_success() {
  success_ = false;
}
inline bool BiometricResponse::success() const {
  // @@protoc_insertion_point(field_get:Services.BiometricResponse.success)
  return success_;
}
inline void BiometricResponse::set_success(bool value) {
  
  success_ = value;
  // @@protoc_insertion_point(field_set:Services.BiometricResponse.success)
}

// -------------------------------------------------------------------

// BiometricUpdate

// optional .DataTypes.FaceCharacteristic insert = 1;
inline bool BiometricUpdate::has_insert() const {
  return update_type_case() == kInsert;
}
inline void BiometricUpdate::set_has_insert() {
  _oneof_case_[0] = kInsert;
}
inline void BiometricUpdate::clear_insert() {
  if (has_insert()) {
    delete update_type_.insert_;
    clear_has_update_type();
  }
}
inline  const ::DataTypes::FaceCharacteristic& BiometricUpdate::insert() const {
  // @@protoc_insertion_point(field_get:Services.BiometricUpdate.insert)
  return has_insert()
      ? *update_type_.insert_
      : ::DataTypes::FaceCharacteristic::default_instance();
}
inline ::DataTypes::FaceCharacteristic* BiometricUpdate::mutable_insert() {
  if (!has_insert()) {
    clear_update_type();
    set_has_insert();
    update_type_.insert_ = new ::DataTypes::FaceCharacteristic;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricUpdate.insert)
  return update_type_.insert_;
}
inline ::DataTypes::FaceCharacteristic* BiometricUpdate::release_insert() {
  // @@protoc_insertion_point(field_release:Services.BiometricUpdate.insert)
  if (has_insert()) {
    clear_has_update_type();
    ::DataTypes::FaceCharacteristic* temp = update_type_.insert_;
    update_type_.insert_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void BiometricUpdate::set_allocated_insert(::DataTypes::FaceCharacteristic* insert) {
  clear_update_type();
  if (insert) {
    set_has_insert();
    update_type_.insert_ = insert;
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricUpdate.insert)
}

// optional .DataTypes.FaceCharacteristic remove = 2;
inline bool BiometricUpdate::has_remove() const {
  return update_type_case() == kRemove;
}
inline void BiometricUpdate::set_has_remove() {
  _oneof_case_[0] = kRemove;
}
inline void BiometricUpdate::clear_remove() {
  if (has_remove()) {
    delete update_type_.remove_;
    clear_has_update_type();
  }
}
inline  const ::DataTypes::FaceCharacteristic& BiometricUpdate::remove() const {
  // @@protoc_insertion_point(field_get:Services.BiometricUpdate.remove)
  return has_remove()
      ? *update_type_.remove_
      : ::DataTypes::FaceCharacteristic::default_instance();
}
inline ::DataTypes::FaceCharacteristic* BiometricUpdate::mutable_remove() {
  if (!has_remove()) {
    clear_update_type();
    set_has_remove();
    update_type_.remove_ = new ::DataTypes::FaceCharacteristic;
  }
  // @@protoc_insertion_point(field_mutable:Services.BiometricUpdate.remove)
  return update_type_.remove_;
}
inline ::DataTypes::FaceCharacteristic* BiometricUpdate::release_remove() {
  // @@protoc_insertion_point(field_release:Services.BiometricUpdate.remove)
  if (has_remove()) {
    clear_has_update_type();
    ::DataTypes::FaceCharacteristic* temp = update_type_.remove_;
    update_type_.remove_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline void BiometricUpdate::set_allocated_remove(::DataTypes::FaceCharacteristic* remove) {
  clear_update_type();
  if (remove) {
    set_has_remove();
    update_type_.remove_ = remove;
  }
  // @@protoc_insertion_point(field_set_allocated:Services.BiometricUpdate.remove)
}

inline bool BiometricUpdate::has_update_type() const {
  return update_type_case() != UPDATE_TYPE_NOT_SET;
}
inline void BiometricUpdate::clear_has_update_type() {
  _oneof_case_[0] = UPDATE_TYPE_NOT_SET;
}
inline BiometricUpdate::UpdateTypeCase BiometricUpdate::update_type_case() const {
  return BiometricUpdate::UpdateTypeCase(_oneof_case_[0]);
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Services

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_services_2ffacial_5fservice_2eproto__INCLUDED
