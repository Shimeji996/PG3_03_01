#pragma once
#include <Input.h>
#include <Novice.h>

class Enemy
{
public:
	void Initialize();
	void Update();
	void Draw();

	Vector2 Pos() { return pos; }

	void OnCollision() { dead = true; }

	bool Dead() { return dead; };
private:


	Input* input;
	Vector2 pos;

	float speed;
	bool dead;
};

