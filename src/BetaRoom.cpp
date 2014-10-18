#include <BetaRoom.hpp>

#include <CubeMap.hpp>
#include <Torus.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>
#include <Mesh.hpp>
#include <Effect.hpp>

using namespace std;

BetaRoom::BetaRoom()
{
	// Instancie les éléments de la scène
	m_emerald = make_shared<Emerald>();
	m_poly    = make_shared<Polyedre>();
	m_torus   = make_shared<Torus>();
	addEffect(Effect::Blur());
	addEffect(Effect::ReverseColor());

	setEnvironment(make_shared<CubeMap>());

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
	Scene::render();
}
