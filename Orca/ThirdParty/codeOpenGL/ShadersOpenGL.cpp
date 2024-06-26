#include "pch.h"
#include "ShadersOpenGL.h"
#include "glad/glad.h"
#include "Utilities.h"

namespace Orca
{
	ShadersOpenGL::ShadersOpenGL()
	{
	}

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

		readFile = ReadFile(fragmentFile);
		sourceCode = readFile.c_str();

		glShaderSource(fragmentShader, 1, &sourceCode, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		// link shaders
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);
		// check for linking errors
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	ShadersOpenGL::ShadersOpenGL(std::string&& vertexFile, std::string&& fragmentFile)
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

		readFile = ReadFile(std::move(fragmentFile));
		sourceCode = readFile.c_str();

		glShaderSource(fragmentShader, 1, &sourceCode, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		// link shaders
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);
		// check for linking errors
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void ShadersOpenGL::Bind()
	{
		glUseProgram(mShaderProgram);
	}

	void ShadersOpenGL::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		int location{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}

	void ShadersOpenGL::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProgram);
		int location{ glGetUniformLocation(mShaderProgram, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}

	ShadersOpenGL::~ShadersOpenGL()
	{
		glDeleteProgram(mShaderProgram);
	}

	void ShadersOpenGL::LoadSourceCode(const std::string& vertexFile, const std::string& fragmentFile)
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

		readFile = ReadFile(fragmentFile);
		sourceCode = readFile.c_str();

		glShaderSource(fragmentShader, 1, &sourceCode, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}

		// link shaders
		mShaderProgram = glCreateProgram();
		glAttachShader(mShaderProgram, vertexShader);
		glAttachShader(mShaderProgram, fragmentShader);
		glLinkProgram(mShaderProgram);
		// check for linking errors
		glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
			ORCA_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	std::string ShadersOpenGL::ReadFile(const std::string& fileName)
	{
		std::ifstream input{ fileName };
		std::string result;
		std::string line;

		while (input)
		{
			line.clear();
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
		std::string result;
		std::string line;

		while (input)
		{
			line.clear();
			std::getline(input, line);
			result.append(line);
			result.append("\n");
		}

		input.close();

		return result;
	}
}
