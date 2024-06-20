#include "pch.h"
#include "Renderer.h"
#include "ThirdParty/codeOpenGL/RendererOpenGL.h"

namespace Orca
{
	void Renderer::Init()
	{
		if (!mInstance)
		{
			mInstance = std::shared_ptr<Renderer>{ new Renderer };
		}
		
		std::shared_ptr<Renderer> Renderer::Get()
		{
			return mInstance;
		}

		void Renderer::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
		{
			mImplementation->Draw(pic, xCoord, yCoord, shaders);
		}

		void Renderer::Draw(Image& pic, int xCoord, int yCoord)
		{
			mDefaultShaders.SetUniform2Ints(
				"ScreenSize",
				OrcaWindow::GetWindow()->GetWidth(),
				OrcaWindow::GetWidth()->GetHeight());
			mImplementation->Draw(pic, xCoord, yCoord, mDefaultShaders);
		}

		Renderer::Renderer()
		{
#ifdef ORCA_OPENGL
			mImplementation = std::make_unique<RendererOpenGL>(vertexFile, fragmentFile);
#else
			#ERROR_ORCA_OPENGL_ISNT_DEFINED
#endif
		}
	}
}
