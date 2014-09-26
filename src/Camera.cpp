#include <Camera.hpp>

using namespace glm;

Camera::Camera(GLWindow *Parent) :
	m_position(vec3(0.0f, -0.000001f, 2.0f)),
	m_center  (vec3(0.0f, 0.0f, 0.0f)),
	m_glWin(Parent),
	View    (lookAt(m_position,
					m_center,
					vec3(0.0f, 0.0f, 1.0f))),
	m_view    (lookAt(m_position,
					  m_center,
					  vec3(0.0f, 0.0f, 1.0f))),
	m_projection(perspective(45.0f, 1600.0f / 900, 0.1f, 10.0f))
{
}

void Camera::update()
{
	// oh boi here we go
	glm::vec3 delta((glfwGetKey(*m_glWin, GLFW_KEY_UP)    == GLFW_PRESS) *  0.1f +
					(glfwGetKey(*m_glWin, GLFW_KEY_DOWN)  == GLFW_PRESS) * -0.1f,
					(glfwGetKey(*m_glWin, GLFW_KEY_LEFT)  == GLFW_PRESS) *  0.1f +
					(glfwGetKey(*m_glWin, GLFW_KEY_RIGHT) == GLFW_PRESS) * -0.1f,
					(glfwGetKey(*m_glWin, GLFW_KEY_Z)     == GLFW_PRESS) *  0.1f +
					(glfwGetKey(*m_glWin, GLFW_KEY_X)     == GLFW_PRESS) * -0.1f);

	m_position += delta;

	m_view = glm::lookAt(m_position,
						 m_center,
						 glm::vec3(0.0f, 0.0f, 1.0f));
}
