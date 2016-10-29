// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datatypes/card.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "datatypes/card.pb.h"

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

const ::google::protobuf::Descriptor* Card_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Card_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_datatypes_2fcard_2eproto() {
  protobuf_AddDesc_datatypes_2fcard_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "datatypes/card.proto");
  GOOGLE_CHECK(file != NULL);
  Card_descriptor_ = file->message_type(0);
  static const int Card_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Card, unique_identifier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Card, owner_id_),
  };
  Card_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Card_descriptor_,
      Card::default_instance_,
      Card_offsets_,
      -1,
      -1,
      -1,
      sizeof(Card),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Card, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Card, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_datatypes_2fcard_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Card_descriptor_, &Card::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_datatypes_2fcard_2eproto() {
  delete Card::default_instance_;
  delete Card_reflection_;
}

void protobuf_AddDesc_datatypes_2fcard_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::DataTypes::protobuf_AddDesc_datatypes_2fkey_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024datatypes/card.proto\022\tDataTypes\032\023datat"
    "ypes/key.proto\"S\n\004Card\022)\n\021unique_identif"
    "ier\030\001 \001(\0132\016.DataTypes.Key\022 \n\010owner_id\030\002 "
    "\001(\0132\016.DataTypes.KeyBI\n\007ex.grpcZ8github.c"
    "om/Enebra/ServiceCoordinator/grpc/dataty"
    "pes/card\242\002\003RTGb\006proto3", 222);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "datatypes/card.proto", &protobuf_RegisterTypes);
  Card::default_instance_ = new Card();
  Card::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_datatypes_2fcard_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_datatypes_2fcard_2eproto {
  StaticDescriptorInitializer_datatypes_2fcard_2eproto() {
    protobuf_AddDesc_datatypes_2fcard_2eproto();
  }
} static_descriptor_initializer_datatypes_2fcard_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Card::kUniqueIdentifierFieldNumber;
const int Card::kOwnerIdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Card::Card()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:DataTypes.Card)
}

void Card::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  unique_identifier_ = const_cast< ::DataTypes::Key*>(&::DataTypes::Key::default_instance());
  owner_id_ = const_cast< ::DataTypes::Key*>(&::DataTypes::Key::default_instance());
}

Card::Card(const Card& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:DataTypes.Card)
}

void Card::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  unique_identifier_ = NULL;
  owner_id_ = NULL;
}

Card::~Card() {
  // @@protoc_insertion_point(destructor:DataTypes.Card)
  SharedDtor();
}

void Card::SharedDtor() {
  if (this != default_instance_) {
    delete unique_identifier_;
    delete owner_id_;
  }
}

void Card::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Card::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Card_descriptor_;
}

const Card& Card::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_datatypes_2fcard_2eproto();
  return *default_instance_;
}

Card* Card::default_instance_ = NULL;

Card* Card::New(::google::protobuf::Arena* arena) const {
  Card* n = new Card;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Card::Clear() {
// @@protoc_insertion_point(message_clear_start:DataTypes.Card)
  if (GetArenaNoVirtual() == NULL && unique_identifier_ != NULL) delete unique_identifier_;
  unique_identifier_ = NULL;
  if (GetArenaNoVirtual() == NULL && owner_id_ != NULL) delete owner_id_;
  owner_id_ = NULL;
}

bool Card::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:DataTypes.Card)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .DataTypes.Key unique_identifier = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_unique_identifier()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_owner_id;
        break;
      }

      // optional .DataTypes.Key owner_id = 2;
      case 2: {
        if (tag == 18) {
         parse_owner_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_owner_id()));
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
  // @@protoc_insertion_point(parse_success:DataTypes.Card)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:DataTypes.Card)
  return false;
#undef DO_
}

void Card::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:DataTypes.Card)
  // optional .DataTypes.Key unique_identifier = 1;
  if (this->has_unique_identifier()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->unique_identifier_, output);
  }

  // optional .DataTypes.Key owner_id = 2;
  if (this->has_owner_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->owner_id_, output);
  }

  // @@protoc_insertion_point(serialize_end:DataTypes.Card)
}

