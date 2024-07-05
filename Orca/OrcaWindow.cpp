#include "pch.h"

#include "OrcaWindow.h"
#include "ThirdParty/codeGLFW/WindowGLFW.h"

namespace Orca
{
	OrcaWindow::OrcaWindow()
	{
#ifdef ORCA_GLFW
		mImplementation = std::unique_ptr<WindowGLFW>{new WindowGLFW};
#else
		#ERROR_ORCA_GLFW_ISNT_DEFINED
#endif
	}

	void OrcaWindow::Init()
	{
		if (!mInstance)
		{
			// OrcaWindow is a singleton, which is why we use (new OrcaWindow)
			mInstance = std::shared_ptr<OrcaWindow>(new OrcaWindow);
		}
	}

	std::shared_ptr<OrcaWindow> OrcaWindow::GetWindow()
	{
		return mInstance;
	}

	void OrcaWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mImplementation->CreateWindow(width, height, windowName);
	}

	void OrcaWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mImplementation->CreateWindow(width, height, std::move(windowName));//enforces r value, treats as temp content
	}

	int OrcaWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int OrcaWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	void OrcaWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void OrcaWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}

	void OrcaWindow::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		mImplementation->SetKeyPressedCallback(newCallback);
	}

	void OrcaWindow::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		mImplementation->SetKeyReleasedCallback(newCallback);
	}

	void OrcaWindow::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		mImplementation->SetWindowCloseCallback(newCallback);
	}

}
