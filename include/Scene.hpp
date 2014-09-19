#pragma once

#include <vector>

#include <Camera.hpp>
#include <Model.hpp>

class Scene
{
	std::vector<Model> m_models;
public:
	void render(const Camera &cam);
};
