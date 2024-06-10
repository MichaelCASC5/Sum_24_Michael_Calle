#pragma once

#include "pch.h"
#include "Utilities.h"
#include "WindowImplementation.h"

namespace Orca
{
	class ORCA_API OrcaWindow
	{
	public:
		static void Init();
		static std::shared_ptr<OrcaWindow> GetWindow();

		void CreateWindow(int width, int height, const std::string& windowName);//l value
		void CreateWindow(int width, int height, std::string&& windowName);//r value
		int GetWidth() const;
		int GetHeight() const;
		void SwapBuffers();
		void PollEvents();

	private:
		//WindowImplementation* mImplementation;//distinguish class parameters from function local vars
		//classic C pointer / raw pointer
		OrcaWindow();
		inline static std::shared_ptr<OrcaWindow> mInstance{ nullptr };

		std::unique_ptr<WindowImplementation> mImplementation{nullptr};
	};
}
