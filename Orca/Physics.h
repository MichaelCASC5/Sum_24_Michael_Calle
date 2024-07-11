#pragma once

#include "Utilities.h"
#include "Unit.h"
#include "Map.h"

namespace Orca
{
	class ORCA_API Physics
	{
	public:
		Physics();
		Physics(int gravity);

		void NextPosition(Unit& unit, const Map& map);
		bool PositionIsPossible(const Unit& unit, const Map& map, Coordinates coords);
		void ApplyGravity(Unit& unit);
		bool IsStanding(Unit& unit, const Map& map);

		int GetGravity() const;
		void SetGravity(int newGravity);

	private:
		int mGravity{ 0 }; // number of pixels to alter Y speed component per frame

	};
}
