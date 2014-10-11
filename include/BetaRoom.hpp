/**
 * \author N.Boutemeur
 */

#pragma once

#include <Scene.hpp>

class CubeMap;
class Torus;
class Emerald;
class Polyedre;

/**
 *\class BetaRoom Définie une scène constituée de 4 objets
 */
class BetaRoom : public Scene
{
	/**
	 * \var m_torus
	 * \p le noeud de torus de la scène
	 */
	std::shared_ptr<Torus>    m_torus;
	/**
	 * \var m_cubemap
	 * \p la skybox de la scene
	 */
    std::shared_ptr<CubeMap>  m_cubemap;
	/**
	 * \var m_emerald
	 * \p l'émeraude de la scène
	 */
    std::shared_ptr<Emerald>  m_emerald;
	/**
	 * \var m_poly
	 * \p le cristal de la scène
	 */
	std::shared_ptr<Polyedre> m_poly;
public:
	/**
	 * \param cam La caméra à utiliser pour le rendu
	 */
	BetaRoom(Camera &);
	/**
	 * \brief Rends la scène sur la cible active
	 */
	virtual void render();
	virtual ~BetaRoom() {};
};
