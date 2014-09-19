#include <Model.hpp>

using namespace std;

Model::Model(const string &OBJFilename)
{
	(void)OBJFilename;
	// TODO: Implementer un parser pour le format OBJ
	abort();
}

Model::Model(const float *vData, unsigned vsize, const unsigned *elements, unsigned esize)
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

Model::Model(const vector<float> &vData, const vector<unsigned> &elements) : Model(vData.data(), vData.size(), elements.data(), elements.size())
{}

