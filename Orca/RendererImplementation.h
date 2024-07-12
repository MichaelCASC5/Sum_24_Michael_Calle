#pragma once

#include "Image.h"
#include "Shaders.h""

namespace Orca
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) = 0;
		virtual void Draw(Image& pic, int xCoord, int yCoord, double scale) = 0;
		virtual void ClearScreen() = 0;

		virtual ~RendererImplementation() {};
	};
}
