#pragma once

#include <Scene.hpp>
#include <CubeMap.hpp>
#include <Emerald.hpp>

using namespace std;

class BetaRoom : public Scene
{
	shared_ptr<CubeMap> m_cubemap;
	shared_ptr<Emerald> m_emerald;
public:
	BetaRoom(Camera &);
	virtual void render();
	virtual ~BetaRoom() {};
};
