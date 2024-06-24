#include "pch.h"
#include "Shaders.h"
#include "ThirdParty/codeOpenGL/ShadersOpenGL.h"

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

	void Shaders::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}

	void Shaders::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(std::move(uniformName), val1, val2);
	}
}