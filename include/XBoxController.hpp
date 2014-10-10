/**
 * \author N.Boutemeur
 */

#pragma once

#include <Controller.hpp>

/**
 * \class XBoxController
 *  La classe XBoxController gere les manettes de Xbox360 connectees
 */
class XBoxController : public Controller
{
	int m_joyNum;
public:
	/*
	 * \brief instancie la manette selon le nomero de manette
	 */
	XBoxController(int);

	/*
	 * \return la position du stick principale, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getMainStickPosition()      final override;
	/*
	 * \return la position du stick secondaire, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getSecondaryStickPosition() final override;
	/*
	 * \return la position des gachette, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getTriggers()               final override;
	/*
	 * \return les bouttons pressés
	 */
	virtual std::vector<bool> getButtons()        final override;
	virtual ~XBoxController()                     final override {};
};
