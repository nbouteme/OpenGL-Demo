#include <Application.hpp>

using namespace std;

std::shared_ptr<Application> Application::m_app = nullptr;

shared_ptr<Application> Application::getSingleton()
{
	if(!m_app)
		m_app = std::make_shared<Application>();
	return m_app;
}

int Application::run(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	m_glWindow = std::make_shared<GLWindow>();
	return m_glWindow->run(argc, argv);
}
