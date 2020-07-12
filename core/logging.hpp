#pragma once

#ifdef DEBUG_LOG
	#define LOG_INIT(...) logging::init(__VA_ARGS__)
	#define LOG_QUIT(...) logging::quit(__VA_ARGS__)
	#define LOG(...) logging::log(__VA_ARGS__)
	#define WARN(...) logging::warn(__VA_ARGS__)
	#define ERROR(...) logging::error(__VA_ARGS__)

	//define the logging namespace
	namespace logging {
		void init(const char* out, const char* err);
		void quit();
		void log(const char* str);
		void warn(const char* str);
		void error(const char* str);
	}
#else
	//empty - strip out the calls
	#define LOG_INIT(...)
	#define LOG_QUIT(...)
	#define LOG(...)
	#define WARN(...)
	#define ERROR(...)
#endif
