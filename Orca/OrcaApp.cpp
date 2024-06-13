#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "OrcaApp.h"
#include "OrcaWindow.h"
#include "stb_image.h"

namespace Orca
{
	void OrcaApp::OnUpdate()
	{
		
	}

	void OrcaApp::Run()
	{
		OrcaWindow::Init();
		OrcaWindow::GetWindow()->CreateWindow(1000, 800, "Test");

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ORCA_ERROR("ERROR: Failed to initialize GLAD")
		}

		//// VERTEX DATA ////

		float vertices[] = {
			-0.5f, -0.5f, 0.0f, 0.0f, // left  
			 0.5f, -0.5f, 0.0f, 1.0f, // right 
			 0.0f,  0.5f, 1.0f, 1.0f, // top 
			 0.5f, -0.5f, 1.0f, 0.0f// bottom-right
		};

		unsigned int indices[] = {
			0, 1, 2, // first triangle
			0, 2, 3  // second triangle
		};

		unsigned VAO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2*sizeof(float));
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		//// SHADERS //// Class C function ("void main")

		const char* vertexShaderSource = R"(
			#version 330 core
			layout (location = 0) in vec2 aPos;
			void main()
			{
				gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);
			}
		)";

		const char* fragmentShaderSource = R"(
			#version 330 core
			out vec4 FragColor;
			void main()
			{
				FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
			}
		)";

		// vertex shader
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

		unsigned int texture1, texture2;
		// texture 1
		// ---------
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		unsigned char* data = stbi_load("../Table/Assets/Images/Sun.png", &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			ORCA_ERROR("Failed to load texture");
		}
		stbi_image_free(data);

		while (true)
		{
			//Game is stuck in this while loop
			OnUpdate();

			glUseProgram(shaderProgram);
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			glBindTexture(GL_TEXTURE_2D, texture1);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			OrcaWindow::GetWindow()->SwapBuffers();
			OrcaWindow::GetWindow()->PollEvents();
		}
	}
}
