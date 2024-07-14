#include "pch.h"
#include "Unit.h"

#define PI 3.1415926535897932384626433832795

namespace Orca
{
	Unit::Unit(const std::string& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(fileName);
		angle = 0;
		scale = 1;
	}

	Unit::Unit(std::string&& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(std::move(fileName));
		angle = 0;
		scale = 1;
	}

	Orca::Coordinates::Coordinates() : x(0), y(0), z(0)
	{
		
	}

	Coordinates::Coordinates(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal)
	{

	}

	Orca::LocalCoordinates::LocalCoordinates() : x(0), y(0), z(0)
	{

	}

	LocalCoordinates::LocalCoordinates(double xVal, double yVal, double zVal) : x(xVal), y(yVal), z(zVal)
	{

	}

	void Unit::SetCoordinates(Coordinates newCoordinates)
	{
		mCoords = newCoordinates;
	}

	Coordinates Unit::GetCoordinates() const
	{
		return mCoords;
	}

	void Unit::LoadSprite(const std::string& fileName)
	{
		mSprite.LoadImage(fileName);
	}

	void Unit::LoadSprite(std::string&& fileName)
	{
		mSprite.LoadImage(std::move(fileName));
	}
	
	bool Unit::OverlapsWih(const Unit& other) const
	{
		bool overlapsOnX {
			(mCoords.x >= other.mCoords.x && mCoords.x <= other.mCoords.x + other.GetWidth()) ||
			(mCoords.x <= other.mCoords.x && other.mCoords.x <= mCoords.x + GetWidth())
		};

		bool overlapsOnY {
			(mCoords.y >= other.mCoords.y && mCoords.y <= other.mCoords.y + other.GetHeight()) ||
			(mCoords.y <= other.mCoords.y && other.mCoords.y <= mCoords.y + GetHeight())
		};

		return overlapsOnX && overlapsOnY;
	}

	void Unit::UpdateXBy(int amount)
	{
		mCoords.x += amount;
	}

	void Unit::UpdateYBy(int amount)
	{
		mCoords.y += amount;
	}

	int Unit::GetWidth() const
	{
		return mSprite.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mSprite.GetHeight();
	}

	double Unit::getAngle() const
	{
		return angle;
	}

	Speed Unit::GetSpeed() const
	{
		return mSpeed;
	}

	void Unit::SetSpeed(Speed newSpeed)
	{
		mSpeed = newSpeed;
	}

	void Unit::UpdateSpeed(int xChange, int yChange)
	{
		mSpeed.xSpeed += xChange;
		mSpeed.ySpeed += yChange;
	}

	void Unit::SetScale(double d)
	{
		scale = d;
	}

	bool Unit::isVisible() const
	{
		return mIsVisible;
	}

	void Unit::SetVisible()
	{
		mIsVisible = true;
	}

	void Unit::SetInvisible()
	{
		mIsVisible = false;
	}

	Speed::Speed()
	{
	}

	Speed::Speed(int xComponent, int yComponent) : xSpeed(xComponent), ySpeed(yComponent)
	{
	}

	/*
	* 3D Functions
	*/

	void Unit::SetAll(Unit& unit)
	{
		mCoords.x = unit.mCoords.x;
		mCoords.y = unit.mCoords.y;
		mCoords.z = unit.mCoords.z;

		mLocalCoords.x = unit.mLocalCoords.x;
		mLocalCoords.y = unit.mLocalCoords.y;
		mLocalCoords.z = unit.mLocalCoords.z;
	}

	void Unit::Reset(Camera& cam)
	{
		mLocalCoords.x = mCoords.x;
		mLocalCoords.y = mCoords.y;
		mLocalCoords.z = mCoords.z;

		SetVisible();
		cam.reset();
	}

	// roll
	void Unit::RotateZ(Camera& cam)
	{
		double xPos = mLocalCoords.x - cam.getX();
		double yPos = mLocalCoords.y - cam.getY();
		double zPos = mLocalCoords.z - cam.getZ();

		double a;
		double b;

		a = yPos * cos(cam.getRoll() / (180.0 / PI));
		b = xPos * sin(cam.getRoll() / (180.0 / PI));

		mLocalCoords.y = a - b + cam.getY();

		a = xPos * cos(cam.getRoll() / (180.0 / PI));
		b = yPos * sin(cam.getRoll() / (180.0 / PI));

		mLocalCoords.x = a + b + cam.getX();
	}

	// yaw 
	void Unit::RotateY(Camera& cam)
	{
		double xPos = mLocalCoords.x - cam.getX();
		double yPos = mLocalCoords.y - cam.getY();
		double zPos = mLocalCoords.z - cam.getZ();

		double a;
		double b;

		a = xPos * cos(cam.getYaw() / (180.0 / PI));
		b = zPos * sin(cam.getYaw() / (180.0 / PI));

		mLocalCoords.x = a - b + cam.getX();

		a = zPos * cos(cam.getYaw() / (180.0 / PI));
		b = xPos * sin(cam.getYaw() / (180.0 / PI));

		mLocalCoords.z = a + b + cam.getZ();
	}

	// pitch
	void Unit::RotateX(Camera& cam)
	{		
		double xPos = mLocalCoords.x - cam.getX();
		double yPos = mLocalCoords.y - cam.getY();
		double zPos = mLocalCoords.z - cam.getZ();

		double a;
		double b;

		a = yPos * cos(cam.getPitch() / (180.0 / PI));
		b = zPos * sin(cam.getPitch() / (180.0 / PI));

		mLocalCoords.y = a - b + cam.getY();

		a = zPos * cos(cam.getPitch() / (180.0 / PI));
		b = yPos * sin(cam.getPitch() / (180.0 / PI));

		mLocalCoords.z = a + b + cam.getZ();
	}

	void Unit::Project(Camera& cam)
	{
		
		double xPos = mLocalCoords.x - cam.getX();
		double yPos = mLocalCoords.y - cam.getY();
		double zPos = mLocalCoords.z - cam.getZ();

		// Set to invisible if object is behind camera
		if (zPos < 0)
		{
			SetInvisible();
		}

		double parr = abs(500.0 / zPos);

		// local coordinates get converted to screen coordinates and a scale value
		// screen coordinates
		mLocalCoords.x = 500.0 + parr * xPos;
		mLocalCoords.y = 400.0 + parr * yPos;

		// scale value
		mLocalCoords.z = (100 / zPos) * scale;

		// rotate value
		angle = 360 - cam.getRoll();
	}

	double Unit::DistToCam(Camera& cam)
	{
		double xDist = mCoords.x - cam.getX();
		double yDist = mCoords.y - cam.getY();
		double zDist = mCoords.z - cam.getZ();

		return sqrt(pow(xDist, 2) + pow(yDist, 2) + pow(zDist, 2));
	}
}
