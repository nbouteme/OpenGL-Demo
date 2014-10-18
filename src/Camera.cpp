#include <Camera.hpp>

#include <memory>

#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Application.hpp>
#include <GLWindow.hpp>
#include <Controller.hpp>

using namespace std;
using namespace glm;

void onHovering(GLFWwindow *win, double x, double y)
{
	static int oldx, oldy;
	// si le bouton de la souris est enfoncé
	if(glfwGetMouseButton(*(GLWindow*)Application::getSingleton()->getWindow().get(), 0) == GLFW_PRESS)
	{
		// Recupere la caméra
		int dim[4];
		glGetIntegerv(GL_VIEWPORT, dim);
		Camera &self = *(Camera *)glfwGetWindowUserPointer(win);

		// calcule la difference d'angle par pixel pour un champs de vision de 45 deg
		float xangle = 3.141529f / 4 / dim[2];
		float yangle = 3.141529f / 4 / dim[3];

		vec3 right = cross(vec3(0.0f, 1.0f, 0.0f), self.m_direction); // une normale perpendiculaire a une norme vers le haut et la direction de la vue (droite dans l'espace vue)
		vec3 up = cross(self.m_direction, right); // une normale perpendiculaire a la direction de la vue et du vecteur droite (haut dans l'espace vue)

		self.m_direction = rotate(self.m_direction, float(y - oldy) * -yangle, right);
		self.m_direction = rotate(self.m_direction, float(x - oldx) * xangle, up);

	}

	oldx = x, oldy = y;
}

Camera::Camera() :
	m_projection(perspective(45.0f, 1600.0f / 900, 0.1f, 10.0f)),
	m_controller(Application::getSingleton()->getController()),
	m_position(vec3(-1.5f, 1.3f, -0.81f)),
	m_direction  (vec3(0.7f, -0.5f, 0.5f)),
	m_glWin(GLWindow::getMainWindow()),
	m_view(lookAt(m_position,
				  m_direction * 0.1f,
				  vec3(0.0f, 1.0f, 0.0f)))
{
	glfwSetWindowUserPointer(*m_glWin, this);	
	glfwSetCursorPosCallback(*m_glWin, &onHovering);
}

void Camera::update()
{
	vec3 right = cross(vec3(0.0f, 1.0f, 0.0f), m_direction);
	auto oldPos = m_position;

	// Avance ou recule dans la direction de la vue
	if(glfwGetKey(*m_glWin, GLFW_KEY_UP)     == GLFW_PRESS) m_position += m_direction * 0.1f;
	if(glfwGetKey(*m_glWin, GLFW_KEY_DOWN)   == GLFW_PRESS) m_position -= m_direction * 0.1f;
	// Avance ou recule sur la droite de l'ecran
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
	if(length(m_position) >= 9.0f) m_position = oldPos;
	m_view = glm::lookAt(m_position,
						 m_direction + m_position,
						 glm::vec3(0.0f, 1.0f, 0.0f));
}
