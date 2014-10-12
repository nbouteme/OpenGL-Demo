/**
 * \author N.Boutemeur
 */

#pragma once

#include <Camera.hpp>
#include <Shader.hpp>
#include <Model.hpp>

/**
 * \class Polyedre
 *  La classe Polyedre defini un cristal qui est dessinable
 */
class Polyedre : public Model
{
	bool reachedMin = false;
	bool reachedMax = false;
	const float kGoalMinScale = 0.5f;
	const float kGoalMaxScale = -1.0f;
	float cScale = 1.0f;
	std::shared_ptr<Shader> m_shader;
	int m_uniModel, m_uniView, m_uniProj, m_univPos;
	void (Polyedre::*action)();
	void waitInput();
	void scale();
public:
	Polyedre();

	virtual void draw(const Camera&);
	virtual void update();
};
