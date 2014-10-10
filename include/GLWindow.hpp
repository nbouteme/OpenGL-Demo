/**
 * \author N.Boutemeur
 */

#pragma once

#include <BaseWindow.hpp>

#include <memory>

#define GLEW_STATIC
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
	 * \brief Pointeur sur la fenetre interne
	 */
	GLFWwindow* m_win;
	/**
	 * \var 
	 * \brief Pointeur sur l'intance unique de la manette
	 */
	std::shared_ptr<Controller> m_controller;
public:
	/**
	 * \brief Constructeur par defaut
	 */
	GLWindow();
	/**
	 * \brief Destructeur
	 */
	virtual ~GLWindow() final;
	/**
	 * \brief Permet la conversion implicite vers le type fenetre de base
	 * \return un pointeur sur la fenetre de base
	 */
	operator GLFWwindow*() const { return m_win; }
	/**
	 * \param argc Le nombre d'arguments
	 * \param argv argc arguments
	 * \brief execute le huehuehue
	 * \return l'etat de sortie
	 */
	virtual int run(int = 0, char ** = 0) override;
	/**
	 * \return un pointeur sur l'instance existante de la fenetre
	 */
	static GLWindow *getMainWindow();
	/**
	 * \return un pointeur sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller> getController() { return m_controller; }
	/**
	 * \var m_cam
	 * \param un pointeur sur l'instance existante de la camera
	 */
	static std::shared_ptr<Camera> m_cam;
};
