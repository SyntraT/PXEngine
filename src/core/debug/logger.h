#pragma once

#include "iostream"
#include <sstream>

enum class LogLevel { 
	Info,
	Warning,
	Error			
};

class Logger {
public:
	static void SetLevel(LogLevel level);

	static void Info(const std::string & message);
	static void Warning(const std::string & message);
	static void Error(const std::string & message);
	static void Log(const std::string & message, LogLevel level = LogLevel::Info, const char* file = nullptr, int line = 0);
private:
	static void writeToConsole(const std::string & message, LogLevel level, const char* file = nullptr, int line = 0);
	inline static LogLevel currentLevel = LogLevel::Info;
};

#define LOG_INFO(msg)    Debug::Log(msg, LogLevel::Info,    __FILE__, __LINE__)
#define LOG_WARNING(msg) Debug::Log(msg, LogLevel::Warning, __FILE__, __LINE__)
#define LOG_ERROR(msg)   Debug::Log(msg, LogLevel::Error,   __FILE__, __LINE__)