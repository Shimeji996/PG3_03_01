#include "Player.h"

void Player::Initialize() {

	input = Input::GetInstance();
	pos = { 1280.0f / 2.0f - 50.0f,360.0f };
}

void Player::Update() {

	if (input->PushKey(DIK_W)) {
		pos.y -= 10.0f;
	}

	if (input->PushKey(DIK_S)) {
		pos.y += 10.0f;
	}

	if (input->PushKey(DIK_A)) {
		pos.x -= 10.0f;
	}
	if (input->PushKey(DIK_D)) {
		pos.x += 10.0f;
	}

	Attack();

	for (PlayerBullet* bullet : bullets) {

		bullet->Update();
	}

	bullets.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});
}

void Player::Draw() {

	Novice::DrawBox(int(pos.x), int(pos.y), 50, 50, 0.0f, WHITE, kFillModeSolid);
	for (PlayerBullet* bullet : bullets) {
		bullet->Draw();
	}

}

void Player::Attack() {

	if (input->PushKey(DIK_SPACE)) {
		Vector2 velocity(0, 10.0f);
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(pos, velocity);

		bullets.push_back(newBullet);
	}

}