/**
 * \author N.Boutemeur
 */

#pragma once

#include <Shader.hpp>
#include <Model.hpp>

class CubeMap : public Model
{
	/**
	 * \var m_tID
	 * \p Identifiant de texture OpenGL
	 */
	unsigned m_tID;

	/**
	 * \var m_shader
	 * \p Programme shader utilisé pour le dessin
	 */
	std::shared_ptr<Shader> m_shader;

	int m_uniModel, m_uniView, m_uniProj, m_univPos;
public:
	/**
	 * \brief Instancie une skybox
	 */
	CubeMap();
	/**
	 * \brief dessine la skybox
	 */
	virtual void draw(const Camera &);
	/**
	 * \brief met a jour une skybox
	 */
	virtual void update() {};
	/**
	 * \brief Recupere l'identifiant de la texture utilisée
	 * \return la texture d'environnement
	 */
	unsigned getEnvTexture() { return m_tID; }
};
