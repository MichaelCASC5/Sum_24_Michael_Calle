#include "pch.h"
#include "RendererOpenGL.h"
#include "glad/glad.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "OrcaWindow.h"
#define PI 3.1415926535897932384626433832795

namespace Orca
{
	RendererOpenGL::RendererOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			ORCA_ERROR("ERROR: Failed to initialize GLAD");
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		mDefaultShaders.LoadSourceCode(
			"../Orca/Assets/Shaders/defaultVertex.glsl",
			"../Orca/Assets/Shaders/defaultFragment.glsl");
	}

	RendererOpenGL::~RendererOpenGL()
	{
		
	}

	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord, Shaders& shaders)
	{
		float vertices[] = {
			xCoord,					 yCoord,				   0.0f, 0.0f, // left  
			xCoord,					 yCoord + pic.GetHeight(), 0.0f, 1.0f, // right 
			xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f, // top 
			xCoord + pic.GetWidth(), yCoord,				   1.0f, 0.0f// bottom-right
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

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		shaders.Bind();
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererOpenGL::Draw(Image& pic, int xCoord, int yCoord, double scale, double angle)
	{
		// Adjusting the width and height of the picture to account for scale
		int width = pic.GetWidth() * scale;
		int height = pic.GetHeight() * scale;

		angle = angle * (PI / 180.0);

		double c = cos(angle);
		double s = sin(angle);

		// Trig to rotate the picture
		float vertices[] = {
			xCoord,									yCoord,									0.0f, 0.0f, // left  
			xCoord - (s * height),					yCoord + (c * height),					0.0f, 1.0f, // right 
			xCoord + (c * width) - (s * height),	yCoord + (s * width) + (c * height),	1.0f, 1.0f, // top 
			xCoord + (c * width),					yCoord + (s * width),					1.0f, 0.0f// bottom-right
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

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned EBO{ 0 };
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		mDefaultShaders.Bind();
		mDefaultShaders.SetUniform2Ints(
			"ScreenSize",
			OrcaWindow::GetWindow()->GetWidth(),
			OrcaWindow::GetWindow()->GetHeight());
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		pic.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void RendererOpenGL::ClearScreen()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
