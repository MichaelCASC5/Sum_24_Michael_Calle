#include "pch.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "OrcaApp.h"
#include "OrcaWindow.h"

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
			-0.5f, -0.5f, // left  
			 0.5f, -0.5f, // right 
			 0.0f,  0.5f  // top   
		};

		unsigned VO{ 0 };
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned VBO{ 0 };
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), (void*)(0);
		glEnableVertexAttribArray(2);


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



		while (true)
		{
			//Game is stuck in this while loop
			OnUpdate();

			OrcaWindow::GetWindow()->SwapBuffers();
			OrcaWindow::GetWindow()->PollEvents();
		}
	}
}
