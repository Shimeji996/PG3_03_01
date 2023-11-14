#pragma once
#include "IScene.h"
#include <memory>
#include <Input.h>

class Title : public IScene
{

public:
	void Initialize();
	void Update();
	void Draw();

private:
	Input* input;

};

