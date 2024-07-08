#include "pch.h"
#include "Physics.h"

namespace Orca
{
	Physics::Physics()
	{

	}

	Physics::Physics(int gravity) : mGravity(gravity)
	{

	}

	void Physics::NextPosition(Unit, Map)
	{

	}

	int Physics::GetGravity() const
	{
		return mGravity;
	}

	void Physics::SetGravity(int newGravity)
	{
		mGravity = newGravity;
	}
}
