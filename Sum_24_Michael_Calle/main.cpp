#include "Orca.h"
#include <iostream>
#include <random>

class BestGame : public Orca::OrcaApp
{
	//All public methods are included in BestGame (inheritance)
public:
	BestGame()
	{
		SetKeyPressedCallback([this](const Orca::KeyPressedEvent& key) {
			MyKeyPressedCallback(key);
			});

		SetKeyReleasedCallback([this](const Orca::KeyReleasedEvent& key) {
			MyKeyReleasedCallback(key);
				});

		ORCA_LOG("Game Started");

		// cam.setPosition(0, 0, -1000);

		// Mersenne Twister
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(0, 1.0); // range [0,1)

		for (int i = 0; i < 25; i++)
		{

			auto asteroid1 = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Tree.png", Orca::Coordinates
			{
				5000 * dis(gen) - 2500,
				0,
				5000 * dis(gen) - 2500
			});

			/*auto asteroid1 = std::make_unique<Orca::Unit>("../Orca/Assets/Images/Asteroid.png", Orca::Coordinates
				{
					10.0,
					10.0,
					10.0 - i * 20.0
				});*/

			scene.push_back(std::move(asteroid1));
		}
	}

	virtual void OnUpdate() override
	{
		/*
		* DO COMPUTATIONS
		*/
		/*
		* Camera movement
		*/

		double translationSpeed = 10;
		double rotationSpeed = 10;

		//Arrow keys
		if (keybuffer.getRightArrow())
		{
			cam.yaw(rotationSpeed);
		}
		if (keybuffer.getLeftArrow())
		{
			cam.yaw(-rotationSpeed);
		}
		if (keybuffer.getUpArrow())
		{
			cam.pitch(rotationSpeed);
		}
		if (keybuffer.getDownArrow())
		{
			cam.pitch(-rotationSpeed);
		}

		// WASD
		if (keybuffer.getD())
		{
			cam.left(translationSpeed);
		}
		if (keybuffer.getA())
		{
			cam.left(-translationSpeed);
		}
		if (keybuffer.getW())
		{
			cam.forward(translationSpeed);
		}
		if (keybuffer.getS())
		{
			cam.forward(-translationSpeed);
		}


		if (keybuffer.getSpace())
		{
			cam.updateYBy(translationSpeed);
		}
		if (keybuffer.getCtrl())
		{
			cam.updateYBy(-translationSpeed);
		}

		/*
		* Do scene computations
		*/
		for (int i = 0; i < scene.size(); i++)
		{
			scene[i]->Reset(cam);
			scene[i]->RotateY(cam);
			scene[i]->RotateX(cam);
			scene[i]->RotateZ(cam);
			scene[i]->Project(cam);
		}

		int horizon = int(cam.getPitch() * -9.75);

		/*
		* DRAWING THE SCREEN
		*/

		/*
		* Drawing the sky
		*/
		Orca::Renderer::Get()->Draw(skyback, 0, 0);
		
		//Locking bottom to camera if looking down
		if (horizon - 400 > 0)
		{
			Orca::Renderer::Get()->Draw(skybackbottom, 0, 0);
		}
		else
		{
			Orca::Renderer::Get()->Draw(skybackbottom, 0, horizon - 400);
		}
		
		Orca::Renderer::Get()->Draw(sky, 0, horizon + 200);

		
		/*
		* Drawing the scene
		*/
		for (int i = 0; i < scene.size(); i++)
		{
			Orca::Renderer::Get()->Draw(*scene[i]);
		}
	}

private:

	std::vector<std::unique_ptr<Orca::Unit>> scene;
	Orca::Camera cam;

	Orca::Image skyback{ "../Orca/Assets/Images/Skyback.png" };
	Orca::Image skybackbottom{ "../Orca/Assets/Images/Skybackbottom.png" };
	Orca::Image sky{ "../Orca/Assets/Images/Sky.png"};

	Orca::KeyBuffer keybuffer;

	void MyKeyPressedCallback(const Orca::KeyPressedEvent& key) {
		
		//Arrow keys
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			keybuffer.setRightArrow(true);
		}
		if(key.GetKey() == ORCA_KEY_LEFT)
		{
			keybuffer.setLeftArrow(true);
		}
		if (key.GetKey() == ORCA_KEY_UP)
		{
			keybuffer.setUpArrow(true);
		}
		if (key.GetKey() == ORCA_KEY_DOWN)
		{
			keybuffer.setDownArrow(true);
		}

		// WASD
		if (key.GetKey() == ORCA_KEY_D)
		{
			keybuffer.setD(true);
		}
		if (key.GetKey() == ORCA_KEY_A)
		{
			keybuffer.setA(true);
		}
		if (key.GetKey() == ORCA_KEY_W)
		{
			keybuffer.setW(true);
		}
		if (key.GetKey() == ORCA_KEY_S)
		{
			keybuffer.setS(true);
		}

		
		if (key.GetKey() == ORCA_KEY_SPACE)
		{
			keybuffer.setSpace(true);
		}
		if (key.GetKey() == ORCA_KEY_LEFT_CONTROL)
		{
			keybuffer.setCtrl(true);
		}
	}

	void MyKeyReleasedCallback(const Orca::KeyReleasedEvent& key) {
		//Arrow keys
		if (key.GetKey() == ORCA_KEY_RIGHT)
		{
			keybuffer.setRightArrow(false);
		}
		if (key.GetKey() == ORCA_KEY_LEFT)
		{
			keybuffer.setLeftArrow(false);
		}
		if (key.GetKey() == ORCA_KEY_UP)
		{
			keybuffer.setUpArrow(false);
		}
		if (key.GetKey() == ORCA_KEY_DOWN)
		{
			keybuffer.setDownArrow(false);
		}

		// WASD
		if (key.GetKey() == ORCA_KEY_D)
		{
			keybuffer.setD(false);
		}
		if (key.GetKey() == ORCA_KEY_A)
		{
			keybuffer.setA(false);
		}
		if (key.GetKey() == ORCA_KEY_W)
		{
			keybuffer.setW(false);
		}
		if (key.GetKey() == ORCA_KEY_S)
		{
			keybuffer.setS(false);
		}


		if (key.GetKey() == ORCA_KEY_SPACE)
		{
			keybuffer.setSpace(false);
		}
		if (key.GetKey() == ORCA_KEY_LEFT_CONTROL)
		{
			keybuffer.setCtrl(false);
		}
	}
};

GAME_ORCA_START(BestGame);
//physics and map class not necessary
//uniquenesses text file in game (custom additions)
