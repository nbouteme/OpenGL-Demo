/**
 * \author N.Boutemeur
 */

#pragma once

#include <memory>
#include <cassert>

#include <Log.hpp>

class Controller;
class BaseWindow;

/**
 * \class Application
 * Cette classe gère les accès aux ressources partagées
 */
class Application : public std::enable_shared_from_this<Application>
{
	static std::shared_ptr<Application> m_app;
    /**
	 * \var m_glWindow
	 * \p Pointe sur l'instance existante de la fenêtre
	 */
	std::shared_ptr<BaseWindow> m_glWindow;
    /**
	 * \var m_controller
	 * \p Pointe sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller> m_controller;
    /**
	 * \return Instance existante du singleton
	 */
	static std::shared_ptr<Application> returnSingleton();
    /**
	 * \return Nouvelle instance de singleton
	 */
	static std::shared_ptr<Application> createSingleton();
    /**
	 * \var _getSingleton
	 * \p Pointe sur la fonction qui retourne une instance de singleton
	 */
	static std::shared_ptr<Application> (*_getSingleton)();
	// Pour empêcher une instanciation.
	Application();
public:
    /**
	 * \return L'instance existante du singleton
	 */
	static std::shared_ptr<Application> getSingleton() { return _getSingleton(); }
    /**
	 * \return Un pointeur sur l'instance existante de la fenêtre
	 */
	std::shared_ptr<BaseWindow>  getWindow()
	{
		//	assert(m_glWindow);
		return m_glWindow;
	}
    /**
	 * \return Un pointeur sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller>  getController()       { return m_controller;    }
    /**
	 * \return L'état de fin d'exécution de l'application.
	 */
	int run(int = 0, char ** = 0);
	static Logger Log;
};
