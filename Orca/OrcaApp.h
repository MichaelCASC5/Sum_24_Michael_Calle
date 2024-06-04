#pragma once

#include "Utilities.h"

//Base class

namespace Orca
{	
	class ORCA_API OrcaApp
	{
	public:
		//Virtual means double check who is calling on update method, what is the type of the obj calling?
		//When you plan to override methods it means you can override the method
		//Check the type of the obj that calls, and run the appriopriate version of the method
		virtual void OnUpdate();

		void Run();

	private:

	};
}
