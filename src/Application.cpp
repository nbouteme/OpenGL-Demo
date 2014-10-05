#include <Application.hpp>
#include <Controller.hpp>

using namespace std;

shared_ptr<Application> (*Application::_getSingleton)() =
	&Application::createSingleton;

shared_ptr<Application> Application::m_app = Application::getSingleton();

int Application::run(int argc, char **argv)
{
	m_glWindow   = std::make_shared<GLWindow>();
	return m_glWindow->run(argc, argv);
}

shared_ptr<Application> Application::createSingleton()
{
	Application::_getSingleton = &Application::returnSingleton;
	return shared_ptr<Application>(new Application());
}

shared_ptr<Application> Application::returnSingleton()
{
	return m_app->shared_from_this();
}
