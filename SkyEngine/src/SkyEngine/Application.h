#pragma once

#include "Core.h"

namespace SkyEngine 
{
	class SKYENGINE_API Application 
	{
		public:
			//class __declspec(dllexport) Application  now becomes
			//class SKYENGINE_API Application
			//sends the application to Sandbox(exports).
			Application();

			virtual ~Application(); 
			/*inherited / subclassed by Sandbox 
			Application(Sandbox's Application.cpp file). */

			void Run(); //runs our application
	};

	//To be defined in CLIENT.
	Application* CreateApplication();
}

