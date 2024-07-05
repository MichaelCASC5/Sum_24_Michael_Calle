#pragma once

#include "pch.h"
#include "Utilities.h"
#include "WindowImplementation.h"
#include "Events.h"

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

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& newCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& newCallback);
		void SetWindowCloseCallback(const std::function<void(const WindowCloseEvent&)>& newCallback);

	private:
		//WindowImplementation* mImplementation;//distinguish class parameters from function local vars
		//classic C pointer / raw pointer
		OrcaWindow();
		inline static std::shared_ptr<OrcaWindow> mInstance;
		//initializes object, inline with static intializes here
		//without inline, you have to intialize somewhere else

		//remove blank implementations

		std::unique_ptr<WindowImplementation> mImplementation;
	};
}
