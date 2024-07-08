#include "pch.h"
#include "Map.h"

namespace Orca
{
	void Map::LoadBackgroundImage(const std::string& fileName)
	{
		mBackground.LoadImage(fileName);
	}

	void Map::LoadBackgroundImage(std::string&& fileName)
	{
		mBackground.LoadImage(std::move(fileName));
	}

	void Map::LoadPixelPassability(std::vector<std::vector<bool>> pixelPassability)
	{
		mPassable = std::move(pixelPassability);
	}

	bool Map::GetPixelPassability(Coordinates coords) const
	{
		return mPassable[coords.x][coords.y];
	}

	int Map::GetWidth() const
	{
		return mBackground.GetWidth();
	}

	int Map::GetHeight() const
	{
		return mBackground.GetHeight();
	}
}
