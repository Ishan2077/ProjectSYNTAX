#include <SkyEngine.h>

class ExampleLayer : public SkyEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SE_INFO("ExampleLayer::Update");
	}

	void OnEvent(SkyEngine::Event& event) override
	{
		SE_TRACE("{0}", event);
	}

};

class Sandbox : public SkyEngine::Application
{
public:
	Sandbox()
	{

		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};
SkyEngine::Application* SkyEngine::CreateApplication()
{
	return new Sandbox();
}