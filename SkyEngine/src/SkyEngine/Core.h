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
// SE_PLATFORM_WINDOWS (for windows platform only . . .)
#endif

#ifdef SE_ENABLE_ASSERTS
	#define SE_ASSERT(x, ...) { if(!(x)) { SE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define SE_core_assert(x, ...) { if(!(x)) {SE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}	
#else
	#define SE_ASSERT(x, ...)
	#define SE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)