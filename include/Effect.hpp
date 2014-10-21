/**
 * \author N.Boutemeur
 */

#pragma once

#include <Model.hpp>

#include <memory>

class Shader;

/**
 * \class Effect
 * La classe Effect définie des effets de post-processing, vous devez
 * la deriver si vous vouler utiliser d'autre information dans le 
 * post processing comme le tampon de profondeur.
 */
class Effect
{
	/**
	 * \var fbId
	 * Référence au framebuffer
	 */
	/**
	 * \var texId
	 * Référence à la texture
	 */
	/**
	 * \var texId
	 * Référence au renderbuffer
	 */
	/**
	 * \var m_vao
	 * Référence au Vertex array object interne
	 */
	/**
	 * \var m_vbo
	 * Référence au Vertex buffer object (carré)
	 */
	unsigned fbId, texId, rbId, m_vao, m_vbo;
	/**
	 * \var m_shader
	 * Effet utilisé lors du dessin du tampon interne
	 */
	std::shared_ptr<Shader> m_shader;
protected:
	/**
	 * Construit un effet à partir d'un shader
	 */
	Effect(const char *);
public:
	/**
	 * Construit un effet de base qui ne fait rien
	 */
	static std::shared_ptr<Effect> BasicEffect();
	/**
	 * Construit un effet de base qui inverse les pixels affichés
	 */
	static std::shared_ptr<Effect> ReverseColor();
	/**
	 * Construit un effet de base qui floute les bords de l'ecran
	 */
	static std::shared_ptr<Effect> Blur();
	/**
	 * Active l'effet, à appeler avant de dessiner
	 */
	void active();
	/**
	 * Dessine le contenue dans le tampon actif
	 * Cela permet de 'chaîner' les effets
	 */
	void present();
	virtual ~Effect();
};
