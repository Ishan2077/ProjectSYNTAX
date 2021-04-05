#pragma once
#include "../sepch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SkyEngine
{
	class SKYENGINE_API Log
	{
	public:
		static void Init(); //initialization

		inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr < spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr <spdlog::logger> s_CoreLogger;
		static std::shared_ptr <spdlog::logger> s_ClientLogger;
	};
}
/*creating macros for Logging(info and warn)
	
	SkyEngine::Log::GetCoreLogger()->warn("Initialized Log!");
	SkyEngine::Log::GetClientLogger()->info("Hello!");

*/
// CORE LOG MACROS
#define SE_CORE_TRACE(...)		:: SkyEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)		:: SkyEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)		:: SkyEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)		:: SkyEngine::Log::GetCoreLogger()->error(__VA_ARGS__) // ... for variable number of arguments
#define SE_CORE_TRACE(...)		:: SkyEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

// CLIENT LOG MACROS
#define SE_TRACE(...)			:: SkyEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)			:: SkyEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)			:: SkyEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)			:: SkyEngine::Log::GetClientLogger()->error(__VA_ARGS__) // ... for variable number of arguments
#define SE_TRACE(...)			:: SkyEngine::Log::GetClientLogger()->trace(__VA_ARGS__)

