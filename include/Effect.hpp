#pragma once

class Effect
{
protected:
	Effect(const Shader &);
public:
	static BasicEffect();
	virtual ~Effect() {};
};
