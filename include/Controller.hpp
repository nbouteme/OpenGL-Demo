#pragma once

#include <vector>

#include <glm/glm.hpp>

#include <GLWindow.hpp>

class GLWindow;

class Controller
{
	friend GLWindow;
	static std::shared_ptr<Controller> getController();
public:

	virtual glm::vec2 getMainStickPosition()      = 0;
	virtual glm::vec2 getSecondaryStickPosition() = 0;
	virtual glm::vec2 getTriggers()               = 0;
	virtual std::vector<bool> getButtons()        = 0;
	virtual ~Controller(){};
};
