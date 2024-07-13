#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"
#include "Camera.h"

namespace Orca
{
	struct ORCA_API Coordinates
	{
		double x{ 0 };
		double y{ 0 };
		double z{ 0 };

		Coordinates();
		Coordinates(double xVal, double yVal, double zVal);
	};

	struct ORCA_API LocalCoordinates
	{
		double x{ 0 };
		double y{ 0 };
		double z{ 0 };

		LocalCoordinates();
		LocalCoordinates(double xVal, double yVal, double zVal);
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
		double getAngle() const;

		Speed GetSpeed() const;
		void SetSpeed(Speed newSpeed);
		void UpdateSpeed(int xChange, int yChange);
		
		bool isVisible() const;
		void SetVisible();
		void SetInvisible();

		friend class Renderer;

		/*
		* 3D Functions
		*/
		void Reset(Camera& cam);
		void RotateZ(Camera& cam);
		void RotateY(Camera& cam);
		void RotateX(Camera& cam);
		void Project(Camera& cam);

	private:
		Coordinates mCoords;
		LocalCoordinates mLocalCoords;

		Image mSprite;

		bool mIsVisible{ true };
		Speed mSpeed;

		double angle;
	};
}
