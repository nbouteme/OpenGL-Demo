#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GLWindow.hpp>

#include <Camera.hpp>
#include <Scene.hpp>
#include <Mesh.hpp>
#include <iostream>

GLFWvidmode GLWindow::Screen;

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
	GLWindow::Screen = *glfwGetVideoMode(glfwGetPrimaryMonitor());

	glewExperimental = GL_TRUE;
	glewInit();

	auto triangle  = make_shared<Mesh>();
	Camera cam(this);
	Scene sc;
	sc.addModel(triangle);

	// TODO: regler le bug d'import OBJ
	// TODO: Deplacer la gestion des entree en dehors de la boucle principale
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
        glClear(GL_COLOR_BUFFER_BIT);

		sc.render(cam);

		glfwSwapBuffers(m_win);
	}

	glfwTerminate();
	return 0;	
}
