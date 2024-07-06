#include "pch.h"
#include "Unit.h"

namespace Orca
{
	Orca::Coordinates::Coordinates() : x(0), y(0)
	{
		
	}

	Coordinates::Coordinates(int xVal, int yVal) : x(xVal), y(yVal)
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
		return false;
	}

	void Unit::UpdateXBy(int amount)
	{
		mCoords.x += amount;
	}

	void Unit::UpdateYBy(int amount)
	{
		mCoords.y += amount;
	}
}
