#pragma once
#include <Input.h>
#include <Novice.h>
#include <list>
#include "PlayerBullet.h"

class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Attack();

	const std::list<PlayerBullet*>& GetBullets()const { return bullets; }
private:

	Input* input;
	Vector2 pos;

	std::list<PlayerBullet*> bullets;
};

