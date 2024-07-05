#include "Orca.h"
#include <iostream>

class BestGame : public Orca::OrcaApp
{
	//All public methods are included in BestGame (inheritance)
public:
	BestGame()
	{
		SetKeyPressedCallback([this](const Orca::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
		});
	}
	
	//This method is virtual and declared in OrcaApp
	//It will be started on each game loop, does everything that needs to be done between frames to create the next frame
	//Where majority of the work happens
	virtual void OnUpdate() override
	//Override is similar to const, not mandatory but helpful
	//It tells the C++ compiler this is not the first time this method was declared, but is another version
	//If you can allow the compiler to do error checking, do it
	{
		//ORCA_LOG("Running"<<"\n");
		Orca::Renderer::Get()->Draw(pic, x, 200);
		// x += 1;
	}
private:
	Orca::Image pic{ "../Orca/Assets/Images/Sun.png" };

	int x{ 100 };
	void MyKeyPressedCallback(const Orca::KeyPressedEvent& key) {
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			x += 40;
		}
	}
};

GAME_ORCA_START(BestGame);
