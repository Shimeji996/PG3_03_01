#include "PlayerBullet.h"

void PlayerBullet::Initialize(const Vector2& pos, const Vector2& velocity) {

	pos_ = pos;

	velocity_ = velocity;
};


void PlayerBullet::Update() {

	if (--deathTimer_ == 0) {
		isDead = true;
	}

	pos_.y -= velocity_.y;

};

void PlayerBullet::Draw() {
	Novice::DrawBox(int(pos_.x), int(pos_.y), 50, 50, 0.0f, RED, kFillModeSolid);
};

Vector2 PlayerBullet::GetWorldPosition() {
	
	Vector2 worldPos;

	worldPos.x = pos_.x;
	worldPos.y = pos_.y;

	return worldPos;
}

void PlayerBullet::OnCollision() {
	isDead = true;
}