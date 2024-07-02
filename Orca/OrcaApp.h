#pragma once

#include "pch.h"
#include "Utilities.h"

//Base class

namespace Orca
{	
	constexpr int DEFAULT_FRAME_RATE{ 60 }; // measured in frames per second

	class ORCA_API OrcaApp
	{
	public:
		OrcaApp();
		//Virtual means double check who is calling on update method, what is the type of the obj calling?
		//When you plan to override methods it means you can override the method
		//Check the type of the obj that calls, and run the appriopriate version of the method
		virtual void OnUpdate();
		void Run();
		void SetFrameRate(int newFrameRate);

	private:
		int mFrameRate{ 0 };
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{0};
	};
}
