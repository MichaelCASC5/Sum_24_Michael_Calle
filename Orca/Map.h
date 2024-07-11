#pragma once

#include "pch.h"
#include "Utilities.h"
#include "Image.h"
#include "Unit.h"

namespace Orca
{
	class ORCA_API Map
	{
	public:
		void LoadBackgroundImage(const std::string& fileName);
		void LoadBackgroundImage(std::string&& fileName);
		void LoadPixelPassability(std::vector<std::vector<bool>> pixelPassability);

		bool GetPixelPassability(Coordinates coords) const;

		int GetWidth() const;
		int GetHeight() const;

		friend class Renderer;

	private:
		Image mBackground;
		std::vector<std::vector<bool>> mPassable;
	};
}
