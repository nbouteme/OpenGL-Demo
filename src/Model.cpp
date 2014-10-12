#include <Model.hpp>

#include <string>
#include <unistd.h>
#include <fcntl.h>

#include <GL/glew.h>

#include <OBJData.hpp>

using namespace std;

Model::Model(const string &OBJSource)
{
	auto objd = make_shared<OBJData>(OBJSource);
	vector<float> data = objd->getData(); // lis les données du fichier source 
	vertNum = data.size();

	glGenVertexArrays(1, &m_vao); // Génère un VAO
	glGenBuffers     (1, &m_vbo); // Génère un VBO

	glBindVertexArray(m_vao); // Les active
	glBindBuffer     (GL_ARRAY_BUFFER, m_vbo);

	// Remplis le buffer avec les données
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

	// Location 0 dans le shader(position), 3 floats, 
	// ne pas normaliser, 32 octets entre les position du sommet i et i+1,
	// les positions sont au debut du groupe [position uv normales]
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 32, nullptr);
	glEnableVertexAttribArray(0);

	// Location 1 dans le shader(uv), 2 floats, 
	// ne pas normaliser, 32 octets entre les uv du sommet i et i+1,
	// les uv sont apres les 3 floats de position dans le groupe [position uv normales]
	glVertexAttribPointer(1, 2, GL_FLOAT, false, 32, (void *)12);
	glEnableVertexAttribArray(1);

	// Location 2 dans le shader(normal), 3 floats, 
	// ne pas normaliser, 32 octets entre les normales du sommet i et i+1,
	// les normales sont apres les 3 floats de position et les 2 float d'uv
	// dans le groupe [position uv normales]
	glVertexAttribPointer(2, 3, GL_FLOAT, false, 32, (void *)20);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

Model::Model(const float *vData, unsigned vsize, 
			 const unsigned *elements, unsigned esize)
{
	// même principe qu'au dessus
	glGenVertexArrays(1, &m_vao);
	glGenBuffers     (1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer     (GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, vsize, vData, GL_STATIC_DRAW);

	// Si on recycle les points pour dessiner les triangles
	if(elements)
	{
		glGenBuffers     (1, &m_ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, esize, elements, GL_STATIC_DRAW);
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);
    glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

Model::Model(const vector<float> &vData) : Model(vData.data(), vData.size())
{}

Model::Model(const vector<float> &vData, const vector<unsigned> &elements) :
	Model(vData.data(), vData.size(), elements.data(), elements.size())
{}

Model::~Model()
{
	if(m_ebo != -1U)
		glDeleteBuffers(1, &m_ebo); // Libère l'éventuel EBO

	glDeleteVertexArrays(1, &m_vao);// Libère le VBO
	glDeleteBuffers(1, &m_vao);// Libère le VAO
}

void Model::rebuildModelMat()
{
	m_modelMatrix = glm::translate(  glm::mat4(), m_position);

	m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation[0], glm::vec3(1.0f, 0.0f, 0.0f));
	m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation[1], glm::vec3(0.0f, 1.0f, 0.0f));
	m_modelMatrix = glm::rotate(m_modelMatrix, m_rotation[2], glm::vec3(0.0f, 0.0f, 1.0f));

	m_modelMatrix = glm::scale(m_modelMatrix, m_scale);
}

void Model::setScale(const glm::vec3 &scale)
{
	m_scale = scale;
	rebuildModelMat();
}

void Model::setPosition(const glm::vec3 &pos)
{
	m_position = pos;
	rebuildModelMat();
}

void Model::setRotation   (const glm::vec3 &rot)
{
	m_rotation = rot;
	rebuildModelMat();
}
