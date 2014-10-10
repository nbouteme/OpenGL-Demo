/**
 * \author N.Boutemeur
 */

#pragma once

/**
 * \struct DrawableComponent
 *  La classe DrawingComponent defini des objets qui peuvent etre dessinable
 */
struct DrawableComponent
{
	/**
	 * \brief Pour la derivation
	 */
	virtual ~DrawableComponent() {};

	/**
	 * \brief Dessine un objet sur la cible active
	 */
	virtual void draw(const Camera &) = 0;
};
