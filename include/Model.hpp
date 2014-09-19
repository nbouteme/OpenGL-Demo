#pragma once

#include <memory>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <DrawableComponent.hpp>

class Model : DrawableComponent
{
public:
	glm::mat4 m_modelMatrix;
/*	Model(const Model &) = default;
	Model(Model &&) = default;
	Model() = default;
//	virtual ~Model() {};
*/	virtual void draw(glm::mat4 view) = 0;
protected:
	unsigned m_vao = 0, m_vbo = 0, m_ebo = -1;

	Model(const std::string &OBJFilename);
	Model(const float *vData, unsigned vsize, const unsigned *elements = nullptr, unsigned esize = 0);
	Model(const std::vector<float> &vData);
	Model(const std::vector<float> &vData, const std::vector<unsigned> &elements);
};
