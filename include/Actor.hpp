/**
 * \author N.Boutemeur
 */

#pragma once

/**
 * \struct Actor
 *  La classe Actor définie des classes qui peuvent être mises à jour et
 * réagir à des entrées
 */
struct Actor
{
	/**
	 * \brief Met à jour un acteur
	 */
	virtual void update() = 0;
};
