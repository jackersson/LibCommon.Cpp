#ifndef ServiceUtils_Included
#define ServiceUtils_Included

#include <future>
#include <fstream>


namespace utils
{
	namespace service {
		
		template <typename T>
		T get_result(std::promise<T>& promise
			, std::chrono::milliseconds time_duration = std::chrono::milliseconds(1000))
		{
			auto future = promise.get_future();
			return get_result(future, time_duration);
		}

		template <typename T>
		T get_result(std::future<T>& future
			, std::chrono::milliseconds time_duration = std::chrono::milliseconds(1000))
		{
			std::chrono::milliseconds step(50);
			const auto max_try_count = time_duration.count() / step.count();
			auto try_count = 0;
			while (future.wait_for(step) == std::future_status::timeout
				&& try_count < max_try_count)
				try_count++;

			auto failed = try_count >= max_try_count;
			if (failed)
				throw std::exception("timeout exception");

			return future.get();
		}
		
		inline
		void create_file(const std::string& filename)
		{
			std::fstream outfile(filename, std::fstream::out);
			outfile.close();
		}

		
	}
}

#endif
