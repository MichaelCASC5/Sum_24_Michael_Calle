#include "pch.h"

#include "WindowGLFW.h"
#include "GLFW/glfw3.h"
#include "Utilities.h"

namespace Orca
{
	void WindowGLFW::CreateWindow(int width, int height, const std::string& windowName)// l value
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			ORCA_ERROR("ERROR: Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);

		SetDefaultCallbacks();
	}

	void WindowGLFW::CreateWindow(int width, int height, const std::string&& windowName)// r value
	{
		mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		if (mWindow == NULL)
		{
			ORCA_ERROR("ERROR: Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);

		SetDefaultCallbacks();
	}

	int WindowGLFW::GetWidth() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width{ 0 };
		int height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}

	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwTerminate();
	}

	void WindowGLFW::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		mCallbacks.KeyPressedCallback = newCallback;
	}

	void WindowGLFW::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		mCallbacks.KeyReleasedCallback = newCallback;
	}

	void WindowGLFW::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		mCallbacks.WindowCloseCallback = newCallback;
	}

	/*
	* Window Events
	*/
	void WindowGLFW::SetDefaultCallbacks()
	{
		// user pointer
		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (action == GLFW_PRESS)
			{
				Callbacks* ptrCallbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressedEvent event{ key };
				ptrCallbacks->KeyPressedCallback(event);
			}
			else if (action == GLFW_RELEASE)
			{
				Callbacks* ptrCallbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleasedEvent event{ key };
				ptrCallbacks->KeyReleasedCallback(event);
			}
			});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* ptrCallbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

			WindowCloseEvent event;
			ptrCallbacks->WindowCloseCallback(event);
			});
	}
}
