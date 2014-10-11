#include <Camera.hpp>

#include <memory>

#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Application.hpp>
#include <GLWindow.hpp>
#include <Controller.hpp>

using namespace std;
using namespace glm;

// un peu con de la part de glfw d'utiliser des double pour des coordonnees en pixels
void onHovering(GLFWwindow *win, double x, double y)
{
	static int oldx, oldy;
	(void)win;
	if(glfwGetMouseButton(*(GLWindow*)Application::getSingleton()->getWindow().get(), 0) == GLFW_PRESS)
	{
		Camera &self = *((GLWindow*)Application::getSingleton()->getWindow().get())->m_cam;

		float xangle = 3.141529f / 4 / self.width;
		float yangle = 3.141529f / 4 / self.height;

		vec3 right = cross(vec3(0.0f, 1.0f, 0.0f), self.m_direction); // une normale perpendiculaire a une norme vers le haut et la direction de la vue (droite dans l'espace vue)
		vec3 up = cross(self.m_direction, right); // une normale perpendiculaire a la direction de la vue et du vecteur droite (haut dans l'espace vue)

		self.m_direction = rotate(self.m_direction, float(y - oldy) * -yangle, right);
		self.m_direction = rotate(self.m_direction, float(x - oldx) * xangle, up);

	}

	oldx = x, oldy = y;
}

Camera::Camera(GLWindow *Parent) :
	m_projection(perspective(45.0f, 1600.0f / 900, 0.1f, 10.0f)),
	m_controller(Parent->getController()),
	m_position(vec3(-1.5f, 1.3f, -0.81f)),
	m_direction  (vec3(0.7f, -0.5f, 0.5f)),
	m_glWin(Parent),
	m_view(lookAt(m_position,
				  m_direction * 0.1f,
				  vec3(0.0f, 1.0f, 0.0f)))
{
	glfwSetCursorPosCallback(*Parent, &onHovering);
}

void Camera::update()
{
	vec3 right = cross(vec3(0.0f, 1.0f, 0.0f), m_direction);

	// TODO: changer ca
	if(glfwGetKey(*m_glWin, GLFW_KEY_UP)     == GLFW_PRESS) m_position += m_direction * 0.1f;
	if(glfwGetKey(*m_glWin, GLFW_KEY_DOWN)   == GLFW_PRESS) m_position -= m_direction * 0.1f;
	if(glfwGetKey(*m_glWin, GLFW_KEY_RIGHT)  == GLFW_PRESS) m_position -= right * 0.1f;
	if(glfwGetKey(*m_glWin, GLFW_KEY_LEFT)   == GLFW_PRESS) m_position += right * 0.1f;

	vec2 mstick;
	if(m_controller && length(mstick = m_controller->getMainStickPosition()) > 0.25f)
	{
		m_position += m_direction * -mstick.y * 0.1f;
		m_position += right * -mstick.x * 0.1f;
	}
	if(m_controller && length(mstick = m_controller->getSecondaryStickPosition()) > 0.25f)
	{
		vec3 up = cross(m_direction, right);
		m_direction = rotate(m_direction, mstick.y * 0.1f, right);
		m_direction = rotate(m_direction, -mstick.x * 0.1f, up);

	}

	m_view = glm::lookAt(m_position,
						 m_direction + m_position,
						 glm::vec3(0.0f, 1.0f, 0.0f));
}
