#include <Polyedre.hpp>

#include <GLWindow.hpp>
#include <Assets.hpp>
#include <Controller.hpp>

using namespace std;
using namespace glm;

/*
 * Même principe que l'émeraude
 */

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

	glUniform3f(m_univPos,
				cam.getPosition().x,
				cam.getPosition().y,
				cam.getPosition().z);

	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
}

void Polyedre::waitInput()
{
	if(glfwGetKey(*GLWindow::getMainWindow(), GLFW_KEY_G) ||
	   m_controller->getButtons()[2])
		action = &Polyedre::scale;
}

void Polyedre::scale()
{
	if(cScale <= kGoalMaxScale)
	{
		cScale = 1.0f;
		action = &Polyedre::waitInput;
		return;
	}
	else
		cScale -= 1.0f / 30;
	setScale(glm::vec3(cScale < 0.0f ? -cScale : cScale));
}

void Polyedre::update()
{
	(this->*action)();
}
