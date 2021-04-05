#pragma once

#include "sepch.h"

#include "SkyEngine/Core.h"
#include "SkyEngine/Events/Event.h"

namespace SkyEngine {
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;


		WindowProps(const std::string& title = "Sky Engine",
			unsigned int width = 1200,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

		//Interface representing a desktop system based Window
	class SKYENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		//made it virtual because it is an interface and will be implemented per platform.
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps()); //returns Windows Window or Mac's Window, Implemented per platform.
		};
}