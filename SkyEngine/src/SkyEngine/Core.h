#pragma once
#ifdef SE_PLATFORM_WINDOWS
//for actual SkyEngine(SE) project not Sandbox.
	#ifdef SE_BUILD_DLL
		#define SKYENGINE_API __declspec(dllexport) //define as export
	#else
		#define SKYENGINE_API __declspec(dllimport) //define as import
	#endif
#else
	#error Sky Engine only supports Windows! 
	//only if #ifdef SE_PLATFORM_WINDOWS generates ERROR.
#endif // SE_PLATFORM_WINDOWS (for windows platform only . . .)

