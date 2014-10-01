#include <BetaRoom.hpp>

using namespace std;

BetaRoom::BetaRoom(Camera &cam) : Scene(cam)
{
	m_emerald = make_shared<Emerald>();
	m_poly    = make_shared<Polyedre>();
	m_cubemap = make_shared<CubeMap>();
	addModel(m_poly);
	m_poly->translateX(1.0f);
	addModel(m_emerald);
}

void BetaRoom::render()
{
	if(m_cubemap)
		m_cubemap->draw(m_cam);
	Scene::render();
}
