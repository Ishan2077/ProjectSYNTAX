#include "sepch.h"
#include "Application.h"
#include <GLFW/glfw3.h>
#include "SkyEngine/Events/ApplicationEvent.h"
#include "G:\\Sky\\SkyEngine\\SkyEngine\\src\\SkyEngine\\Log.h"
/*
	The dllexport and dllimport storage-class attributes are 
	Microsoft-specific extensions to the C and C++ languages. 
	You can use them to export and import functions, data, and
	objects to or from a DLL. These attributes explicitly define 
	the DLL's interface to its client, which can be
	the executable file or another DLL. Also are Macros.
*/
namespace SkyEngine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	//carries SkyEngine's application.
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));//when we generate events, we are able to call this function
	}

	Application::~Application() 
	{

	}
	void Application::OnEvent(Event& e) 
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SE_CORE_TRACE("{0}", e);
	}

	void Application::Run() 
	{
		
		while (m_Running) 

		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}