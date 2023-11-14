#include "Enemy.h"

void Enemy::Initialize() {

	input = Input::GetInstance();
	pos = { 0.0f,0.0f };
	speed = 10.0f;
	dead = false;
}

void Enemy::Update() {

	if (pos.x >= 980.0f) {
		speed = -10.0f;
	}


	if (pos.x <= 0) {
		speed = 10.0f;
	}

	pos.x += speed;

}

void Enemy::Draw() {
	if (!dead) {
		Novice::DrawBox(int(pos.x), int(pos.y), 300, 300, 0.0f, BLACK, kFillModeSolid);
	}
}