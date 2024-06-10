#include "pch.h"
#include "OrcaApp.h"
#include "OrcaWindow.h"

namespace Orca
{
	void OrcaApp::OnUpdate()
	{
		
	}

	void OrcaApp::Run()
	{
		OrcaWindow::Init();
		OrcaWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		while (true)
		{
			//Game is stuck in this while loop
			OnUpdate();

			OrcaWindow::GetWindow()->SwapBuffers();
			OrcaWindow::GetWindow()->PollEvents();
		}
	}
}
