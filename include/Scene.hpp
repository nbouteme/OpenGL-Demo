#pragma once

#include <set>
#include <memory>

#include <Camera.hpp>
#include <Model.hpp>

class Scene
{
	glm::mat4 m_view;
	std::set<std::shared_ptr<Model>> m_models;

protected:
	Camera &m_cam;

	void addModel(const std::shared_ptr<Model> &model)
		{ m_models.insert(model); }

	template <typename T>
	void addModel(const T& derived)
	{
		//Type safe car derived doit bien deriver de Model, pour compiler
		addModel(std::shared_ptr<Model>(derived));
	}

public:
	virtual void render();
	std::set<std::shared_ptr<Model>> getModels() { return m_models; }
	Scene(Camera &);
	virtual ~Scene(){};
};
