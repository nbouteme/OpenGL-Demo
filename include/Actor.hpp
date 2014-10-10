/**
 * \author N.Boutemeur
 */

#pragma once

/**
 * \class Actor
 *  La classe Actor defini des classe qui peuvent etre mise a jour
 */
class Actor
{
public:
	/**
	 * \brief Met a jour un acteur
	 */
	virtual void update() = 0;
};
