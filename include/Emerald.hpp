/**
 * \author N.Boutemeur
 */

#pragma once

#include <Model.hpp>

class Camera;
class Shader;

/**
 * \class Emerald
 *  La classe Emerald defini une emeraude dessinable
 */
class Emerald : public Model
{
	/**
	 * \var kGoalRotation
	 * \p limite de la rotation en radians 
	 */
	const float kGoalTranslate = 1.0f;
	bool goalReached;
	/**
	 * \var rotation
	 * \p angle de orotation actuel en radians 
	 */
	float rotation = 0.0f;
	/**
	 * \var m_shader
	 * \p Programme shader utilise pour le dessin 
	 */
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;
	/**
	 * \var action
	 * \p Pointeur sur le comportement actuel de l'objet 
	 */
	void (Emerald::*action)();
	/**
	 * \brief Comportement normale de l'objet, en attente d'entree
	 */
	void waitInput();
	/**
	 * \brief Comportement actif de l'objet, en rotation
	 */
	void translate();
public:
	/**
	 * \brief Constructeur par defaut
	 */
	Emerald();
	/**
	 * \brief Dessine une emeraude selon la camera
	 * \param cam La camera utilisé pour le dessin
	 */
	virtual void draw(const Camera&);
	/**
	 * \brief Met a jour l'etat de l'emeraude
	 */
	virtual void update();
};
