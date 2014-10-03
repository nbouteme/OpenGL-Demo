#include <Polyedre.hpp>

#include <Assets.hpp>

using namespace std;
using namespace glm;

Polyedre::Polyedre() :
	Model(OBJRes->getString("polyedre.obj")),
	m_shader(make_shared<Shader>(ShaderRes->getString("baseVS.glsl")    .c_str(), 
								 ShaderRes->getString("polyedreFS.glsl").c_str()))

{
	action = &Polyedre::waitInput;
	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");
	m_univPos  = glGetUniformLocation(m_shader->getProgramid(),    "viewPos");
}

void Polyedre::draw(const Camera &cam)
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shader->getProgramid());

	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(cam.m_view));
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));
	glUniform3f(m_univPos, cam.getPosition().x, cam.getPosition().y, cam.getPosition().z);

	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
}

void Polyedre::waitInput()
{
	if(glfwGetKey(GLWindow::getMainWindow(), GLFW_KEY_F))
		action = &Polyedre::rotate;
}

void Polyedre::rotate()
{
	if(rotation >= kGoalRotation)
	{
		rotation = 0.0f;
		action = &Polyedre::waitInput;
		return;
	}
	else
		rotation += 3.14f * 2 / 60;
	rotateY(3.14f * 2 / 60);
}

void Polyedre::update()
{
	(this->*action)(); // absolument degueulasse.
}
