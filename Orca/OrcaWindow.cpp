#include "pch.h"

#include "OrcaWindow.h"

namespace Orca
{
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
}
