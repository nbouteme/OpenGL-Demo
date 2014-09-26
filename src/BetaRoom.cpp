#include <BetaRoom.hpp>

BetaRoom::BetaRoom()
{
	m_emerald = make_shared<Emerald>();
	addModel(m_emerald);
}
