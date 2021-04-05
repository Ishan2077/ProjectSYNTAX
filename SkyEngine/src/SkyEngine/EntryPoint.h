#pragma once

#ifdef SE_PLATFORM_WINDOWS

	extern SkyEngine::Application* SkyEngine::CreateApplication(); 
	//describe this function somewhere
	//else so that it runs our application.

	int main(int argc, char** argv) 
	{
		SkyEngine::Log::Init(); //initialize logs
		SE_CORE_WARN("Initialized Log!");
		int a = 5;
		SE_INFO("Hello! Var={0}", a);
		auto app = SkyEngine::CreateApplication();
		app->Run();
		delete app;
	}
#endif // SE_PLATFORM_WINDOWS

