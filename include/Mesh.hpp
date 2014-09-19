#pragma once

#include <Shader.hpp>
#include <Model.hpp>

class Mesh : public Model
{
	std::shared_ptr<Shader> m_shader;
public:
	// FIXME: Ce constructeur n'est la que pour demonstration
	Mesh();
	Mesh(const Mesh &) = default;
	Mesh(Mesh &&) = default;
	virtual void draw(glm::mat4 view);
};
