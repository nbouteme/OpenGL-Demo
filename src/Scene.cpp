#include <Scene.hpp>
#include <Camera.hpp>
#include <Model.hpp>
#include <CubeMap.hpp>
#include <Effect.hpp>
#include <GL/glew.h>

using namespace std;

Scene::Scene() : m_cam(make_shared<Camera>())
{
}

void Scene::render()
{
	if(!m_effects.empty()) m_effects[0]->active();

	m_cam->update(); // Mets à jour la caméra
	if(m_cubemap)
		m_cubemap->draw(*m_cam); // Si une skybox a été définie pour cette scène, on la déssine.
	for(auto model : m_models) // Pour chaque modèle présent dans la scène
		model->update(), model->draw(*m_cam); // Met à jour le model, puis le dessine
	if(!m_effects.empty())
		for(unsigned i = 1; i < m_effects.size(); ++i)
			m_effects[i]->active(), m_effects[i - 1]->present();
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	if(!m_effects.empty()) m_effects[m_effects.size() - 1]->present();
}