::google::protobuf::uint8* Card::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:DataTypes.Card)
  // optional .DataTypes.Key unique_identifier = 1;
  if (this->has_unique_identifier()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, *this->unique_identifier_, target);
  }

  // optional .DataTypes.Key owner_id = 2;
  if (this->has_owner_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, *this->owner_id_, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:DataTypes.Card)
  return target;
}

int Card::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:DataTypes.Card)
  int total_size = 0;

  // optional .DataTypes.Key unique_identifier = 1;
  if (this->has_unique_identifier()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->unique_identifier_);
  }

  // optional .DataTypes.Key owner_id = 2;
  if (this->has_owner_id()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->owner_id_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Card::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:DataTypes.Card)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const Card* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Card>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:DataTypes.Card)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:DataTypes.Card)
    MergeFrom(*source);
  }
}

void Card::MergeFrom(const Card& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:DataTypes.Card)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from.has_unique_identifier()) {
    mutable_unique_identifier()->::DataTypes::Key::MergeFrom(from.unique_identifier());
  }
  if (from.has_owner_id()) {
    mutable_owner_id()->::DataTypes::Key::MergeFrom(from.owner_id());
  }
}

void Card::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:DataTypes.Card)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Card::CopyFrom(const Card& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:DataTypes.Card)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Card::IsInitialized() const {

  return true;
}

void Card::Swap(Card* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Card::InternalSwap(Card* other) {
  std::swap(unique_identifier_, other->unique_identifier_);
  std::swap(owner_id_, other->owner_id_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Card::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Card_descriptor_;
  metadata.reflection = Card_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Card

// optional .DataTypes.Key unique_identifier = 1;
bool Card::has_unique_identifier() const {
  return !_is_default_instance_ && unique_identifier_ != NULL;
}
void Card::clear_unique_identifier() {
  if (GetArenaNoVirtual() == NULL && unique_identifier_ != NULL) delete unique_identifier_;
  unique_identifier_ = NULL;
}
const ::DataTypes::Key& Card::unique_identifier() const {
  // @@protoc_insertion_point(field_get:DataTypes.Card.unique_identifier)
  return unique_identifier_ != NULL ? *unique_identifier_ : *default_instance_->unique_identifier_;
}
::DataTypes::Key* Card::mutable_unique_identifier() {
  
  if (unique_identifier_ == NULL) {
    unique_identifier_ = new ::DataTypes::Key;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Card.unique_identifier)
  return unique_identifier_;
}
::DataTypes::Key* Card::release_unique_identifier() {
  // @@protoc_insertion_point(field_release:DataTypes.Card.unique_identifier)
  
  ::DataTypes::Key* temp = unique_identifier_;
  unique_identifier_ = NULL;
  return temp;
}
void Card::set_allocated_unique_identifier(::DataTypes::Key* unique_identifier) {
  delete unique_identifier_;
  unique_identifier_ = unique_identifier;
  if (unique_identifier) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Card.unique_identifier)
}

// optional .DataTypes.Key owner_id = 2;
bool Card::has_owner_id() const {
  return !_is_default_instance_ && owner_id_ != NULL;
}
void Card::clear_owner_id() {
  if (GetArenaNoVirtual() == NULL && owner_id_ != NULL) delete owner_id_;
  owner_id_ = NULL;
}
const ::DataTypes::Key& Card::owner_id() const {
  // @@protoc_insertion_point(field_get:DataTypes.Card.owner_id)
  return owner_id_ != NULL ? *owner_id_ : *default_instance_->owner_id_;
}
::DataTypes::Key* Card::mutable_owner_id() {
  
  if (owner_id_ == NULL) {
    owner_id_ = new ::DataTypes::Key;
  }
  // @@protoc_insertion_point(field_mutable:DataTypes.Card.owner_id)
  return owner_id_;
}
::DataTypes::Key* Card::release_owner_id() {
  // @@protoc_insertion_point(field_release:DataTypes.Card.owner_id)
  
  ::DataTypes::Key* temp = owner_id_;
  owner_id_ = NULL;
  return temp;
}
void Card::set_allocated_owner_id(::DataTypes::Key* owner_id) {
  delete owner_id_;
  owner_id_ = owner_id;
  if (owner_id) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:DataTypes.Card.owner_id)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace DataTypes

// @@protoc_insertion_point(global_scope)