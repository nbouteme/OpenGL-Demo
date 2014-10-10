/**
 * \author N.Boutemeur
 */

#pragma once

#include <Shader.hpp>
#include <Model.hpp>

/**
 * \class Mesh Cette classe sert d'example pour deriver de Model
 */
class Mesh : public Model
{
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;
public:
	// FIXME: Cette classe n'est la que pour demonstration
	Mesh();
	virtual void draw(const Camera &);
	virtual void update() {};
};
