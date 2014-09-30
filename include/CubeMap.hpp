#pragma once

#include <Shader.hpp>
#include <Model.hpp>

class CubeMap : public Model
{
	unsigned m_tID;
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;

public:
	CubeMap();
	virtual void draw(const Camera &);
	virtual void update() {};
	unsigned getEnvTexture() { return m_tID; }
};
