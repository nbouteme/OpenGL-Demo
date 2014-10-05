#pragma once

#include <Controller.hpp>

class DummyController : public Controller
{
public:
	virtual glm::vec2 getMainStickPosition()       final override { return glm::vec2(); }
	virtual glm::vec2 getSecondaryStickPosition()  final override { return glm::vec2(); }
	virtual glm::vec2 getTriggers()                final override { return glm::vec2(); }

	virtual std::vector<bool> getButtons()         final override { return std::vector<bool>(20); }
	virtual ~DummyController() final override{};
};
