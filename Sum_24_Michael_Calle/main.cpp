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

		ORCA_LOG("Game Started");

		auto unit = std::make_unique<Orca::Unit>( "../Orca/Assets/Images/Sun.png", Orca::Coordinates{ 100, 200, 0 } );

		for (int i = 0; i < 10; i++)
		{
			auto asteroid1 = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Sun.png", Orca::Coordinates{ 50, 0, 200 - i * 50.0 });
			scene.push_back(std::move(asteroid1));

			//auto asteroid = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Asteroid.png", Orca::Coordinates{ 0, 0, 20 });
			//scene.push_back(std::move(asteroid));
		}
	}

	virtual void OnUpdate() override
	{
		// Do computations
		for (int i = 0; i < scene.size(); i++)
		{
			scene[i]->Reset(cam);
			scene[i]->RotateZ(cam);
			scene[i]->RotateY(cam);
			scene[i]->RotateX(cam);
			scene[i]->Project(cam);
		}

		// Draw units
		for (int i = 0; i < scene.size(); i++)
		{
			Orca::Renderer::Get()->Draw(*scene[i]);
		}
	}

private:

	std::vector<std::unique_ptr<Orca::Unit>> scene;
	Orca::Camera cam;

	void MyKeyPressedCallback(const Orca::KeyPressedEvent& key) {
		
		//Arrow keys
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			//scene[0]->UpdateXBy(40);
			cam.roll(10);
		}
		else if(key.GetKey() == ORCA_KEY_LEFT)
		{
			cam.roll(-10);
		}
		else if (key.GetKey() == ORCA_KEY_UP)
		{
			cam.pitch(10);
		}
		else if (key.GetKey() == ORCA_KEY_DOWN)
		{
			cam.pitch(-10);
		}

		// WASD
		if (key.GetKey() == ORCA_KEY_D)
		{
			cam.updateXBy(50);
		}
		else if (key.GetKey() == ORCA_KEY_A)
		{
			cam.updateXBy(-50);
		}
		else if (key.GetKey() == ORCA_KEY_W)
		{
			cam.updateZBy(50);
		}
		else if (key.GetKey() == ORCA_KEY_S)
		{
			cam.updateZBy(-50);
		}

		
		else if (key.GetKey() == ORCA_KEY_SPACE)
		{
			cam.updateYBy(50);
		}
		else if (key.GetKey() == ORCA_KEY_LEFT_CONTROL)
		{
			cam.updateYBy(-50);
		}
	}
};

GAME_ORCA_START(BestGame);
//physics and map class not necessary
//uniquenesses text file in game (custom additions)
