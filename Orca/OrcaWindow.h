#pragma once

#include "pch.h"
#include "Utilities.h"

namespace Orca
{
	class ORCA_API OrcaWindow
	{
	public:
		
		void CreateWindow(int width, int height, const std::string& windowName);//l value
		void CreateWindow(int width, int height, std::string&& windowName);//r value
		int GetWidth() const;
		int GetHeight() const;

	private:
		//WindowImplementation* mImplementation;//distinguish class parameters from function local vars
		//classic C pointer / raw pointer

		std::unique_ptr<WindowImplementation> mImplementation{nullptr};
	};
}
