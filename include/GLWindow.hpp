#pragma once

#include <BaseWindow.hpp>

#include <memory>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Controller;
class Camera;

class GLWindow : public BaseWindow
{
	GLFWwindow* m_win;
	std::shared_ptr<Controller> m_controller;
public:
	GLWindow();
	virtual ~GLWindow() final;
	operator GLFWwindow*() const { return m_win; }
	virtual int run(int = 0, char ** = 0) override;
	static GLWindow *getMainWindow();
	std::shared_ptr<Controller> getController() { return m_controller; }
	static std::shared_ptr<Camera> m_cam;
};
