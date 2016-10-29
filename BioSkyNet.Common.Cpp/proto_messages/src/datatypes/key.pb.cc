// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datatypes/key.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "datatypes/key.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace DataTypes {

namespace {

const ::google::protobuf::Descriptor* Key_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Key_reflection_ = NULL;
struct KeyOneofInstance {
  ::google::protobuf::int64 number_;
  ::google::protobuf::internal::ArenaStringPtr identifier_;
  ::google::protobuf::internal::ArenaStringPtr guid_;
}* Key_default_oneof_instance_ = NULL;

}  // namespace


void protobuf_AssignDesc_datatypes_2fkey_2eproto() {
  protobuf_AddDesc_datatypes_2fkey_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "datatypes/key.proto");
  GOOGLE_CHECK(file != NULL);
  Key_descriptor_ = file->message_type(0);
  static const int Key_offsets_[4] = {
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Key_default_oneof_instance_, number_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Key_default_oneof_instance_, identifier_),
    PROTO2_GENERATED_DEFAULT_ONEOF_FIELD_OFFSET(Key_default_oneof_instance_, guid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Key, id_type_),
  };
  Key_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Key_descriptor_,
      Key::default_instance_,
      Key_offsets_,
      -1,
      -1,
      -1,
      Key_default_oneof_instance_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Key, _oneof_case_[0]),
      sizeof(Key),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Key, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Key, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_datatypes_2fkey_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Key_descriptor_, &Key::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_datatypes_2fkey_2eproto() {
  delete Key::default_instance_;
  delete Key_default_oneof_instance_;
  delete Key_reflection_;
}

void protobuf_AddDesc_datatypes_2fkey_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023datatypes/key.proto\022\tDataTypes\"H\n\003Key\022"
    "\020\n\006number\030\001 \001(\003H\000\022\024\n\nidentifier\030\002 \001(\tH\000\022"
    "\016\n\004guid\030\003 \001(\014H\000B\t\n\007id_typeBH\n\007ex.grpcZ7g"
    "ithub.com/Enebra/ServiceCoordinator/grpc"
    "/datatypes/key\242\002\003RTGb\006proto3", 188);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "datatypes/key.proto", &protobuf_RegisterTypes);
  Key::default_instance_ = new Key();
  Key_default_oneof_instance_ = new KeyOneofInstance();
  Key::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_datatypes_2fkey_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_datatypes_2fkey_2eproto {
  StaticDescriptorInitializer_datatypes_2fkey_2eproto() {
    protobuf_AddDesc_datatypes_2fkey_2eproto();
  }
} static_descriptor_initializer_datatypes_2fkey_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Key::kNumberFieldNumber;
const int Key::kIdentifierFieldNumber;
const int Key::kGuidFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Key::Key()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:DataTypes.Key)
}

void Key::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  Key_default_oneof_instance_->number_ = GOOGLE_LONGLONG(0);
  Key_default_oneof_instance_->identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  Key_default_oneof_instance_->guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Key::Key(const Key& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:DataTypes.Key)
}

void Key::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  clear_has_id_type();
}

Key::~Key() {
  // @@protoc_insertion_point(destructor:DataTypes.Key)
  SharedDtor();
}

void Key::SharedDtor() {
  if (has_id_type()) {
    clear_id_type();
  }
  if (this != default_instance_) {
  }
}

void Key::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Key::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Key_descriptor_;
}

const Key& Key::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_datatypes_2fkey_2eproto();
  return *default_instance_;
}

Key* Key::default_instance_ = NULL;

