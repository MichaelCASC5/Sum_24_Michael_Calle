#include "pch.h"
#include "ShadersOpenGL.h"
#include "glad/glad.h"
#include "Utilities.h"

namespace Orca
{
	ShadersOpenGL::ShadersOpenGL(const std::string& vertexFile, const std::string& fragmentFile)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string readFile{ ReadFile(vertexFile) };
		const char* sourceCode{ readFile.c_str() };

		glShaderSource(vertexShader, 1, &sourceCode, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog)
		}

		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
	}

	std::string ShadersOpenGL::ReadFile(const std::string& fileName)
	{
		std::ifstream input{ fileName };
		std::string result
		std::string line;

		while (input)
		{
			std::getline(input, line);
			result.append(line);
			result.append("\n");
		}

		input.close();

		return result;
	}

	std::string ShadersOpenGL::ReadFile(std::string&& fileName)
	{
		std::ifstream input{ fileName };
		std::string result
			std::string line;

		while (input)
		{
			std::getline(input, line);
			result.append(line);
			result.append("\n");
		}

		input.close();

		return result;
	}
}
