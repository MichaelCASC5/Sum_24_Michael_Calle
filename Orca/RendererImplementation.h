#pragma once

#include "Image.h"
#include "Shaders.h""

namespace Orca
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) override;
		virtual void Draw(Image& pic, int xCoord, int yCoord) override;

		virtual ~RendererImplementation() {};
	};
}