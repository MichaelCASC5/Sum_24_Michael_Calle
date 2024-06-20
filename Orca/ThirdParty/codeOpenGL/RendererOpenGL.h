#pragma once

#include "../../RendererImplementation.h"

namespace Orca
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) override;


	private:
		Shaders mDefaultShaders {

		}
	};
}
