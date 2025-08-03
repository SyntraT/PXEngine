#pragma once

#include <mutex>
#include <condition_variable>
#include <thread>
#include "circular_buffer.h"
#include <cstdarg>

namespace debug {};

struct LogMessage {
    std::string text;
    int8_t level;
    const char* file;
    uint16_t line;
};

enum class LogLevel { 
	Info,
	Warning,
	Error			
};

class Logger {
public:
	static Logger& Instance() {
        static Logger instance;
        return instance;
	}
	
	void Info(const char* format, ...);

	void Warning(const char* format, ...);
	
	void Error(const char* format, ...);
	
	void Log(LogLevel level, const char* file, uint16_t line, const char* format, ...);
	void Log(LogLevel level, const char* format, ...);
	void Log(const char* format, ...);

	void SetLevel(LogLevel level);
	
	void Start(); // Start thread
	void Stop(); // Stop thread

private:
	Logger() = default;
    ~Logger() = default;

    Logger(const Logger&) = delete; // Delete copy constructor
    Logger& operator=(const Logger&) = delete; // Delete copy assignment operator

	void writeToConsole(const std::string & message, LogLevel level, const char* file = nullptr, uint16_t line = 0);

    void enqueueMessage(const char* format, va_list args, LogLevel level, const char* file = nullptr, uint16_t line = 0);
    void loggerThread();

	LogLevel currentLevel = LogLevel::Info;

	CircularBuffer<LogMessage, 1024> logBuffer;

	std::mutex mutex;
	std::condition_variable cv;

	std::thread thread;
	bool running = false;
};

#define LOG_INFO(msg, ...)    Logger::Instance().Log(LogLevel::Info,    __FILE__, __LINE__, msg, ##__VA_ARGS__)
#define LOG_WARNING(msg, ...)    Logger::Instance().Log(LogLevel::Warning,    __FILE__, __LINE__, msg, ##__VA_ARGS__)
#define LOG_ERROR(msg, ...)    Logger::Instance().Log(LogLevel::Error,    __FILE__, __LINE__, msg, ##__VA_ARGS__)