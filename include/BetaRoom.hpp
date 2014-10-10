/**
 * \author N.Boutemeur
 */

#pragma once

#include <Scene.hpp>
#include <CubeMap.hpp>
#include <Torus.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>

class BetaRoom : public Scene
{
	/**
	 * \var m_torus
	 * \p le noeud de torus de la scene
	 */
	std::shared_ptr<Torus>    m_torus;
	/**
	 * \var m_cubemap
	 * \p la skybox de la scene
	 */
    std::shared_ptr<CubeMap>  m_cubemap;
	/**
	 * \var m_emerald
	 * \p l'emeraude de la scene
	 */
    std::shared_ptr<Emerald>  m_emerald;
	/**
	 * \var m_poly
	 * \p le crystal de la scene
	 */
	std::shared_ptr<Polyedre> m_poly;
public:
	/**
	 * \param cam La camera a utiliser pour le rendu
	 */
	BetaRoom(Camera &);
	/**
	 * \brief Rends la scene sur la cible active
	 */
	virtual void render();
	/**
	 * \brief Libere les ressources
	 */
	virtual ~BetaRoom() {};
};
