#include "pch.h"
#include "OrcaApp.h"

namespace Orca
{
	void OrcaApp::OnUpdate()
	{
		
	}

	void OrcaApp::Run()
	{
		while (true)
		{
			//Game is stuck in this while loop
			OnUpdate();
		}
	}
}
