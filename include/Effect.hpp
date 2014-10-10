/**
 * \author N.Boutemeur
 */

#pragma once

/**
 * \class Effect
 * La classe Effect defini des effet de post-processing
 */
class Effect
{
protected:
	/**
	 * Construit un effet a partir d'un shader
	 */
	Effect(const Shader &);
public:
	/**
	 * Construit un effet de base qui ne fait rien
	 */
	static BasicEffect();
	virtual ~Effect() {};
};
