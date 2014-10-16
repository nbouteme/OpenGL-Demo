#include <Emerald.hpp>

#include <GLWindow.hpp>
#include <Camera.hpp>
#include <Shader.hpp>
#include <Assets.hpp>
#include <Controller.hpp>

using namespace std;
using namespace glm;

Emerald::Emerald() :
	Model(OBJRes->getString("emerald.obj")),
	m_shader(make_shared<Shader>(ShaderRes->getString("baseVS.glsl")   .c_str(), 
								 ShaderRes->getString("emeraldFS.glsl").c_str()))
{
	action = &Emerald::waitInput; // Comportement par défaut
	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");
	m_univPos  = glGetUniformLocation(m_shader->getProgramid(),    "viewPos");
}

void Emerald::draw(const Camera &cam)
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shader->getProgramid()); // Active le VAO(qui va lui même bind le VBO contenant les données de l'émeraude) et le shader

	// Met a jour les uniform dans le shader
	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(cam.m_view));
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));

	glUniform3f(m_univPos,
				cam.getPosition().x,
				cam.getPosition().y,
				cam.getPosition().z);

	// Dessine
	glDrawArrays(GL_TRIANGLES, 0, vertNum);

	// Désactive le VAO
	glBindVertexArray(0);
	glUseProgram(0);
}

void Emerald::waitInput()
{
	if(glfwGetKey(*GLWindow::getMainWindow(), GLFW_KEY_F) ||
	   m_controller->getButtons()[0])                       // Un appui sur une touche modifie son comportement 
		action = &Emerald::translate; // Le comportement devient "Rotation"
}

void Emerald::translate()
{
	if(!goalReached && m_position[1] >= kGoalTranslate)
		goalReached = true;
	else if(goalReached)
	{
		m_position[1] -= 2.0f / 60;
		if(m_position[1] <= 0.0f)
		{
			m_position[1] = goalReached = false;
			action = &Emerald::waitInput;
			return;
		}
	}
	else
		m_position[1] += 2.0f / 60;
	rebuildModelMat();
}

void Emerald::update()
{
	(this->*action)(); // Effectue l'action bindée
}
