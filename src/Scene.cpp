#include <Scene.hpp>
#include <Camera.hpp>
#include <Model.hpp>

Scene::Scene(Camera &cam) : m_cam(cam)
{
}

void Scene::render()
{
	m_cam.update();
	for(auto model : m_models)
		model->update(), model->draw(m_cam);
}
