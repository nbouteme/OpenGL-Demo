#pragma once

#include <Scene.hpp>
#include <Emerald.hpp>

using namespace std;

class BetaRoom : public Scene
{
	shared_ptr<Emerald> m_emerald;
public:
	BetaRoom();
};
