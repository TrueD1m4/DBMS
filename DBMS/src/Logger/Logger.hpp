#pragma once
#pragma warning(disable : 26812)

#ifndef LOGGER
#define LOGGER

#include <fstream>
#include <array>
#include <string>
#include <vector>
#include <thread>

namespace logger {

	class FileSink {
	public:

		FileSink() = default;
		FileSink(const std::string& fileName, std::size_t buffer_size);

		void write(const std::string& data);

		~FileSink();

	private:
		std::vector<char> m_buffer;
		std::size_t m_offset;
		std::ofstream m_output;

		void flush();
	};

	class Logger {
		
	public:
		enum Level {
			TRACE_LVL,
			DEBUG_LVL,
			INFO_LVL,
			WARN_LVL,
			ERROR_LVL,
			FATAL_LVL
		};

		Logger() = default;
		Logger(std::string& fileName);

		static inline std::array<std::string, Level::FATAL_LVL + 1u> LevelStr = {
			"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
		};

		void log(Level level, const char* source, const std::string& message);

	private:
		FileSink m_sink;
	};
}

inline logger::Logger& getLogger() {
	std::string path = "data.log";
	static logger::Logger logger(path);

	return logger;
}

// TODO: Realize thread that will LOGS

#define STR_(x) #x
#define STR(x) STR_(x)

//macroses 
#define TRACE_LOG(msg) getLogger().log(logger::Logger::Level::TRACE_LVL, __FILE__ " : " STR(__LINE__), (msg))
#define DEBUG_LOG(msg) getLogger().log(logger::Logger::Level::DEBUG_LVL, __FILE__ " : " STR(__LINE__), (msg))
#define INFO_LOG(msg) getLogger().log(logger::Logger::Level::INFO_LVL, __FILE__ " : " STR(__LINE__), (msg))
#define WARN_LOG(msg) getLogger().log(logger::Logger::Level::WARN_LVL, __FILE__ " : " STR(__LINE__), (msg))
#define ERROR_LOG(msg) getLogger().log(logger::Logger::Level::ERROR_LVL, __FILE__ " : " STR(__LINE__), (msg))
#define FATAL_LOG(msg) getLogger().log(logger::Logger::Level::FATAL_LVL, __FILE__ " : " STR(__LINE__), (msg))


#endif // !LOGGER