#include <BetaRoom.hpp>

#include <CubeMap.hpp>
#include <Torus.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>

using namespace std;

BetaRoom::BetaRoom()
{
	// Instancie les éléments de la scène
	m_torus   = make_shared<Torus>();
	m_emerald = make_shared<Emerald>();
	m_poly    = make_shared<Polyedre>();
	m_cubemap = make_shared<CubeMap>();

	// Les ajoutes à la scène
	addModel(m_poly);
	addModel(m_emerald); // TODO: probleme d'ordre de dessin ?
	addModel(m_torus);

	// Déplace deux élements
	m_poly ->setPosition(glm::vec3( 1.0f, 0.0f, 0.0f));
	m_torus->setPosition(glm::vec3(-1.0f, 0.0f, 0.0f));
}

void BetaRoom::render()
{
	if(m_cubemap)
		m_cubemap->draw(*m_cam); // Si une skybox a été définie pour cette scène, on la déssine.
	Scene::render();
}
