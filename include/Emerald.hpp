#pragma once

#include <Camera.hpp>
#include <Shader.hpp>
#include <Model.hpp>

class Emerald : public Model
{
	const float kGoalRotation = 3.14f * 2;
	float rotation = 0.0f;
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;
	void (Emerald::*action)();
	void waitInput();
	void rotate();
public:
	Emerald();

	virtual void draw(const Camera&);
	virtual void update();
};
