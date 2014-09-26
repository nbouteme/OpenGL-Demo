#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GLWindow.hpp>

#include <Application.hpp>
#include <Camera.hpp>
#include <BetaRoom.hpp>
#include <Mesh.hpp>

#include <iostream>

GLFWwindow *GLWindow::getMainWindow()
{
	return dynamic_cast<GLWindow*>(Application::getWindow().get())->m_win;
}

using namespace std;

int GLWindow::run(int argc, char **argv)
{
	// Inutilises pour l'instant
	(void) argc;
	(void) argv;
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, false);
	glfwWindowHint(GLFW_RESIZABLE, true);
	m_win = glfwCreateWindow(1280, 720, "Demo Math", nullptr, nullptr);

	glfwMakeContextCurrent(m_win);

	glewExperimental = GL_TRUE;
	glewInit();

	auto triangle  = make_shared<Mesh>();
	auto li  = make_shared<Mesh>();

	li->translateX(2.0f);
	li->translateY(3.0f);
	li->translateZ(1.0f);

	li->scaleX(0.1f);
	li->scaleY(0.1f);
	li->scaleZ(0.1f);

	Camera cam(this);
	BetaRoom sc;

	glEnable(GL_DEPTH_TEST);
	// TODO: activer le depth test
	// TODO: lumieres
	// TODO: Rendre scene derivable, pour deplacer la creation des mesh dedans
	// TODO: desactiver le wireframe
	// TODO: revoir les ordres d'inclusions
	while(!glfwWindowShouldClose(m_win))
	{
		glfwPollEvents();
		if (glfwGetKey(m_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_win, GL_TRUE);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sc.render(cam);

		glfwSwapBuffers(m_win);
	}

	glfwTerminate();
	return 0;
}
