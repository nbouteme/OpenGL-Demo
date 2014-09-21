#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <GLWindow.hpp>

#include <Camera.hpp>
#include <Scene.hpp>
#include <Mesh.hpp>

int GLWindow::run(int argc, char **argv)
{
	// Inutilises pour l'instant
	(void) argc;
	(void) argv;
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);

	glfwWindowHint(GLFW_RESIZABLE, false);
	m_win = glfwCreateWindow(1280, 720, "Demo Math", nullptr, nullptr);
	glfwMakeContextCurrent(m_win);

	glewExperimental = GL_TRUE;
	glewInit();

	auto triangle = std::make_shared<Mesh>();
	auto triangle2 = std::make_shared<Mesh>();
	auto triangle3 = std::make_shared<Mesh>();
	Camera cam;
	Scene sc;
	sc.addModel(triangle);
	sc.addModel(triangle2);
	sc.addModel(triangle3);

	triangle2->translateX(1.0f);
	triangle3->translateX(0.5f);
	triangle3->translateY(0.866025f);

	while(!glfwWindowShouldClose(m_win))
	{
		glfwPollEvents();
		if (glfwGetKey(m_win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(m_win, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		sc.render(cam);

		if (glfwGetKey(m_win, GLFW_KEY_UP) == GLFW_PRESS)
			cam.m_position += glm::vec3(0.1f, 0.0f, 0.0f);
		else if (glfwGetKey(m_win, GLFW_KEY_DOWN) == GLFW_PRESS)
			cam.m_position += glm::vec3(-0.1f, 0.0f, 0.0f);
		else if (glfwGetKey(m_win, GLFW_KEY_LEFT) == GLFW_PRESS)
			cam.m_position += glm::vec3(0.0f, 0.1f, 0.0f);
		else if (glfwGetKey(m_win, GLFW_KEY_RIGHT) == GLFW_PRESS)
			cam.m_position += glm::vec3(0.0f, -0.1f, 0.0f);
		else if (glfwGetKey(m_win, GLFW_KEY_Z) == GLFW_PRESS)
			cam.m_position += glm::vec3(0.0f, 0.0f, 0.1f);
		else if (glfwGetKey(m_win, GLFW_KEY_X) == GLFW_PRESS)
			cam.m_position += glm::vec3(0.0f, 0.0f, -0.1f);

		cam.update();
		glfwSwapBuffers(m_win);
	}

	glfwTerminate();
	return 0;	
}
