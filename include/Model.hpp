#pragma once

#include <memory>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <DrawableComponent.hpp>
#include <Actor.hpp>

class Model : public DrawableComponent, public Actor 
{
public:
	Model()              = default;
	Model(Model &&)      = default;
	Model(const Model &) = default;
	virtual ~Model();

	virtual void draw  (const Camera &) = 0;
	virtual void update() = 0;

	// Utiliser seulement pour positionner sur la scene

	void scaleX    (float = 0.2f);
	void scaleY    (float = 0.2f);
	void scaleZ    (float = 0.2f);
	void rotateX   (float = 0.1f);
	void rotateY   (float = 0.1f);
	void rotateZ   (float = 0.1f);
	void translateX(float = 0.1f);
	void translateY(float = 0.1f);
	void translateZ(float = 0.1f);

protected:
	unsigned m_vao = 0, m_vbo = 0, m_ebo = -1;
	glm::mat4 m_modelMatrix;
	int vertNum, faceNum;

	Model(const std::string &);
	Model(const float *, unsigned, const unsigned * = nullptr, unsigned = 0);
	Model(const std::vector<float> &);
	Model(const std::vector<float> &, const std::vector<unsigned> &);
};
