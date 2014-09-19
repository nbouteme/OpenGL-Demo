#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	glm::vec3 m_position, m_center; 
	static glm::mat4 m_projection;
	Camera();
	void update();
	glm::mat4 getView() const { return m_view; };
private:
	glm::mat4 m_view;
};
