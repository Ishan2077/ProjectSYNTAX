#include "sepch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//using namespace std;
namespace SkyEngine {

	std::shared_ptr <spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr <spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$"); 
		/*[%T] timestamp ; %n is name of the logger ; 
		%v%$ message to be displayed.
		All will be wrapped under correct color(message to be displayed)
		*/
		s_CoreLogger = spdlog::stdout_color_mt("SkyEngine"); //mt is multi-threading
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP"); //mt is multi-threading
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}