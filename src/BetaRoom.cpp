#include <BetaRoom.hpp>

#include <CubeMap.hpp>
#include <Torus.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>

using namespace std;

BetaRoom::BetaRoom(Camera &cam) : Scene(cam)
{
	m_torus   = make_shared<Torus>();
    m_emerald = make_shared<Emerald>();
	m_poly    = make_shared<Polyedre>();
	m_cubemap = make_shared<CubeMap>();

	addModel(m_poly);

    m_poly->translateX(1.0f);
    addModel(m_emerald);
	m_torus->translateX(-1.0f);
	addModel(m_torus);

}

void BetaRoom::render()
{
	if(m_cubemap)
		m_cubemap->draw(m_cam);
	Scene::render();
}
