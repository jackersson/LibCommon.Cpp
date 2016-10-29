// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: services/file_service.proto

#include "services/file_service.pb.h"
#include "services/file_service.grpc.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/channel_interface.h>
#include <grpc++/impl/codegen/client_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/rpc_service_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/sync_stream.h>
namespace Services {

static const char* FileService_method_names[] = {
  "/Services.FileService/Get",
  "/Services.FileService/Create",
  "/Services.FileService/Delete",
  "/Services.FileService/Exists",
};

std::unique_ptr< FileService::Stub> FileService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  std::unique_ptr< FileService::Stub> stub(new FileService::Stub(channel));
  return stub;
}

FileService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Get_(FileService_method_names[0], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Create_(FileService_method_names[1], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(FileService_method_names[2], ::grpc::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Exists_(FileService_method_names[3], ::grpc::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status FileService::Stub::Get(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::Services::FileBytes* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Get_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::Services::FileBytes>* FileService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::Services::FileBytes>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::Status FileService::Stub::Create(::grpc::ClientContext* context, const ::Services::FileBytes& request, ::Services::FileMessage* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Create_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::Services::FileMessage>* FileService::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::Services::FileBytes& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::Services::FileMessage>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::Status FileService::Stub::Delete(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::Services::EmptyMessage* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Delete_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::Services::EmptyMessage>* FileService::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::Services::EmptyMessage>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::Status FileService::Stub::Exists(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::Services::ExistMessage* response) {
  return ::grpc::BlockingUnaryCall(channel_.get(), rpcmethod_Exists_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::Services::ExistMessage>* FileService::Stub::AsyncExistsRaw(::grpc::ClientContext* context, const ::Services::FileMessage& request, ::grpc::CompletionQueue* cq) {
  return new ::grpc::ClientAsyncResponseReader< ::Services::ExistMessage>(channel_.get(), cq, rpcmethod_Exists_, context, request);
}

FileService::Service::Service() {
  (void)FileService_method_names;
  AddMethod(new ::grpc::RpcServiceMethod(
      FileService_method_names[0],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< FileService::Service, ::Services::FileMessage, ::Services::FileBytes>(
          std::mem_fn(&FileService::Service::Get), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      FileService_method_names[1],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< FileService::Service, ::Services::FileBytes, ::Services::FileMessage>(
          std::mem_fn(&FileService::Service::Create), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      FileService_method_names[2],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< FileService::Service, ::Services::FileMessage, ::Services::EmptyMessage>(
          std::mem_fn(&FileService::Service::Delete), this)));
  AddMethod(new ::grpc::RpcServiceMethod(
      FileService_method_names[3],
      ::grpc::RpcMethod::NORMAL_RPC,
      new ::grpc::RpcMethodHandler< FileService::Service, ::Services::FileMessage, ::Services::ExistMessage>(
          std::mem_fn(&FileService::Service::Exists), this)));
}

FileService::Service::~Service() {
}

::grpc::Status FileService::Service::Get(::grpc::ServerContext* context, const ::Services::FileMessage* request, ::Services::FileBytes* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FileService::Service::Create(::grpc::ServerContext* context, const ::Services::FileBytes* request, ::Services::FileMessage* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FileService::Service::Delete(::grpc::ServerContext* context, const ::Services::FileMessage* request, ::Services::EmptyMessage* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FileService::Service::Exists(::grpc::ServerContext* context, const ::Services::FileMessage* request, ::Services::ExistMessage* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Services

