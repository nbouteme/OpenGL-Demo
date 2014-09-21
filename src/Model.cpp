#include <Model.hpp>

using namespace std;

Model::Model(const string &OBJFilename)
{
	(void)OBJFilename;
	// TODO: Implementer un parser pour le format OBJ
	abort();
}

Model::Model(const float *vData, unsigned vsize, 
			 const unsigned *elements, unsigned esize)
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers     (1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer     (GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, vsize * sizeof(float), vData, GL_STATIC_DRAW);

	// Si on recycle les points pour dessiner les triangles
	if(elements)
	{
		glGenBuffers     (1, &m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, esize, elements, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	}
}

Model::Model(const vector<float> &vData) : Model(vData.data(), vData.size())
{}

Model::Model(const vector<float> &vData, const vector<unsigned> &elements) :
	Model(vData.data(), vData.size(), elements.data(), elements.size())
{}

Model::~Model()
{
	glDeleteBuffers(1, &m_vao);

	if(m_ebo != -1U)
		glDeleteBuffers(1, &m_ebo);

	glDeleteVertexArrays(1, &m_vao);
}

void Model::rotateX      (float angle) { m_modelMatrix = glm::rotate(   m_modelMatrix, angle, glm::vec3(1.0f,         0.0f,     0.0f));}
void Model::rotateY      (float angle) { m_modelMatrix = glm::rotate(   m_modelMatrix, angle, glm::vec3(0.0f,         1.0f,     0.0f));}
void Model::rotateZ      (float angle) { m_modelMatrix = glm::rotate(   m_modelMatrix, angle, glm::vec3(0.0f,         0.0f,     1.0f));}
void Model::translateX(float distance) { m_modelMatrix = glm::translate(m_modelMatrix,        glm::vec3(distance,     0.0f,     0.0f));}
void Model::translateY(float distance) { m_modelMatrix = glm::translate(m_modelMatrix,        glm::vec3(    0.0f, distance,     0.0f));}
void Model::translateZ(float distance) { m_modelMatrix = glm::translate(m_modelMatrix,        glm::vec3(    0.0f,     0.0f, distance));}
