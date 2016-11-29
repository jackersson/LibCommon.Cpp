#include <filesystem>
#include <logging/logger.hpp>

using namespace spdlog;

namespace contracts
{
	namespace logging
	{
		void Logger::initialize()
		{
			if (initialized_)
				return;

			auto path = std::experimental::filesystem::current_path();
			path.concat("\\logs\\");
			create_directory(path);

			loggers_.push_back(daily_logger_mt("daily_logger", "logs/daily", 2, 30));
			loggers_.push_back(stdout_logger_mt("console", true));
			set_pattern("[%H:%M:%S %z] %v");
			initialized_ = true;
		}

		std::list<std::shared_ptr<logger>> Logger::loggers_;
		bool Logger::initialized_;
	}
}