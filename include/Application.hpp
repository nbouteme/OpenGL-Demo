#pragma once
#include <memory>
#include "GLWindow.hpp"

class Application : public std::enable_shared_from_this<Application>
{
private:
	static std::shared_ptr<Application> m_app;
	std::shared_ptr<BaseWindow> m_glWindow;
	static std::shared_ptr<Application> returnSingleton();
	static std::shared_ptr<Application> createSingleton();
	Application() {};
public:
	static std::shared_ptr<Application> (*getSingleton)();
	int run(int argc = 0, char **argv = 0);
};
