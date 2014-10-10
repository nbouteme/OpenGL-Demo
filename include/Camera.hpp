/**
 * \author N.Boutemeur
 */

#pragma once
#include <Actor.hpp>

#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct GLFWwindow;
class GLWindow;
class Controller;

class Camera : public Actor
{
	friend void onHovering(GLFWwindow *, double, double);
	friend void resizeCallback(GLFWwindow *, int, int);

	/**
	 * \var m_projection
	 * \p Matrice de projection utilisee lors du rendu
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
	 * \brief Instancie une camera, liee a une fenetre
	 */
	Camera(GLWindow *Parent);
	/**
	 * \brief Mets a jour la camera
	 */
	virtual void update();
	/**
	 * \var m_controller
	 * \p Pointe sur l'instance existante de la manette
	 */
	std::shared_ptr<Controller> m_controller;

	/**
	 * \deprecated Utilisez m_view plutot
	 * \brief Renvoie une copie de la matrice de vue
	 */
	glm::mat4 getView      () const { return m_view; };
	/**
	 * \brief Renvoie une copie de la matrice de projection
	 */
	glm::mat4 getProjection() const { return m_projection; };
	/**
	 * \brief Renvoie la position de la camera
	 */
	glm::vec3 getPosition  () const { return m_position; };

	/**
	 * \var m_direction
	 * \p Direction dans laquelle regarde la camera
	 */
	/**
	 * \var m_position
	 * \p Position de la camera dans le monde
	 */
	glm::vec3 m_position, m_direction; 
	/**
	 * \var m_glWin
	 * \p Pointeur vers l'unique instance de la fenetre
	 */
	GLWindow *m_glWin;
	/**
	 * \var m_view
	 * \p Matrice de vue de la camera
	 */
	glm::mat4 m_view;
};
