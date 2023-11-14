#include "Stage.h"

void Stage::Initialize() {

	input = Input::GetInstance();
	player = std::make_unique<Player>();
	player->Initialize();

	enemy = std::make_unique<Enemy>();
	enemy->Initialize();

}

void Stage::Update() {

	player->Update();
	enemy->Update();

	CheckAllCollision();

	if (enemy->Dead()) {
		sceneNo = CLEAR;
	}

}

void Stage::Draw() {

	player->Draw();
	enemy->Draw();

}

void Stage::CheckAllCollision() {

	if (input->TriggerKey(DIK_RETURN)) {
		enemy->OnCollision();
	}

	Vector2 posA, posB;

	const std::list<PlayerBullet*>& playerBullets = player->GetBullets();

	for (PlayerBullet* bullet : playerBullets) {
	
		posA = enemy->Pos();
		
		posB = bullet->GetWorldPosition();

		if (posA.x + 300 >= posB.x &&
			posB.x + 50 >= posA.x &&
			posA.y + 300 >= posB.y &&
			posB.y + 50 >= posA.y) {
			
			enemy->OnCollision();
			bullet->OnCollision();
		}
	}

}