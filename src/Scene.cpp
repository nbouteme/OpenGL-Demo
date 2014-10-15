#include <Scene.hpp>
#include <Camera.hpp>
#include <Model.hpp>

using namespace std;

Scene::Scene() : m_cam(make_shared<Camera>())
{
}

void Scene::render()
{
	m_cam->update(); // Mets à jour la caméra
	for(auto model : m_models) // Pour chaque modèle présent dans la scène
		model->update(), model->draw(*m_cam); // Met à jour le model, puis le dessine
}
