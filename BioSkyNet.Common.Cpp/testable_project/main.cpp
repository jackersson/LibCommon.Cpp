#include <memory>
#include <iostream>
#include <thread>
#include <future>
#include "thread_pool.hpp"

/*
#include <grpc++/grpc++.h>

#include <services/unit_service.grpc.pb.h>
#include "test.hpp"
//#include <async_service_base.hpp>
using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;

using Services::UnitService;

class ServerImpl final : public services_api::AsyncServiceBase<UnitService::AsyncService> {
	
public:
	ServerImpl(contracts::services::IServiceAddress& address,
		       ServerBuilder* server_builder) 
		: AsyncServiceBase(address, server_builder)
	//: active_(true)
	{
		bind(server_builder);
		//init();
	}

	void bind(ServerBuilder* server_builder) override
	{
		AsyncServiceBase::bind(server_builder);
		initialize_handler<CallData>(server_builder);
	}

	void de_init() override
	{
		stop();
	}
	void init() override
	{		

		//initialize_handler<CallData>();

	}

	std::string class_name() const override {
		return typeid(ServerImpl).name();
	}

	~ServerImpl() {
		//server_->Shutdown();
		//active_ = false;

		// Always shutdown the completion queue after the server.
		//cq_->Shutdown();
		//thread_.join();
	}

	template <typename T>
	void initialize_handler(ServerBuilder* server_builder)
	{
		add_rpc_handler    <T>(server_builder);
		add_handler_creator<T>();
	}

	template <typename T>
	void add_handler_creator()
	{
		services_api::CreateRequestHandlerFunc func
			= [this](ServerCompletionQueue* queue)
		{
			T::create(&service_, queue);
		};
		add_handler_factory_method<T>(func);
	}

	// There is no shutdown handling in this code.
	void Run() {
		//std::string server_address("0.0.0.0:50051");
		//ServerBuilder builder;
		// Listen on the given address without any authentication mechanism.
		//builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
		// Register "service_" as the instance through which we'll communicate with
		// clients. In this case it corresponds to an *asynchronous* service.
		//builder.RegisterService(&service_);
		// Get hold of the completion queue used for the asynchronous communication
		// with the gRPC runtime.
		//cq_ = builder.AddCompletionQueue();
		// Finally assemble the server.
	//	server_ = builder.BuildAndStart();
		//std::cout << "Server listening on " << server_address << std::endl;

		//thread_ = std::thread([this]()
	//	{
		//	HandleRpcs();
		//});
	
	}

private:

	std::thread thread_;
	// Class encompasing the state and logic needed to serve a request.
	class CallData {
	public:
		~CallData()
		{
			std::cout << "destroyed" << std::endl;
		}
		// Take in the "service" instance (in this case representing an asynchronous
		// server) and the completion queue "cq" used for asynchronous communication
		// with the gRPC runtime.
		CallData(UnitService::AsyncService* service, ServerCompletionQueue* cq)
			: service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
			// Invoke the serving logic right away.
			proceed();
		}

		static void create(UnitService::AsyncService*  service
			, ServerCompletionQueue* completion_queue			)
		{
			new CallData(service, completion_queue);
		}

		void proceed( bool flag = false) {
			if (status_ == CREATE) {
				// Make this instance progress to the PROCESS state.
				status_ = PROCESS;

				// As part of the initial CREATE state, we *request* that the system
				// start processing SayHello requests. In this request, "this" acts are
				// the tag uniquely identifying the request (so that different CallData
				// instances can serve different requests concurrently), in this case
				// the memory address of this CallData instance.
				service_->RequestCheckDevice(&ctx_, &request_, &responder_, cq_, cq_,
					this);
			}
			else if (status_ == PROCESS) {
				// Spawn a new CallData instance to serve new clients while we process
				// the one for this CallData. The instance will deallocate itself as
				// part of its FINISH state.
				new CallData(service_, cq_);

				// The actual processing.
				std::string prefix("Hello ");
				reply_.set_message(prefix + request_.device_name());

				// And we are done! Let the gRPC runtime know we've finished, using the
				// memory address of this instance as the uniquely identifying tag for
				// the event.
				status_ = FINISH;
				responder_.Finish(reply_, Status::OK, this);
			}
			else {
				GPR_ASSERT(status_ == FINISH);
				// Once in the FINISH state, deallocate ourselves (CallData).
				delete this;
			}
		}

	private:
		// The means of communication with the gRPC runtime for an asynchronous
		// server.
		UnitService::AsyncService* service_;
		// The producer-consumer queue where for asynchronous server notifications.
		ServerCompletionQueue* cq_;
		// Context for the rpc, allowing to tweak aspects of it such as the use
		// of compression, authentication, as well as to send metadata back to the
		// client.
		ServerContext ctx_;

		// What we get from the client.
		DataTypes::Device request_;
		// What we send back to the client.
		DataTypes::CheckMsg reply_;

		// The means to get back to the client.
		ServerAsyncResponseWriter<DataTypes::CheckMsg> responder_;

		// Let's implement a tiny state machine with the following states.
		enum CallStatus { CREATE, PROCESS, FINISH };
		CallStatus status_;  // The current serving state.
	};
	/*
	// This can be run in multiple threads if needed.
	void HandleRpcs() {
		// Spawn a new CallData instance to serve new clients.
		new CallData(&service_, cq_.get());
		void* tag;  // uniquely identifies a request.
		bool ok;
		while (active_) {
			// Block waiting to read the next event from the completion queue. The
			// event is uniquely identified by its tag, which in this case is the
			// memory address of a CallData instance.
			// The return value of Next should always be checked. This return value
			// tells us whether there is any kind of event or cq_ is shutting down.
			GPR_ASSERT(cq_->Next(&tag, &ok));
			if  (ok)
			  static_cast<CallData*>(tag)->Proceed();
		}
	}
	

	//std::unique_ptr<ServerCompletionQueue> cq_;
	//UnitService::AsyncService service_;
	//std::unique_ptr<Server> server_;
};

class ServerManager
{
public:
	void start()
	{
		ServerBuilder builder;

		contracts::services::ServiceAddress sa("0.0.0.0", 50051);
		unit_service_ = std::make_unique<ServerImpl>(sa, &builder);

		server_ = builder.BuildAndStart();
		unit_service_->start();
	}

	void stop()
	{
		server_->Shutdown();
		unit_service_->stop();
	}

private:
	std::unique_ptr<Server>  server_;
	std::unique_ptr<ServerImpl> unit_service_;
};

void test()
{
	ServerManager server;
	server.start();

	std::cin.get();

	server.stop();
}
*/

void test()
{
	/*/
	auto t = std::async([]()
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "done st1" << std::endl;
	});
	*/
	utils::default_thread_pool::submit_job_nowait([]()
	{
		std::this_thread::sleep_for(std::chrono::seconds(3));
		std::cout << "done st1" << std::endl;
		//t.get();
	});

	/*
	auto f = std::async([]()
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "done st1" << std::endl;
	});
	*/
	//auto f = boost::async([]()
	//{
	//	std::this_thread::sleep_for(std::chrono::seconds(1));
	//	std::cout << "done st1" << std::endl;
	//}); 
		//.then([](boost::future<void>)
	//{std::this_thread::sleep_for(std::chrono::seconds(1)); });
}


int main(int argc, char** argv) {
	
	 test();

	 auto size = utils::default_thread_pool::thread_pool().size();

	std::cout << "done " << size << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	//test();
	std::cin.get();
	return 0;
}
