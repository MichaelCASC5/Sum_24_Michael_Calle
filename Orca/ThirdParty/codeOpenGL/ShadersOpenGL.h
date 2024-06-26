#pragma once

#include "../../ShadersImplementation.h"

namespace Orca
{
	class ShadersOpenGL : public ShadersImplementation
	{
	public:
		ShadersOpenGL();
		ShadersOpenGL(const std::string& vertexFile, const std::string& fragmentFile);
		ShadersOpenGL(std::string&& vertexFile, std::string&& fragmentFile);
		~ShadersOpenGL();

		virtual void Bind() override;
		virtual void SetUniform2Ints(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Ints(std::string&& uniformName, int val1, int val2) override;
		void LoadSourceCode(const std::string& vertexFile, const std::string& fragmentFile);

	private:
		unsigned int mShaderProgram{ 0 };

		std::string ReadFile(const std::string& fileName);
		std::string ReadFile(std::string&& fileName);

	};
}