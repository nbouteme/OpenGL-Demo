/**
 * \author N.Boutemeur
 */

#pragma once

class Camera;

/**
 * \struct DrawableComponent
 *  La classe DrawingComponent défini des objets qui peuvent être dessinés
 */
struct DrawableComponent
{
	/**
	 * \brief Dessine un objet sur la cible active
	 */
	virtual void draw(const Camera &) = 0;
	virtual ~DrawableComponent() {};
};
