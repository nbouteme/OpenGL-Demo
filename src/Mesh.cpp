#include <Camera.hpp>
#include <Mesh.hpp>

// Seulement pour demonstration //
// Pour les 3 cristaux, deriver de Model et s'inspirer de cette classe

extern char baseFS_glsl[]; // Code source des shader
extern char baseVS_glsl[];
extern char cube_obj[];

extern unsigned int baseFS_glsl_len; // leurs tailles
extern unsigned int baseVS_glsl_len;
extern unsigned int cube_obj_len;

const float tri[] = 
{
	-0.5f, -0.866025f / 2, 0.0f,
	 0.5f, -0.866025f / 2, 0.0f,
	 0.0f,  0.866025f / 2, 0.0f
};

using namespace std;
using namespace glm;

Mesh::Mesh() :
	Model(string(cube_obj, cube_obj_len)),
//	Model(tri, 9),
	m_shader(make_shared<Shader>(string(baseVS_glsl, baseVS_glsl_len).c_str(), 
								 string(baseFS_glsl, baseFS_glsl_len).c_str()))
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

//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if(m_ebo != -1U)
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, vertNum);

	glBindVertexArray(0);
}
