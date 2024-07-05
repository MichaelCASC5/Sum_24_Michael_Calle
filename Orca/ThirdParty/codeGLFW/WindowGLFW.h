#pragma once

#include "WindowImplementation.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Orca
{
	class WindowGLFW : public WindowImplementation// not meant to be used by the user directly
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;// l value
		virtual void CreateWindow(int width, int height, const std::string&& windowName) override;// r value
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback) override;
		virtual void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback) override;
		virtual void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback) override;

		WindowGLFW();
		~WindowGLFW();

	private:
		struct Callbacks
		{
			std::function<void(const KeyPressedEvent&)> KeyPressedCallback{ [](const KeyPressedEvent&) {} };
			std::function<void(const KeyReleasedEvent&)> KeyReleasedCallback{ [](const KeyReleasedEvent&) {} };
			std::function<void(const WindowCloseEvent&)> WindowCloseCallback{ [](const WindowCloseEvent&) {} };
		} mCallbacks;

		GLFWwindow* mWindow{ nullptr };

		void SetDefaultCallbacks();
	};
}
