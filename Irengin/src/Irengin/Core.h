#pragma once

#ifdef IRNGN_PLATFORM_WINDOWS
	#ifdef IRNGN_BUILD_DLL
		#define IRNGN_API __declspec(dllexport)
	#else
		#define	IRNGN_API __declspec(dllimport)
	#endif
#else
	#error Irengin only works on Windows!
#endif