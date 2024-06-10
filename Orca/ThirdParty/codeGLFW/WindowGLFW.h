#pragma once

#include "WindowImplementation.h"
//#include "GLFW/glfw3.h"

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

		WindowGLFW();
		~WindowGLFW();

	private:
		GLFWwindow* mWindow{ nullptr };
	};
}
