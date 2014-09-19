#include <Camera.hpp>

glm::mat4 Camera::m_projection = glm::perspective(45.0f, 1280.0f / 720.0f, 0.1f, 10.0f);

Camera::Camera() : m_position(glm::vec3(0.0f, -0.000001f, 2.0f)),
				   m_center(glm::vec3(0.0f, 0.0f, 0.0f)),
				   m_view(glm::lookAt(m_position,
									  m_center,
									  glm::vec3(0.0f, 0.0f, 1.0f)))
{
}

void Camera::update()
{
	m_view = glm::lookAt(m_position,
					   m_center,
					   glm::vec3(0.0f, 0.0f, 1.0f));
}
