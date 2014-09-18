#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GLWindow.hpp"
#include <iostream>

int GLWindow::run(int argc, char **argv)
{
	// Inutilises pour l'instant
	(void) argc;
	(void) argv;
	glewExperimental = GL_TRUE;
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, false);
	m_win = glfwCreateWindow(1280, 720, "Demo Math", nullptr, nullptr);
	glfwMakeContextCurrent(m_win);
	glewInit();

	GLuint vertexBuffer = 0;
	glGenBuffers(1, &vertexBuffer);
	printf("%u\n", vertexBuffer);


	while(!glfwWindowShouldClose(m_win))
	{
		glfwSwapBuffers(m_win);
		glfwPollEvents();
		if (glfwGetKey(m_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_win, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwTerminate();
	return 0;	
}
