#pragma once

#include <vector>
#include <string>

#include <DrawableComponent.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Model : DrawableComponent
{
	unsigned m_vao = 0, m_vbo = 0, m_ebo = -1;
public:
	glm::mat4 m_modelMatrix;
	virtual ~Model() {};
	virtual void draw() = 0;
protected:
	Model(const std::string &OBJFilename);
	Model(const float *vData, unsigned vsize, const unsigned *elements = nullptr, unsigned esize = 0);
	Model(const std::vector<float> &vData);
	Model(const std::vector<float> &vData, const std::vector<unsigned> &elements);
};
