#pragma once

#include <Scene.hpp>
#include <CubeMap.hpp>
#include <Gem.hpp>
#include <Emerald.hpp>
#include <Polyedre.hpp>

class BetaRoom : public Scene
{
	std::shared_ptr<Gem>      m_gem;
    std::shared_ptr<CubeMap>  m_cubemap;
    std::shared_ptr<Emerald>  m_emerald;
	std::shared_ptr<Polyedre> m_poly;
public:
	BetaRoom(Camera &);
	virtual void render();
	virtual ~BetaRoom() {};
};
