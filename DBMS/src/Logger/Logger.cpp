#include "Logger.h"

namespace Logger {

	FileSink::FileSink(const std::string& fileName, std::size_t buffer_size = 4096u) : m_buffer(buffer_size),
		m_output(fileName), m_offset(0u) {
		if (!m_output.is_open()) {
			throw std::runtime_error("File was not created!");
		}
	}

	void FileSink::flush() {
		if (m_offset != 0u) {
			m_output.write(m_buffer.data(), m_offset);
			m_offset = 0u;
		}
	}

	void FileSink::write(const std::string& data) {
		const std::size_t data_size = data.size();
		if (data_size + m_offset >= m_buffer.size()) {
			flush();
		}

		std::copy(begin(data), end(data), begin(m_buffer) + m_offset);
		m_offset += data_size;
	}

	FileSink::~FileSink() {
		flush();
	}

	Logger::Logger(std::string& fileName) :m_sink(fileName) {
	}

	void Logger::log(Logger::Logger::Level level, const char* source, const std::string& message) {
		const std::string formated_msg = "[" + LevelStr[level] + "] - " + source + " - " + message + '\n';
		m_sink.write(formated_msg);
	};
}