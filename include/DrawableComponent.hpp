#pragma once

class DrawableComponent
{
public:
	virtual ~DrawableComponent() {};
	virtual void draw() = 0;
};
