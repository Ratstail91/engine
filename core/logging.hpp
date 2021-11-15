#pragma once

#include "core.hpp"

#ifdef DEBUG_LOG
	#define LOG_INIT(...) logging::init(__VA_ARGS__)
	#define LOG_QUIT(...) logging::quit(__VA_ARGS__)
	#define LOG(...) logging::log(__VA_ARGS__)
	#define WARN(...) logging::warn(__VA_ARGS__)
	#define ERROR(...) logging::error(__VA_ARGS__)

	//define the logging namespace
	namespace logging {
		ENGINE_API void init(const char* out, const char* err);
		ENGINE_API void quit();
		ENGINE_API void log(const char* str);
		ENGINE_API void warn(const char* str);
		ENGINE_API void error(const char* str);
	}
#else
	//empty - strip out the calls
	#define LOG_INIT(...)
	#define LOG_QUIT(...)
	#define LOG(...)
	#define WARN(...)
	#define ERROR(...)
#endif

namespace logging {
	ENGINE_API bool getLoggingInitialized();
}