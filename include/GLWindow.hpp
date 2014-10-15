/**
 * \author N.Boutemeur
 */

#pragma once

#include <BaseWindow.hpp>

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Controller;
class Camera;

/**
 * \class GLWindow
 *  La classe GLWindow s'occupe de l'interface graphique et de la boucle de rendu principale
 */
class GLWindow : public BaseWindow
{
	/**
	 * \var m_win
	 * \brief Pointeur sur la fenêtre interne
	 */
	GLFWwindow* m_win;
	/**
	 * \var 
	 * \brief Pointeur sur l'instance unique de la manette
	 */
	std::shared_ptr<Controller> m_controller;
public:
	GLWindow();
	virtual ~GLWindow() final;
	/**
	 * \brief Permet la conversion implicite vers le type fenêtre de base
	 * \return un pointeur sur la fenêtre de base
	 */
	operator GLFWwindow*() const { return m_win; }
	/**
	 * \param argc Le nombre d'arguments
	 * \param argv argc arguments
	 * \brief exécute la boucle de rendue
	 * \return l'état de sortie
	 */
	virtual int run(int = 0, char ** = 0) override;
	/**
	 * \return un pointeur sur l'instance existante de la fenêtre
	 */
	static GLWindow *getMainWindow();
	/**
	 * \return un pointeur sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller> getController() { return m_controller; }
};
