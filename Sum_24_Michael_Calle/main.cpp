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

		map.LoadBackgroundImage("../Orca/Assets/Images/Background.png");
		/*std::vector<std::vector<bool>> util;
		for (int i{ 0 }; i < 118; i++)
		{
			util.push_back(std::vector<bool>(1000, false));
		}
		for (int i{ 0 }; i < 682; i++)
		{
			util.push_back(std::vector<bool>(1000, true));
		}
		map.LoadMapPassability(util);

		unit.SetSpeed({ 10, 1 });*/
	}
	
	//This method is virtual and declared in OrcaApp
	//It will be started on each game loop, does everything that needs to be done between frames to create the next frame
	//Where majority of the work happens
	virtual void OnUpdate() override
	//Override is similar to const, not mandatory but helpful
	//It tells the C++ compiler this is not the first time this method was declared, but is another version
	//If you can allow the compiler to do error checking, do it
	{
		physics.NextPosition(unit, map);
		Orca::Renderer::Get()->Draw(map);
		Orca::Renderer::Get()->Draw(unit);
		
		//ORCA_LOG("Running"<<"\n");
		//Orca::Renderer::Get()->Draw(pic, x, 200);
		// x += 1;
	}

private:
	Orca::Image pic{ "../Orca/Assets/Images/Sun.png" };
	Orca::Unit unit{ "../Orca/Assets/Images/Sun.png", {100, 200} };
	Orca::Map map;
	Orca::Physics physics;

	int x{ 100 };
	void MyKeyPressedCallback(const Orca::KeyPressedEvent& key) {
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			//x += 40;
			unit.UpdateXBy(40);
		}
	}
};

GAME_ORCA_START(BestGame);
//physics and map class not necessary
//uniquenesses text file in game (custom additions)
