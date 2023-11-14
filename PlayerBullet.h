#pragma once
#include "Input.h"
#include <Novice.h>

class PlayerBullet
{
public:

	void Initialize(const Vector2& pos, const Vector2& velocity);

	void Update();

	void Draw();

	bool IsDead() const { return isDead; }

	Vector2 GetWorldPosition();

	void OnCollision();

private:

	Vector2 pos_;
	
	Vector2 velocity_;

	static const int32_t kLifeTime = 0;
	
	int32_t deathTimer_ = kLifeTime;

	bool isDead;

};

