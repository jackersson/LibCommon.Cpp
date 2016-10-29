// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datatypes/commands.proto

#ifndef PROTOBUF_datatypes_2fcommands_2eproto__INCLUDED
#define PROTOBUF_datatypes_2fcommands_2eproto__INCLUDED

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
#include "datatypes/data.pb.h"
// @@protoc_insertion_point(includes)

namespace DataTypes {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_datatypes_2fcommands_2eproto();
void protobuf_AssignDesc_datatypes_2fcommands_2eproto();
void protobuf_ShutdownFile_datatypes_2fcommands_2eproto();

class CommitRequest;
class CommitResponse;

// ===================================================================

class CommitRequest : public ::google::protobuf::Message {
 public:
  CommitRequest();
  virtual ~CommitRequest();

  CommitRequest(const CommitRequest& from);

  inline CommitRequest& operator=(const CommitRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommitRequest& default_instance();

  void Swap(CommitRequest* other);

  // implements Message ----------------------------------------------

  inline CommitRequest* New() const { return New(NULL); }

  CommitRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CommitRequest& from);
  void MergeFrom(const CommitRequest& from);
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
  void InternalSwap(CommitRequest* other);
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

  // repeated .DataTypes.Mutation mutations = 1;
  int mutations_size() const;
  void clear_mutations();
  static const int kMutationsFieldNumber = 1;
  const ::DataTypes::Mutation& mutations(int index) const;
  ::DataTypes::Mutation* mutable_mutations(int index);
  ::DataTypes::Mutation* add_mutations();
  ::google::protobuf::RepeatedPtrField< ::DataTypes::Mutation >*
      mutable_mutations();
  const ::google::protobuf::RepeatedPtrField< ::DataTypes::Mutation >&
      mutations() const;

  // @@protoc_insertion_point(class_scope:DataTypes.CommitRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::DataTypes::Mutation > mutations_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_datatypes_2fcommands_2eproto();
  friend void protobuf_AssignDesc_datatypes_2fcommands_2eproto();
  friend void protobuf_ShutdownFile_datatypes_2fcommands_2eproto();

  void InitAsDefaultInstance();
  static CommitRequest* default_instance_;
};
// -------------------------------------------------------------------

class CommitResponse : public ::google::protobuf::Message {
 public:
  CommitResponse();
  virtual ~CommitResponse();

  CommitResponse(const CommitResponse& from);

  inline CommitResponse& operator=(const CommitResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommitResponse& default_instance();

  void Swap(CommitResponse* other);

  // implements Message ----------------------------------------------

  inline CommitResponse* New() const { return New(NULL); }

  CommitResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CommitResponse& from);
  void MergeFrom(const CommitResponse& from);
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
  void InternalSwap(CommitResponse* other);
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

  // repeated .DataTypes.MutationResult mutation_results = 1;
  int mutation_results_size() const;
  void clear_mutation_results();
  static const int kMutationResultsFieldNumber = 1;
  const ::DataTypes::MutationResult& mutation_results(int index) const;
  ::DataTypes::MutationResult* mutable_mutation_results(int index);
  ::DataTypes::MutationResult* add_mutation_results();
  ::google::protobuf::RepeatedPtrField< ::DataTypes::MutationResult >*
      mutable_mutation_results();
  const ::google::protobuf::RepeatedPtrField< ::DataTypes::MutationResult >&
      mutation_results() const;

  // @@protoc_insertion_point(class_scope:DataTypes.CommitResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::DataTypes::MutationResult > mutation_results_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_datatypes_2fcommands_2eproto();
  friend void protobuf_AssignDesc_datatypes_2fcommands_2eproto();
  friend void protobuf_ShutdownFile_datatypes_2fcommands_2eproto();

  void InitAsDefaultInstance();
  static CommitResponse* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// CommitRequest

// repeated .DataTypes.Mutation mutations = 1;
inline int CommitRequest::mutations_size() const {
  return mutations_.size();
}
inline void CommitRequest::clear_mutations() {
  mutations_.Clear();
}
inline const ::DataTypes::Mutation& CommitRequest::mutations(int index) const {
  // @@protoc_insertion_point(field_get:DataTypes.CommitRequest.mutations)
  return mutations_.Get(index);
}
inline ::DataTypes::Mutation* CommitRequest::mutable_mutations(int index) {
  // @@protoc_insertion_point(field_mutable:DataTypes.CommitRequest.mutations)
  return mutations_.Mutable(index);
}
inline ::DataTypes::Mutation* CommitRequest::add_mutations() {
  // @@protoc_insertion_point(field_add:DataTypes.CommitRequest.mutations)
  return mutations_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::DataTypes::Mutation >*
CommitRequest::mutable_mutations() {
  // @@protoc_insertion_point(field_mutable_list:DataTypes.CommitRequest.mutations)
  return &mutations_;
}
inline const ::google::protobuf::RepeatedPtrField< ::DataTypes::Mutation >&
CommitRequest::mutations() const {
  // @@protoc_insertion_point(field_list:DataTypes.CommitRequest.mutations)
  return mutations_;
}

// -------------------------------------------------------------------

// CommitResponse

// repeated .DataTypes.MutationResult mutation_results = 1;
inline int CommitResponse::mutation_results_size() const {
  return mutation_results_.size();
}
inline void CommitResponse::clear_mutation_results() {
  mutation_results_.Clear();
}
inline const ::DataTypes::MutationResult& CommitResponse::mutation_results(int index) const {
  // @@protoc_insertion_point(field_get:DataTypes.CommitResponse.mutation_results)
  return mutation_results_.Get(index);
}
inline ::DataTypes::MutationResult* CommitResponse::mutable_mutation_results(int index) {
  // @@protoc_insertion_point(field_mutable:DataTypes.CommitResponse.mutation_results)
  return mutation_results_.Mutable(index);
}
inline ::DataTypes::MutationResult* CommitResponse::add_mutation_results() {
  // @@protoc_insertion_point(field_add:DataTypes.CommitResponse.mutation_results)
  return mutation_results_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::DataTypes::MutationResult >*
CommitResponse::mutable_mutation_results() {
  // @@protoc_insertion_point(field_mutable_list:DataTypes.CommitResponse.mutation_results)
  return &mutation_results_;
}
inline const ::google::protobuf::RepeatedPtrField< ::DataTypes::MutationResult >&
CommitResponse::mutation_results() const {
  // @@protoc_insertion_point(field_list:DataTypes.CommitResponse.mutation_results)
  return mutation_results_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace DataTypes

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_datatypes_2fcommands_2eproto__INCLUDED