Key* Key::New(::google::protobuf::Arena* arena) const {
  Key* n = new Key;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Key::clear_id_type() {
// @@protoc_insertion_point(one_of_clear_start:DataTypes.Key)
  switch(id_type_case()) {
    case kNumber: {
      // No need to clear
      break;
    }
    case kIdentifier: {
      id_type_.identifier_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
      break;
    }
    case kGuid: {
      id_type_.guid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
      break;
    }
    case ID_TYPE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = ID_TYPE_NOT_SET;
}


void Key::Clear() {
// @@protoc_insertion_point(message_clear_start:DataTypes.Key)
  clear_id_type();
}

bool Key::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:DataTypes.Key)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 number = 1;
      case 1: {
        if (tag == 8) {
          clear_id_type();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_type_.number_)));
          set_has_number();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_identifier;
        break;
      }

      // optional string identifier = 2;
      case 2: {
        if (tag == 18) {
         parse_identifier:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_identifier()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->identifier().data(), this->identifier().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "DataTypes.Key.identifier"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_guid;
        break;
      }

      // optional bytes guid = 3;
      case 3: {
        if (tag == 26) {
         parse_guid:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_guid()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:DataTypes.Key)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:DataTypes.Key)
  return false;
#undef DO_
}

void Key::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:DataTypes.Key)
  // optional int64 number = 1;
  if (has_number()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->number(), output);
  }

  // optional string identifier = 2;
  if (has_identifier()) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->identifier().data(), this->identifier().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "DataTypes.Key.identifier");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->identifier(), output);
  }

  // optional bytes guid = 3;
  if (has_guid()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->guid(), output);
  }

  // @@protoc_insertion_point(serialize_end:DataTypes.Key)
}

::google::protobuf::uint8* Key::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:DataTypes.Key)
  // optional int64 number = 1;
  if (has_number()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->number(), target);
  }

  // optional string identifier = 2;
  if (has_identifier()) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->identifier().data(), this->identifier().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "DataTypes.Key.identifier");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->identifier(), target);
  }

  // optional bytes guid = 3;
  if (has_guid()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->guid(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:DataTypes.Key)
  return target;
}

int Key::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:DataTypes.Key)
  int total_size = 0;

  switch (id_type_case()) {
    // optional int64 number = 1;
    case kNumber: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->number());
      break;
    }
    // optional string identifier = 2;
    case kIdentifier: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->identifier());
      break;
    }
    // optional bytes guid = 3;
    case kGuid: {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->guid());
      break;
    }
    case ID_TYPE_NOT_SET: {
      break;
    }
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Key::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:DataTypes.Key)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Key* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Key>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:DataTypes.Key)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:DataTypes.Key)
    MergeFrom(*source);
  }
}

void Key::MergeFrom(const Key& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:DataTypes.Key)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  switch (from.id_type_case()) {
    case kNumber: {
      set_number(from.number());
      break;
    }
    case kIdentifier: {
      set_identifier(from.identifier());
      break;
    }
    case kGuid: {
      set_guid(from.guid());
      break;
    }
    case ID_TYPE_NOT_SET: {
      break;
    }
  }
}

void Key::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:DataTypes.Key)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Key::CopyFrom(const Key& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:DataTypes.Key)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Key::IsInitialized() const {

  return true;
}

