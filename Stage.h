#pragma once
#include <memory>
#include "IScene.h"
#include <Input.h>
#include "Player.h"
#include "Enemy.h"

class Stage : public IScene
{
public:
	void Initialize();
	void Update();
	void Draw();

	void CheckAllCollision();

private:
	Input* input;

	std::unique_ptr<Player> player;
	std::unique_ptr<Enemy> enemy;
};

