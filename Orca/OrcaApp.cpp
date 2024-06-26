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
	void OrcaApp::OnUpdate()
	{
		
	}

	void OrcaApp::Run()
	{
		OrcaWindow::Init();
		OrcaWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		Renderer::Init();

		//// TEXTURE ////
		Orca::Image pic{ "../Orca/Assets/Images/Sun.png" };

		while (true)
		{
			//Game is stuck in this while loop
			Renderer::Get()->ClearScreen();

			OnUpdate();

			Renderer::Get()->Draw(pic, 100, 200);

			OrcaWindow::GetWindow()->SwapBuffers();
			OrcaWindow::GetWindow()->PollEvents();
		}
	}
}
