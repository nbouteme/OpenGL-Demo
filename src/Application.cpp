#include <Application.hpp>

using namespace std;

shared_ptr<Application> (*Application::getSingleton)() = &Application::createSingleton;
shared_ptr<Application> Application::m_app = Application::getSingleton();
shared_ptr<BaseWindow> Application::m_glWindow = std::make_shared<GLWindow>();

int Application::run(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	return m_glWindow->run(argc, argv);
}

shared_ptr<Application> Application::createSingleton()
{
	Application::getSingleton = &Application::returnSingleton;
	return shared_ptr<Application>(new Application());
}

shared_ptr<Application> Application::returnSingleton()
{
	return m_app->shared_from_this();
}
