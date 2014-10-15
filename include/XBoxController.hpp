/**
 * \author N.Boutemeur
 */

#pragma once

#include <Controller.hpp>

/**
 * \class XBoxController
 *  La classe XBoxController gère les manettes de Xbox360 connectées
 */
class XBoxController : public Controller
{
	int m_joyNum;
	float m_sensitivity;
public:
	/*
	 * \brief instancie la manette selon le numéro de manette
	 */
	XBoxController(int, float);
	/*
	 * \return La position du stick principal, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getMainStickPosition()      final override;
	/*
	 * \return La position du stick secondaire, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getSecondaryStickPosition() final override;
	/*
	 * \return La position des gâchettes, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getTriggers()               final override;
	/*
	 * \return Les bouttons pressés
	 */
	virtual std::vector<bool> getButtons()        final override;
	virtual ~XBoxController()                     final override {};
};
