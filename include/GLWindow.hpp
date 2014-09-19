#pragma once

#include <memory>
#include "BaseWindow.hpp"
#include <GLFW/glfw3.h>

class GLWindow : public BaseWindow
{
	GLFWwindow* m_win = nullptr;
public:
	virtual int run(int argc = 0, char **argv = 0) override;
};
