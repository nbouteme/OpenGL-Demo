#include <Emerald.hpp>

extern char         emerald_obj[];
extern unsigned int emerald_obj_len;

using namespace std;
using namespace glm;

Emerald::Emerald() :
	Model(string(emerald_obj, emerald_obj_len)),
	m_shader(Shader::BasicShader())
{
	action = &Emerald::waitInput;
	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");
	m_univPos  = glGetUniformLocation(m_shader->getProgramid(),    "viewPos");
}

void Emerald::draw(const Camera &cam)
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shader->getProgramid());

	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(cam.m_view));//cam.View.getValue()));
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));
	glUniform3f(m_univPos, cam.getPosition().x, cam.getPosition().y, cam.getPosition().z);

	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);

}

void Emerald::waitInput()
{
	if(glfwGetKey(GLWindow::getMainWindow(), GLFW_KEY_F))
		action = &Emerald::rotate;
}

void Emerald::rotate()
{
	if(rotation >= kGoalRotation)
	{
		rotation = 0.0f;
		action = &Emerald::waitInput;
		return;
	}
	else
		rotation += 3.14f * 2 / 60;
	rotateZ(3.14f * 2 / 60);
}

void Emerald::update()
{
	(this->*action)(); // absolument degueulasse.
}
