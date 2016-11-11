// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: services/unit_service.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "services/unit_service.pb.h"

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

namespace Services {

namespace {


}  // namespace


void protobuf_AssignDesc_services_2funit_5fservice_2eproto() {
  protobuf_AddDesc_services_2funit_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "services/unit_service.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_services_2funit_5fservice_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_services_2funit_5fservice_2eproto() {
}

void protobuf_AddDesc_services_2funit_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2fempty_2eproto();
  ::DataTypes::protobuf_AddDesc_datatypes_2flocation_2eproto();
  ::DataTypes::protobuf_AddDesc_datatypes_2fdevices_2eproto();
  ::DataTypes::protobuf_AddDesc_datatypes_2fbiometrics_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033services/unit_service.proto\022\010Services\032"
    "\033google/protobuf/empty.proto\032\030datatypes/"
    "location.proto\032\027datatypes/devices.proto\032"
    "\032datatypes/biometrics.proto2\357\003\n\013UnitServ"
    "ice\0229\n\010OpenDoor\022\023.DataTypes.Location\032\026.g"
    "oogle.protobuf.Empty\"\000\022C\n\021GetLocationStr"
    "eam\022\023.DataTypes.Location\032\025.DataTypes.Fra"
    "meBytes\"\0000\001\022:\n\nGetDevices\022\026.google.proto"
    "buf.Empty\032\022.DataTypes.Devices\"\000\022E\n\016Updat"
    "eLocation\022\031.DataTypes.LocationUpdate\032\026.g"
    "oogle.protobuf.Empty\"\000\0222\n\007GetCard\022\021.Data"
    "Types.Device\032\022.DataTypes.CardMsg\"\000\0227\n\013Ch"
    "eckDevice\022\021.DataTypes.Device\032\023.DataTypes"
    ".CheckMsg\"\000\022\?\n\017GetDeviceStream\022\021.DataTyp"
    "es.Device\032\025.DataTypes.FrameBytes\"\0000\001\022/\n\006"
    "Enroll\022\021.DataTypes.Device\032\020.DataTypes.Fa"
    "ces\"\000BO\n\007ex.grpcZ>github.com/Enebra/Serv"
    "iceCoordinator/grpc/services/unitservice"
    "\242\002\003RTGb\006proto3", 734);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "services/unit_service.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_services_2funit_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_services_2funit_5fservice_2eproto {
  StaticDescriptorInitializer_services_2funit_5fservice_2eproto() {
    protobuf_AddDesc_services_2funit_5fservice_2eproto();
  }
} static_descriptor_initializer_services_2funit_5fservice_2eproto_;

// @@protoc_insertion_point(namespace_scope)

}  // namespace Services

// @@protoc_insertion_point(global_scope)
