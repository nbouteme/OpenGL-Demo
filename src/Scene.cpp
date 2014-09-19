#include <Scene.hpp>

void Scene::render(const Camera &cam)
{
	for(auto model : m_models)
		model->draw(cam.getView());
}
