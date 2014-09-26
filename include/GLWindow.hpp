#pragma once

#include "BaseWindow.hpp"
#include <memory>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GLWindow : public BaseWindow
{
	GLFWwindow* m_win;
public:
	operator GLFWwindow*() const { return m_win; }
	virtual int run(int = 0, char ** = 0) override;
	static GLFWwindow *getMainWindow();
};
