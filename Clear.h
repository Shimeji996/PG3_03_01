#pragma once
#include "IScene.h"
#include <Input.h>

class Clear : public IScene
{
public:
	void Initialize();
	void Update();
	void Draw();

private:
	Input* input;
};

