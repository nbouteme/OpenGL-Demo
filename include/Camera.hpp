#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLWindow.hpp>
#include <Actor.hpp>

#include <utils/Property.hpp>

class Camera
{
public:
	Camera(GLWindow *Parent);
	virtual void update();
	glm::mat4 getView      () const { return m_view; };
	glm::mat4 getProjection() const { return m_projection; };
	glm::vec3 getPosition  () const { return m_position; };
	glm::vec3 m_position, m_center; 
	GLWindow *m_glWin;
	glm::mat4 m_view;
private:
	glm::mat4 m_projection;
};
