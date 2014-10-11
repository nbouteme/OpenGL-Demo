/**
 * \author N.Boutemeur
 */

#pragma once

/**
 * \struct Actor
 *  La classe Actor définie des classes qui peuvent être mises à jour
 */
struct Actor
{
	/**
	 * \brief Met à jour un acteur
	 */
	virtual void update() = 0;
};
