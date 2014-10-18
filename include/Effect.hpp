/**
 * \author N.Boutemeur
 */

#pragma once

#include <Model.hpp>

#include <memory>

class Shader;

/**
 * \class Effect
 * La classe Effect définie des effets de post-processing
 */
class Effect
{
	unsigned fbId, texId, rbId, m_vao, m_vbo;
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
	static std::shared_ptr<Effect> ReverseColor();
	static std::shared_ptr<Effect> Blur();
	void active();
	void present();
	virtual ~Effect();
};
