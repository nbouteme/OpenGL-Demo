#include <BetaRoom.hpp>

BetaRoom::BetaRoom(Camera &cam) : Scene(cam)
{
	m_emerald = make_shared<Emerald>();
	m_cubemap = make_shared<CubeMap>();
	addModel(m_emerald);
}

void BetaRoom::render()
{
	if(m_cubemap)
		m_cubemap->draw(m_cam);
	Scene::render();
}
