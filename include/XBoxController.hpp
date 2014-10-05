#pragma once

#include <Controller.hpp>

class XBoxController : public Controller
{
	int m_joyNum;
public:
	XBoxController(int);

	virtual glm::vec2 getMainStickPosition()      final override;
	virtual glm::vec2 getSecondaryStickPosition() final override;
	virtual glm::vec2 getTriggers()               final override;
	virtual std::vector<bool> getButtons()        final override;
	virtual ~XBoxController()                     final override {};	
};
