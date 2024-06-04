#include "Orca.h"
#include <iostream>

class BestGame : public Orca::OrcaApp
{
	//All public methods are included in BestGame (inheritance)
	
	//This method is virtual and declared in OrcaApp
	//It will be started on each game loop, does everything that needs to be done between frames to create the next frame
	//Where majority of the work happens
	virtual void OnUpdate() override
	//Override is similar to const, not mandatory but helpful
	//It tells the C++ compiler this is not the first time this method was declared, but is another version
	//If you can allow the compiler to do error checking, do it
	{
		ORCA_LOG("Running"<<"\n");
	}
};

GAME_ORCA_START(BestGame);
