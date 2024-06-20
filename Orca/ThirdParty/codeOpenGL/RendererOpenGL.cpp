#include "pch.h"
#include "RendererOpenGL.h"
#include "glad/glad.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

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
	}
}
