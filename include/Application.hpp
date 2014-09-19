#pragma once
#include <memory>
#include "GLWindow.hpp"

class Application
{
private:
	static std::shared_ptr<Application> m_app;
	std::shared_ptr<BaseWindow> m_glWindow;
public:
	static std::shared_ptr<Application> getSingleton();
	int run(int argc = 0, char **argv = 0);
};
