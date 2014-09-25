#pragma once

#include <Shader.hpp>
#include <Model.hpp>

class Mesh : public Model
{
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;
public:
	// FIXME: Cette classe n'est la que pour demonstration
	Mesh();
	Mesh(const Mesh &) = default;
	Mesh(Mesh &&) = default;
	virtual void draw(const Camera &);
};
