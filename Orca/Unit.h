#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"
#include "Renderer.h"

namespace Orca
{
	struct ORCA_API Coordinates
	{
		int x{ 0 };
		int y{ 0 };

		Coordinates();
		Coordinates(int xVal, int yVal);
	};

	class ORCA_API Unit
	{
	public:
		void SetCoordinates(Coordinates newCoordinates);
		Coordinates GetCoordinates() const;

		void LoadSprite(const std::string& fileName);
		void LoadSprite(std::string&& fileName);

		bool OverlapsWih(const Unit& other) const;

		void UpdateXBy(int amount);
		void UpdateYBy(int amount);
		
		friend class Renderer;

	private:
		Coordinates mCoords;
		Image mSprite;
	};
}
