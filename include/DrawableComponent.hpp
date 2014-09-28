#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Camera.hpp>

struct DrawableComponent
{
	virtual ~DrawableComponent() {};
	virtual void draw(const Camera &) = 0;
};
