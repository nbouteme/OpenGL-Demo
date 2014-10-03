#include <Camera.hpp>
#include <Mesh.hpp>

// Seulement pour demonstration //
// Pour les 3 cristaux, deriver de Model et s'inspirer de cette classe

#include <Assets.hpp>

const float tri[] = 
{
	-0.5f, -0.866025f / 2, 0.0f,
	 0.5f, -0.866025f / 2, 0.0f,
	 0.0f,  0.866025f / 2, 0.0f
};

using namespace std;
using namespace glm;

Mesh::Mesh() :
	Model(OBJRes->getString("cube.obj")),
	m_shader(make_shared<Shader>(ShaderRes->getString("baseVS.glsl").c_str(), 
								 ShaderRes->getString("baseFS.glsl").c_str()))
{
	m_uniModel = glGetUniformLocation(m_shader->getProgramid(),      "model");
	m_uniView  = glGetUniformLocation(m_shader->getProgramid(),       "view");
	m_uniProj  = glGetUniformLocation(m_shader->getProgramid(), "projection");
	m_univPos  = glGetUniformLocation(m_shader->getProgramid(),    "viewPos");
}

void Mesh::draw(const Camera &cam)
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shader->getProgramid());

	glUniformMatrix4fv(m_uniModel, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniformMatrix4fv(m_uniView,  1, GL_FALSE, value_ptr(cam.getView()));
	glUniformMatrix4fv(m_uniProj,  1, GL_FALSE, value_ptr(cam.getProjection()));
	glUniform3f(m_univPos, cam.getPosition().x, cam.getPosition().y, cam.getPosition().z);

	if(m_ebo != -1U)
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
}
