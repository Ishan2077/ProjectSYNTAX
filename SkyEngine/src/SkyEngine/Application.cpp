#include "Application.h"
/*
	The dllexport and dllimport storage-class attributes are 
	Microsoft-specific extensions to the C and C++ languages. 
	You can use them to export and import functions, data, and
	objects to or from a DLL. These attributes explicitly define 
	the DLL's interface to its client, which can be
	the executable file or another DLL. Also are Macros.
*/
namespace SkyEngine {
	//carries SkyEngine's application.
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		while (true); // infinite running of application
	}
}
