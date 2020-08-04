#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#elif defined PLATFORM_LINUX
	#define ENGINE_API
#else
	#error This engine doesnt support this platform!
#endif