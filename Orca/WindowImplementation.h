#pragma once

#include "pch.h"

namespace Orca
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;// l value
		virtual void CreateWindow(int width, int height, const std::string&& windowName) = 0;// r value
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual ~WindowImplementation() {};
	};
}
