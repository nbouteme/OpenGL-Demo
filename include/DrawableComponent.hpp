#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class DrawableComponent
{
public:
	virtual ~DrawableComponent() {};
	virtual void draw(glm::mat4 view) = 0;
};
