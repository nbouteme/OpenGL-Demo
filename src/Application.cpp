/**
 * \file Application.cpp
 * \author N. Boutemeur
 */

#include <Application.hpp>
#include <Controller.hpp>

using namespace std;

/**
 * \var _getSingleton
 * \p Pointe sur la fonction qui retourne une instance de singleton
 */
shared_ptr<Application> (*Application::_getSingleton)() = &Application::createSingleton;

/**
 * \var m_app
 * \p Pointeur sur l'instance du singleton
 */
shared_ptr<Application> Application::m_app = Application::getSingleton();


/**
 * \param argc Le nombre d'arguments
 * \param argv Pointeur sur pointeurs de NTCS
 * \return Status de fin
 */
int Application::run(int argc, char **argv)
{
	m_glWindow   = std::make_shared<GLWindow>(); // Instancie la fenetre.
	return m_glWindow->run(argc, argv);
}

/**
 * \return Nouvelle instance de singleton
 */
shared_ptr<Application> Application::createSingleton()
{
	Application::_getSingleton = &Application::returnSingleton; // A partir de la, getSingleton ne fera que renvoyer l'instance existante
	return shared_ptr<Application>(new Application()); // renvoie une nouvelle instance du singleton
}

/**
 * \return Instance existante du singleton
 */
shared_ptr<Application> Application::returnSingleton()
{
	return m_app->shared_from_this(); // Renvoit un pointeur sur l'instance. // A revoir
}
