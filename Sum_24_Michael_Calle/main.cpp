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

		for (int i = 0; i < 1; i++)
		{
			auto asteroid = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Asteroid.png", Orca::Coordinates{ 0, 0, 20 });
			scene.push_back(std::move(asteroid));

			auto asteroid1 = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Asteroid.png", Orca::Coordinates{ 50, 0, 200 });
			scene.push_back(std::move(asteroid1));
		}
	}

	virtual void OnUpdate() override
	{
		// Do computations
		for (int i = 0; i < scene.size(); i++)
		{
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
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			//scene[0]->UpdateXBy(40);
			cam.updateXBy(2);
		}
	}
};

GAME_ORCA_START(BestGame);
//physics and map class not necessary
//uniquenesses text file in game (custom additions)
