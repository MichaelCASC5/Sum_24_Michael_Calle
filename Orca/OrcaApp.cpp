#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "OrcaApp.h"
#include "OrcaWindow.h"
#include "Image.h"
#include "Shaders.h"
#include "stb_image.h"
#include "Renderer.h"

namespace Orca
{
	OrcaApp::OrcaApp()
	{
		OrcaWindow::Init();
		OrcaWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		Renderer::Init();

		SetFrameRate(DEFAULT_FRAME_RATE);

		SetWindowCloseCallback([this] (const WindowCloseEvent & event) { DefaultWindowCloseCallback(event); });
	}

	void OrcaApp::OnUpdate()
	{
		
	}

	void OrcaApp::Run()
	{

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue)
		{
			//Game is stuck in this while loop
			Renderer::Get()->ClearScreen();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			OrcaWindow::GetWindow()->SwapBuffers();
			OrcaWindow::GetWindow()->PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void OrcaApp::SetFrameRate(int newFrameRate)
	{
		mFrameRate = newFrameRate;
		mFrameDuration = std::chrono::milliseconds{ 1000 } / mFrameRate;
	}

	void OrcaApp::SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback)
	{
		OrcaWindow::GetWindow()->SetKeyPressedCallback(newCallback);
	}

	void OrcaApp::SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback)
	{
		OrcaWindow::GetWindow()->SetKeyReleasedCallback(newCallback);
	}

	void OrcaApp::SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback)
	{
		OrcaWindow::GetWindow()->SetWindowCloseCallback(newCallback);
	}

	void OrcaApp::DefaultWindowCloseCallback(const WindowCloseEvent& event)
	{
		mShouldContinue = false;
	}
}
