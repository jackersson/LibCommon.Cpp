#ifndef ServiceHelpers_INCLUDED
#define ServiceHelpers_INCLUDED

#include <include/grpc++/impl/codegen/completion_queue.h>
#include "request_handler_types.hpp"

namespace services_api
{	
	typedef std::vector<std::pair<std::string, std::string>> Metadata;

	//*****************************
	namespace helpers
	{
		inline void set_deadline(grpc::ClientContext& context, uint32_t seconds)
		{
			auto deadline =
				std::chrono::system_clock::now() + std::chrono::seconds(seconds);
			context.set_deadline(deadline);
		}

		inline std::pair<std::string, std::string>
			               get_metadata_pair( const std::string& id
											                , const std::string& value ) 
		{
			return std::pair<std::string, std::string>(id, value);
		}

		inline
			void set_metadata( grpc::ClientContext& context
				                , const Metadata& metadata)
		{
			if (metadata.size() <= 0)
				return;
			for (auto item : metadata)
				context.AddMetadata(item.first, item.second);
		}

		inline
			void set_metadata(grpc::ClientContext& context
				, const std::pair<std::string, std::string>& metadata)
		{
			context.AddMetadata(metadata.first, metadata.second);
		}

		template <typename T>
		grpc::CompletionQueue* get_completion_queue(const ClientRequestHandlers& handlers)
		{
			auto it = handlers.find(typeid(T).name());
			if (it == handlers.end())
				return nullptr;
			return it->second.completion_queue.get();
		}
	}
}

#endif