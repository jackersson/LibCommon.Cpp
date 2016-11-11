#ifndef CoordinatorClientProtoApi_INCLUDED
#define CoordinatorClientProtoApi_INCLUDED

#include <services/coordinator_service.grpc.pb.h>
#include <database_service/database_client_calls.hpp>

#include <service_utils.hpp>

#include <services/service_address.hpp>
#include <helpers/service_heplers.hpp>
#include "coordinator_client_calls.hpp"
#include <logging/logger.hpp>
#include <helpers/request_adapters.hpp>
#include <abstract_client_service.hpp>

namespace services_api
{
	//Virtual:
	//add_call_handlers (if we do't want to use other call handlers
	class CoordinatorClientProtoApi : public AbstractClientService				                          
	{
	public:
		explicit CoordinatorClientProtoApi( contracts::services::IServiceAddress& address)
			                            : AbstractClientService(address)		
		{		
			CoordinatorClientProtoApi::init();
		}

		~CoordinatorClientProtoApi(){
			CoordinatorClientProtoApi::de_init();
		}

		void init() override
		{
			connect();

			add_call_handlers();		
		}

	protected:
		virtual void add_call_handlers()
		{
			add_call_handler<AsyncConnectCall      >();
			add_call_handler<AsyncHeartbeatCall    >();
			add_call_handler<AsyncUpdateDevicesCall>();
			add_call_handler<AsyncGetRequestCall   >();
			add_call_handler<AsyncCommitRequestCall>();
		}

	public:
		void de_init() override	{
			stop();
		}
		
		bool connect_request(const DataTypes::ConnectMsg& request) 
		{			
			auto queue = get_completion_queue<AsyncConnectCall>();
			if (queue == nullptr)	return false;

			auto call = new AsyncConnectCall;
			set_call_options(call);
			call->reader = stub_->AsyncConnect(&call->context, request, queue);
			call->reader->Finish( &call->response
				                  , &call->status
				                  , reinterpret_cast<void*>(call));
						
			//TODO check if there is a need to handle exception here
			try
			{
				auto result = utils::service::get_result(call->promise);
				return result;
			}
			catch (std::exception& exception)	{
				logger_.error("Connect request exception : {0}", exception.what());		
				return false;
			}			
		}		
	
		void heart_beat(const DataTypes::HeartbeatMessage& request) const 
		{
			auto queue = get_completion_queue<AsyncHeartbeatCall>();
			if (queue == nullptr)	return;

			auto call = new AsyncHeartbeatCall;
			set_call_options(call);
			call->reader = stub_->AsyncHeartbeat(&call->context, request, queue);
			call->reader->Finish(&call->response,&call->status, reinterpret_cast<void*>(call));

			try	{
				utils::service::get_result(call->promise);
			}
			catch (std::exception& exception) {
				//TODO handle broken promise as no response from server
				logger_.error("Coordinator client {0}", exception.what());
			}		
		}

		//TODO send with guid in metadata
		void update_devices(const DataTypes::DeviceUpdate& request) const 
		{
			auto queue = get_completion_queue<AsyncUpdateDevicesCall>();
			if (queue == nullptr)	return;

			auto call = new AsyncUpdateDevicesCall;
			set_call_options(call);
			call->reader = stub_->AsyncUpdateDevices(&call->context, request, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));
		}

		std::shared_ptr<DataTypes::GetResponse>
			get(const DataTypes::GetRequest& request) 
		{
			DataTypes::MessageBytes message;
			helpers::to_message_bytes(request, message);

			auto queue = get_completion_queue<AsyncGetRequestCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncGetRequestCall;
			set_call_options(call);
			call->reader = stub_->AsyncGet(&call->context, message, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			return utils::service::get_result(call->promise);
		}

		//TODO send with guid in metadata
		std::shared_ptr<DataTypes::CommitResponse>
			commit(const DataTypes::CommitRequest& request) 
		{
			DataTypes::MessageBytes message;
			helpers::to_message_bytes(request, message);

			auto queue = get_completion_queue<AsyncCommitRequestCall>();
			if (queue == nullptr)	return nullptr;

			auto call = new AsyncCommitRequestCall;
			set_call_options(call);
			call->reader = stub_->AsyncCommit(&call->context, message, queue);
			call->reader->Finish(&call->response, &call->status, reinterpret_cast<void*>(call));

			//TODO add try catch with timeout
			return utils::service::get_result(call->promise);
		}
		
	private:		
		void do_create_stub(std::shared_ptr<grpc::Channel> channel) override	{
			stub_ = Services::CoordinatorService::NewStub(channel);
		}

		std::string class_name() const override {
			return typeid(CoordinatorClientProtoApi).name();
		}
		
		std::unique_ptr<Services::CoordinatorService::Stub> stub_;

		CoordinatorClientProtoApi(const CoordinatorClientProtoApi&) = delete;
		CoordinatorClientProtoApi& operator=(const CoordinatorClientProtoApi&) = delete;
	};
}

#endif