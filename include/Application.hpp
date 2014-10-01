#pragma once
#include <memory>
#include "GLWindow.hpp"

class Application : public std::enable_shared_from_this<Application>
{
private:
	static std::shared_ptr<Application> m_app;
	static std::shared_ptr<BaseWindow> m_glWindow;
	static std::shared_ptr<Application> returnSingleton();
	static std::shared_ptr<Application> createSingleton();
	Application() {};
public:
	static std::shared_ptr<Application> (*getSingleton)();
	static std::shared_ptr<BaseWindow> getWindow() { return m_glWindow; }
	int run(int = 0, char ** = 0);
};
