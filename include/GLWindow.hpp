#pragma once

#include "BaseWindow.hpp"
#include <memory>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GLWindow : public BaseWindow
{
	GLFWwindow* m_win = nullptr;
public:
	operator GLFWwindow*() const { return m_win; }
	virtual int run(int argc = 0, char **argv = 0) override;
	static GLFWvidmode Screen;
};
