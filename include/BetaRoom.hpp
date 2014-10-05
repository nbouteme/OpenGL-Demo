#pragma once

#include <Scene.hpp>
#include <CubeMap.hpp>
#include <Torus.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>

class BetaRoom : public Scene
{
	std::shared_ptr<Torus>    m_torus;
    std::shared_ptr<CubeMap>  m_cubemap;
    std::shared_ptr<Emerald>  m_emerald;
	std::shared_ptr<Polyedre> m_poly;
public:
	BetaRoom(Camera &);
	virtual void render();
	virtual ~BetaRoom() {};
};
