#include <Camera.hpp>
#include <Mesh.hpp>

// Seulement pour demonstration //
// Pour les 3 cristaux, deriver de Model et s'inspirer de cette classe

extern char baseFS_glsl[]; // Code source des shader
extern char baseVS_glsl[];

extern unsigned int baseFS_glsl_len; // leurs tailles
extern unsigned int baseVS_glsl_len;

const float tri[] = 
{
	 0.0,  0.5, 0.0,
	 0.5,  -0.5, 0.0,
	-0.5, -0.5, 0.0
};

Mesh::Mesh() : 
	Model(tri, 9),
	m_shader(std::make_shared<Shader>(std::string(baseVS_glsl, baseVS_glsl_len).c_str(), 
									  std::string(baseFS_glsl, baseFS_glsl_len).c_str()))
{
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);
    glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Mesh::draw(glm::mat4 view)
{
	glBindVertexArray(m_vao);
	glUseProgram(m_shader->getProgramid());

	// TODO: Separer la mise a jour des uniforms du dessin
	int uModel = glGetUniformLocation(m_shader->getProgramid(), "model");
	glUniformMatrix4fv(uModel, 1, GL_FALSE, glm::value_ptr(m_modelMatrix));

	int uView = glGetUniformLocation(m_shader->getProgramid(), "view");
	glUniformMatrix4fv(uView, 1, GL_FALSE, glm::value_ptr(view));

	int uProj = glGetUniformLocation(m_shader->getProgramid(), "projection");
	glUniformMatrix4fv(uProj, 1, GL_FALSE, glm::value_ptr(Camera::m_projection));

	if(m_ebo != -1U)
	{
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	glBindVertexArray(0);
}
