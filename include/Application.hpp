/**
 * \author N.Boutemeur
 */

#pragma once
#include <memory>

#include <GLWindow.hpp>

class Controller;

/**
 * \class Application
 * Cette classe gere les accees aux ressources partagees
 */
class Application : public std::enable_shared_from_this<Application>
{
private:
	static std::shared_ptr<Application> m_app;

    /**
	 * \var m_glWindow
	 * \p Pointe sur l'instance existante de la fenetre
	 */
	std::shared_ptr<BaseWindow> m_glWindow;


    /**
	 * \var m_controller
	 * \p Pointe sur l'instance existante de la manette
	 */
	static std::shared_ptr<Controller> m_controller;

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
	// Pour empecher une instanciation.
	Application() {};
public:
    /**
	 * \return L'instance existante du singleton
	 */
	static std::shared_ptr<Application> getSingleton() { return _getSingleton(); }

    /**
	 * \return L'instance existante de la fenetre
	 */
	std::shared_ptr<BaseWindow>  getWindow()           { return m_glWindow;      }
    /**
	 * \return L'instance existante de la manette
	 */
	std::shared_ptr<Controller>  getController()       { return m_controller;    }
    /**
	 * \return Execute la huehuehue
	 */
	int run(int = 0, char ** = 0);
};
