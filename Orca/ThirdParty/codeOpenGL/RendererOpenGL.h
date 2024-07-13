#pragma once

#include "../../RendererImplementation.h"
#include "ThirdParty/codeOpenGL/ShadersOpenGL.h"

namespace Orca
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		RendererOpenGL();
		~RendererOpenGL();

		virtual void Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders) override;
		virtual void Draw(Image& pic, int xCoord, int yCoord, double scale, double angle) override;
		virtual void ClearScreen() override;

	private:
		ShadersOpenGL mDefaultShaders;
	};
}
