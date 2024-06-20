
ShadersOpenGL::ShadersOpenGL(std::string& vertexFile, std::string& fragmentFile)
{
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
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
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		ORCA_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}

	// link shaders
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		ORCA_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

ShadersOpenGL::ShadersOpenGL(std::string&& vertexFile, std::string&& fragmentFile)
{
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	std::string readFile{ ReadFile(std::move(vertexFile)) };
	const char* source{ readFile.c_str() };

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
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
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		ORCA_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}

	// link shaders
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		ORCA_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

unsigned int vertexSHader
void ShadersOpenGL::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
{
	glUseProgram(mShaderProgram);
	int location{ glGetUniformLocation(mShaderProgram, uniformName.c_str) };
	glUniform2i(location, val1, val2);
}

void ShadersOpenGL::~ShadersOpenGL()
{
	glDeleteProgram(mShaderProgram);
}

void ShadersOpenGL::Bind()
{
	glUseProgram(mShaderProgram);
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
