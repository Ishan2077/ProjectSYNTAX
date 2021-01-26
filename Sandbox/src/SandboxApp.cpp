#include<SkyEngine.h>

class Sandbox : public SkyEngine::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

SkyEngine::Application* SkyEngine::CreateApplication() {
	return new Sandbox();
}