void Key::Swap(Key* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Key::InternalSwap(Key* other) {
  std::swap(id_type_, other->id_type_);
  std::swap(_oneof_case_[0], other->_oneof_case_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Key::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Key_descriptor_;
  metadata.reflection = Key_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Key

// optional int64 number = 1;
bool Key::has_number() const {
  return id_type_case() == kNumber;
}
void Key::set_has_number() {
  _oneof_case_[0] = kNumber;
}
void Key::clear_number() {
  if (has_number()) {
    id_type_.number_ = GOOGLE_LONGLONG(0);
    clear_has_id_type();
  }
}
 ::google::protobuf::int64 Key::number() const {
  // @@protoc_insertion_point(field_get:DataTypes.Key.number)
  if (has_number()) {
    return id_type_.number_;
  }
  return GOOGLE_LONGLONG(0);
}
 void Key::set_number(::google::protobuf::int64 value) {
  if (!has_number()) {
    clear_id_type();
    set_has_number();
  }
  id_type_.number_ = value;
  // @@protoc_insertion_point(field_set:DataTypes.Key.number)
}

// optional string identifier = 2;
bool Key::has_identifier() const {
  return id_type_case() == kIdentifier;
}
void Key::set_has_identifier() {
  _oneof_case_[0] = kIdentifier;
}
void Key::clear_identifier() {
  if (has_identifier()) {
    id_type_.identifier_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_id_type();
  }
}
 const ::std::string& Key::identifier() const {
  // @@protoc_insertion_point(field_get:DataTypes.Key.identifier)
  if (has_identifier()) {
    return id_type_.identifier_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  return *&::google::protobuf::internal::GetEmptyStringAlreadyInited();
}
 void Key::set_identifier(const ::std::string& value) {
  // @@protoc_insertion_point(field_set:DataTypes.Key.identifier)
  if (!has_identifier()) {
    clear_id_type();
    set_has_identifier();
    id_type_.identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.identifier_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DataTypes.Key.identifier)
}
 void Key::set_identifier(const char* value) {
  if (!has_identifier()) {
    clear_id_type();
    set_has_identifier();
    id_type_.identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.identifier_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DataTypes.Key.identifier)
}
 void Key::set_identifier(const char* value, size_t size) {
  if (!has_identifier()) {
    clear_id_type();
    set_has_identifier();
    id_type_.identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.identifier_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DataTypes.Key.identifier)
}
 ::std::string* Key::mutable_identifier() {
  if (!has_identifier()) {
    clear_id_type();
    set_has_identifier();
    id_type_.identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Key.identifier)
  return id_type_.identifier_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Key::release_identifier() {
  // @@protoc_insertion_point(field_release:DataTypes.Key.identifier)
  if (has_identifier()) {
    clear_has_id_type();
    return id_type_.identifier_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  } else {
    return NULL;
  }
}
 void Key::set_allocated_identifier(::std::string* identifier) {
  if (!has_identifier()) {
    id_type_.identifier_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  clear_id_type();
  if (identifier != NULL) {
    set_has_identifier();
    id_type_.identifier_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        identifier);
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Key.identifier)
}

// optional bytes guid = 3;
bool Key::has_guid() const {
  return id_type_case() == kGuid;
}
void Key::set_has_guid() {
  _oneof_case_[0] = kGuid;
}
void Key::clear_guid() {
  if (has_guid()) {
    id_type_.guid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    clear_has_id_type();
  }
}
 const ::std::string& Key::guid() const {
  // @@protoc_insertion_point(field_get:DataTypes.Key.guid)
  if (has_guid()) {
    return id_type_.guid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  return *&::google::protobuf::internal::GetEmptyStringAlreadyInited();
}
 void Key::set_guid(const ::std::string& value) {
  // @@protoc_insertion_point(field_set:DataTypes.Key.guid)
  if (!has_guid()) {
    clear_id_type();
    set_has_guid();
    id_type_.guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:DataTypes.Key.guid)
}
 void Key::set_guid(const char* value) {
  if (!has_guid()) {
    clear_id_type();
    set_has_guid();
    id_type_.guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value));
  // @@protoc_insertion_point(field_set_char:DataTypes.Key.guid)
}
 void Key::set_guid(const void* value, size_t size) {
  if (!has_guid()) {
    clear_id_type();
    set_has_guid();
    id_type_.guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  id_type_.guid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:DataTypes.Key.guid)
}
 ::std::string* Key::mutable_guid() {
  if (!has_guid()) {
    clear_id_type();
    set_has_guid();
    id_type_.guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Key.guid)
  return id_type_.guid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* Key::release_guid() {
  // @@protoc_insertion_point(field_release:DataTypes.Key.guid)
  if (has_guid()) {
    clear_has_id_type();
    return id_type_.guid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  } else {
    return NULL;
  }
}
 void Key::set_allocated_guid(::std::string* guid) {
  if (!has_guid()) {
    id_type_.guid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  clear_id_type();
  if (guid != NULL) {
    set_has_guid();
    id_type_.guid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        guid);
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Key.guid)
}

bool Key::has_id_type() const {
  return id_type_case() != ID_TYPE_NOT_SET;
}
void Key::clear_has_id_type() {
  _oneof_case_[0] = ID_TYPE_NOT_SET;
}
Key::IdTypeCase Key::id_type_case() const {
  return Key::IdTypeCase(_oneof_case_[0]);
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace DataTypes

// @@protoc_insertion_point(global_scope)
