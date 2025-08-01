#pragma once

#include "logger.h"

namespace Debug {

	inline void SetLevel(LogLevel level) {
		Logger::SetLevel(level);
	}

/* 
 * The current structure should be refactored into a cleaner and 
 * more flexible design to make future development and 
 * modifications easier.
 */

#ifndef NDEBUG // Debug

	inline void Info(const std::string & message) {
		Logger::Info(message);
	}

	inline void Error(const std::string & message) {
		Logger::Error(message);
	}

	inline void Warning(const std::string & message) {
		Logger::Warning(message);
	}

	inline void Log(const std::string & message, LogLevel level = LogLevel::Info, const char* file = nullptr, int line = 0) {
		Logger::Log(message, level);
	}

#else // Release

	inline void Info(const std::string&) {}
	inline void Error(const std::string&) {}
	inline void Warning(const std::string&) {}
	inline void Log(const std::string&, LogLevel = LogLevel::Info, const char* file = nullptr, int line = 0) {}

#endif

};