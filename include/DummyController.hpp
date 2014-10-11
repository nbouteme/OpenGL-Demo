/**
 * \author N.Boutemeur
 */

#pragma once

#include <Controller.hpp>

/**
 * \class DummyController
 * Une manette qui ne fait jamais rien.
 */
struct DummyController : public Controller
{
	/*
	 * \return La position du stick principal, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getMainStickPosition()       final override { return glm::vec2(); }
	/*
	 * \return La position du stick secondaire, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getSecondaryStickPosition()  final override { return glm::vec2(); }
	/*
	 * \return La position des gâchettes, les 2 axes dans l'interval [-1; 1]
	 */
	virtual glm::vec2 getTriggers()                final override { return glm::vec2(); }
	/*
	 * \return Les bouttons pressés
	 */
	virtual std::vector<bool> getButtons()         final override { return std::vector<bool>(20); }
	virtual ~DummyController() final override{};
};
