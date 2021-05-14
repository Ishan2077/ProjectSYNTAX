#pragma once

#include "Core.h"
//#include "Events/Event.h"
//#include <Platform/Windows/WindowsWindow.h>
#include "Window.h"
#include "SkyEngine/LayerStack.h"
#include "SkyEngine/Events/Event.h"
#include "SkyEngine/Events/ApplicationEvent.h"
//#include "SkyEngine/Events/ApplicationEvent.h"

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

			void OnEvent(Event& e);
			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in CLIENT.
	Application* CreateApplication();
}