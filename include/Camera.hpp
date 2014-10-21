/**
 * \author N.Boutemeur
 */

#pragma once

#include <Actor.hpp>
#include <memory>

#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>

struct GLFWwindow;
class GLWindow;
class Controller;

/**
 *\class Camera Définie une caméra dans l'espace
 */
class Camera : public Actor
{
	friend void onHovering(GLFWwindow *, double, double);
	/**
	 * \var m_projection
	 * \p Matrice de projection utilisée lors du rendu
	 */
	glm::mat4 m_projection;
	/**
	 * \var width
	 * \p Largeur en pixel de la surface de rendu
	 */
	/**
	 * \var height
	 * \p Hauteur en pixel de la surface de rendu
	 */
	int width, height;
public:
	/**
	 * \brief Instancie une caméra, liée à une fenêtre
	 */
	Camera();
	/**
	 * \brief Mets à jour la caméra
	 */
	virtual void update();
	/**
	 * \var m_controller
	 * \p Pointe sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller> m_controller;
	/**
	 * \deprecated Utilisez m_view plutôt
	 * \brief Renvoie une copie de la matrice de vue
	 */
	glm::mat4 getView      () const { return m_view; };
	/**
	 * \brief Renvoie une copie de la matrice de projection
	 */
	glm::mat4 getProjection() const { return m_projection; };
	/**
	 * \brief Renvoie la position de la caméra
	 */
	glm::vec3 getPosition  () const { return m_position; };
	/**
	 * \var m_direction
	 * \p Direction dans laquelle regarde la caméra
	 */
	/**
	 * \var m_position
	 * \p Position de la caméra dans le monde
	 */
	glm::vec3 m_position, m_direction; 
	/**
	 * \var m_glWin
	 * \p Pointeur vers l'unique instance de la fenêtre
	 */
	GLWindow *m_glWin;
	/**
	 * \var m_view
	 * \p Matrice de vue de la caméra
	 */
	glm::mat4 m_view;
};
