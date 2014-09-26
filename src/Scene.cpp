#include <Scene.hpp>

void Scene::render(Camera &cam)
{
	cam.update();
	for(auto model : m_models)
		model->update(), model->draw(cam);
}
