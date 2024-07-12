#include "pch.h"
#include "Unit.h"

namespace Orca
{
	Unit::Unit(const std::string& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(fileName);
	}

	Unit::Unit(std::string&& fileName, Coordinates newCoordinates) : mCoords(newCoordinates)
	{
		LoadSprite(std::move(fileName));
	}

	Orca::Coordinates::Coordinates() : x(0), y(0), z(0)
	{
		
	}

	Coordinates::Coordinates(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal)
	{

	}

	Orca::LocalCoordinates::LocalCoordinates() : x(0), y(0), z(0)
	{

	}

	LocalCoordinates::LocalCoordinates(int xVal, int yVal, int zVal) : x(xVal), y(yVal), z(zVal)
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

	void Unit::Project(Camera cam)
	{

		double xDist = mCoords.x - cam.getX();
		double yDist = mCoords.y - cam.getY();
		double zDist = mCoords.z - cam.getZ();

		double parr = abs(1000.0 / zDist);

		mLocalCoords.x = 500 + parr * xDist;
		mLocalCoords.y = 400 - parr * yDist;

		ORCA_LOG("\nObject:");
		ORCA_LOG("Global: " << mCoords.x << ", " << mCoords.y << ", " << mCoords.z);
		ORCA_LOG("Local: " << mLocalCoords.x << ", " << mLocalCoords.y << ", " << mLocalCoords.z);
	}
}
