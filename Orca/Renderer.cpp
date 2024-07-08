#include "pch.h"
#include "Renderer.h"
#include "ThirdParty/codeOpenGL/RendererOpenGL.h"
#include "OrcaWindow.h"

namespace Orca
{
	void Renderer::Init()
	{
		if (!mInstance)
		{
			mInstance = std::shared_ptr<Renderer>{ new Renderer };
		}
	}

	std::shared_ptr<Renderer> Renderer::Get()
	{
		return mInstance;
	}

	void Renderer::Draw(Image & pic, int xCoord, int yCoord, Shaders & shaders)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shaders);
	}

	void Renderer::Draw(Image & pic, int xCoord, int yCoord)
	{
		/*mDefaultShaders.SetUniform2Ints(
			"ScreenSize",
			OrcaWindow::GetWindow()->GetWidth(),
			OrcaWindow::GetWidth()->GetHeight());*/
		mImplementation->Draw(pic, xCoord, yCoord);
	}

	void Renderer::Draw(Unit& unit, Shaders& shaders)
	{
		if (unit.isVisible())
		{
			mImplementation->Draw(unit.mSprite, unit.mCoords.x, unit.mCoords.y, shaders);
		}
	}
	
	void Renderer::Draw(Unit& unit)
	{
		if (unit.isVisible())
		{
			mImplementation->Draw(unit.mSprite, unit.mCoords.x, unit.mCoords.y);
		}
	}

	void Renderer::ClearScreen()
	{
		mImplementation->ClearScreen();
	}

	Renderer::Renderer()
	{
#ifdef ORCA_OPENGL
		mImplementation = std::make_unique<RendererOpenGL>();
#else
		#ERROR_ORCA_OPENGL_ISNT_DEFINED
#endif
	}
}
