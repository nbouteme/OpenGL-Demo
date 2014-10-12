#include <Application.hpp>

#include <GLWindow.hpp>
#include <Controller.hpp>

using namespace std;

shared_ptr<Application> (*Application::_getSingleton)() = &Application::createSingleton;
shared_ptr<Application> Application::m_app = Application::getSingleton();

int Application::run(int argc, char **argv)
{
	m_glWindow   = std::make_shared<GLWindow>(); // Instancie la fenetre.
	return m_glWindow->run(argc, argv); // Renvois l'état de retour
}

shared_ptr<Application> Application::createSingleton()
{
	Application::_getSingleton = &Application::returnSingleton; // A partir de la, getSingleton ne fera que renvoyer l'instance existante
	return shared_ptr<Application>(new Application()); // renvoie une nouvelle instance du singleton
}

shared_ptr<Application> Application::returnSingleton()
{
	return m_app->shared_from_this(); // Renvoit un pointeur sur l'instance. // A revoir
}
