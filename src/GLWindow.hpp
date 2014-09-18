#pragma once

#include "BaseWindow.hpp"

class GLWindow : public BaseWindow
{
public:
	virtual int run(int argc = 0, char **argv = 0) override;
};
