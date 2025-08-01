#include "logger.h"

void Logger::writeToConsole(const std::string & message, LogLevel level, const char* file, int line) {
	std::ostringstream oss;

	if(level < currentLevel) 
		return;

	// [LEVEL]
	switch (level) {
		case LogLevel::Info:
			oss << "[INFO] ";
			break;
		case LogLevel::Warning:
			oss << "\033[33m[WARNING] ";
			break;
		case LogLevel::Error:
			oss << "\033[31m[ERROR] ";
			break;
	}

	if (file && line > 0) {
		oss << "[" << file << ":" << line << "] ";
	}

	oss << message;

	// Reset color if needed
	if (level == LogLevel::Warning || level == LogLevel::Error)
		oss << "\033[0m";

	// Output to correct stream
	if (level == LogLevel::Error)
		std::cerr << oss.str() << std::endl;
	else
		std::cout << oss.str() << std::endl;
}

void Logger::SetLevel(LogLevel level) {
	currentLevel = level;
}

void Logger::Info(const std::string & message) {
	writeToConsole(message, LogLevel::Info);
}
void Logger::Warning(const std::string & message) {
	writeToConsole(message, LogLevel::Warning);
}
void Logger::Error(const std::string & message) {
	writeToConsole(message, LogLevel::Error);
}
void Logger::Log(const std::string & message, LogLevel level, const char* file, int line) {
	writeToConsole(message, level, file, line);
}