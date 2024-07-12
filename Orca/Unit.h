#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"

namespace Orca
{
	struct ORCA_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
	};

	struct ORCA_API Speed
	{
		int xSpeed{ 0 };
		int ySpeed{ 0 };

		Speed();
		Speed(int xComponent, int yComponent);
	};

	class ORCA_API Unit
	{
	public:
		Unit(const std::string& fileName, Coordinates newCoordinates);
		Unit(std::string&& fileName, Coordinates newCoordinates);

		void SetCoordinates(Coordinates newCoordinates);
		Coordinates GetCoordinates() const;

		void LoadSprite(const std::string& fileName);
		void LoadSprite(std::string&& fileName);

		bool OverlapsWih(const Unit& other) const;

		void UpdateXBy(int amount);
		void UpdateYBy(int amount);

		int GetWidth() const;
		int GetHeight() const;

		Speed GetSpeed() const;
		void SetSpeed(Speed newSpeed);
		void UpdateSpeed(int xChange, int yChange);
		
		bool isVisible() const;
		void SetVisible();
		void SetInvisible();

		friend class Renderer;

	private:
		Coordinates mCoords;
		Image mSprite;

		bool mIsVisible{ true };
		Speed mSpeed;
	};
}
