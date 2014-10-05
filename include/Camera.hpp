#pragma once
#include <Actor.hpp>

#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct GLFWwindow;
class GLWindow;
class Controller;

class Camera : public Actor
{
	friend void onHovering(GLFWwindow *, double, double);
	friend void resizeCallback(GLFWwindow *, int, int);

	glm::mat4 m_projection;
	int width, height;
public:
	Camera(GLWindow *Parent);
	virtual void update();
	std::shared_ptr<Controller> m_controller;

	glm::mat4 getView      () const { return m_view; };
	glm::mat4 getProjection() const { return m_projection; };
	glm::vec3 getPosition  () const { return m_position; };
	glm::vec3 m_position, m_direction; 
	GLWindow *m_glWin;
	glm::mat4 m_view;
};
