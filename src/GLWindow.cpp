#include <GLWindow.hpp>

#include <Application.hpp>
#include <BetaRoom.hpp>
#include <Assets.hpp>
#include <Camera.hpp>
#include <Controller.hpp>

#include <iostream>
#include <cassert>

using namespace std;

shared_ptr<Camera> GLWindow::m_cam;

void resizeCallback(GLFWwindow *, int, int);

GLWindow::GLWindow()
{
	// Initialise la bibliotheque
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, false);
	glfwWindowHint(GLFW_RESIZABLE, true);

	m_win = glfwCreateWindow(1280, 720, "Demo Math", nullptr, nullptr);

	// La fonction resizeCallback est appelée à chaque redimensionnement 
	glfwSetWindowSizeCallback(m_win, &resizeCallback);
	// bind le contexte sur la fenêtre
	glfwMakeContextCurrent(m_win);

	// Initialise le chargeur d'extension
	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();// glewInit peut generer un GL_INVALID_ENUM

	// Instancie fenetre et camera
	m_controller = Controller::getController();
	m_cam = make_shared<Camera>(this);

}

void resizeCallback(GLFWwindow *win, int width, int height)
{
	(void)win; // Inutilisé
	glViewport(0, 0, width, height); // Redimensionne le contexte, pour s'adapter au nouvelles tailles

	GLWindow::m_cam->width  = width;
	GLWindow::m_cam->height = height;
	GLWindow::m_cam->m_projection = glm::perspective(45.0f, float(width) / height, 0.1f, 10.0f); // change le ratio dans la matrice de projection
}

GLWindow *GLWindow::getMainWindow()
{
	return dynamic_cast<GLWindow*>(Application::getSingleton()->getWindow().get());
}

int GLWindow::run(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	BetaRoom sc(*m_cam); // Instancie la scène

	glEnable(GL_DEPTH_TEST); // Active le test de profondeur

	while(!glfwWindowShouldClose(m_win)) // Tant que la fenetre ne doit pas se fermer
	{
		glfwPollEvents(); // Recupere l'état des entrée sorties
		if (glfwGetKey(m_win, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Si un appuis sur echap a été détécté, alors on marquela fenetre comme devant se fermer
			glfwSetWindowShouldClose(m_win, GL_TRUE);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // nettoie le tampon de rendu

		sc.render(); // rends la scène

		int e = glGetError();
		assert(e == 0);

		glfwSwapBuffers(m_win); // Affiche le tampon de rendu sur la fenêtre
	}
	return 0;
}

GLWindow::~GLWindow()
{
	glfwTerminate();
}
