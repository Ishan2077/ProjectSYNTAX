#pragma once

#ifdef SE_PLATFORM_WINDOWS

	extern SkyEngine::Application* SkyEngine::CreateApplication(); 
	//describe this function somewhere
	//else so that it runs our application.

	int main(int argc, char** argv) {
		
		auto app = SkyEngine::CreateApplication();
		app->Run();
		delete app;
	}
#endif // SE_PLATFORM_WINDOWS

