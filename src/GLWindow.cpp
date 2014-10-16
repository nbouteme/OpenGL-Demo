#include <GLWindow.hpp>

#include <iostream>
#include <cassert>
#include <unistd.h>

#include <Application.hpp>
#include <BetaRoom.hpp>
#include <Assets.hpp>
#include <Camera.hpp>
#include <Controller.hpp>

using namespace std;

void resizeCallback(GLFWwindow *, int, int);

GLWindow::GLWindow()
{
	// Initialise la bibliotheque
	Application::Log("Initializing GLFW", Logger::Debug);
	glfwInit();

	Application::Log("Getting Controller", Logger::Debug);
	// Instancie fenetre et camera
}

GLWindow *GLWindow::getMainWindow()
{
	return dynamic_cast<GLWindow*>(Application::getSingleton()->getWindow().get());
}

void help(char *name, int option = -1);

int GLWindow::run(int argc, char **argv)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, false);
	glfwWindowHint(GLFW_RESIZABLE, true);

	bool fs = false;
	int nSamples = 0, opt;
	optind = 1;
	while((opt = getopt(argc, argv, "fa:")) != -1)
	{
		switch(opt)
		{
		case 'f':
			fs = true;
			Application::Log("Fullscreen mode enabled", Logger::Debug);
			break;
		case 'a':
			if(stoi(optarg) > 16) help(argv[0], 'a');
			nSamples = stoi(optarg);
			Application::Log(string("Antialiasing set to ") + optarg, Logger::Debug);
			break;
		}
	}

	glfwWindowHint(GLFW_SAMPLES, nSamples);

	if(!fs)
		m_win = glfwCreateWindow(1280, 720, "Demo Math", nullptr, nullptr);
	else
	{
		auto vmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		m_win = glfwCreateWindow(vmode->width, vmode->height, "Demo Math", glfwGetPrimaryMonitor(), nullptr);
	}
	// bind le contexte sur la fenêtre
	glfwMakeContextCurrent(m_win);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();// glewInit peut generer un GL_INVALID_ENUM

	BetaRoom sc; // Instancie la scène
	m_controller = Application::getSingleton()->getController();

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
	Application::Log("Ending Gracefully", Logger::Info);
	glfwTerminate();
}
