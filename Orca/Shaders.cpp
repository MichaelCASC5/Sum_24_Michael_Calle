#include "pch.h"
#include "Shaders.h"

namespace Orca
{
	Shaders::Shaders(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef ORCA_OPENGL
		mImplementation = std::make_unique<ShadersOpenGL>(vertexFile, fragmentFile);
#else
		#ERROR_ORCA_OPENGL_ISNT_DEFINED
#endif
	}

	Shaders::Shaders(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef ORCA_OPENGL
		mImplementation = std::make_unique<ShadersOpenGL>(std::move(vertexFile), std::move(fragmentFile));
#else
		#ERROR_ORCA_OPENGL_ISNT_DEFINED
#endif
	}

	void Shaders::Bind()
	{
		mImplementation->Bind();
	}
}