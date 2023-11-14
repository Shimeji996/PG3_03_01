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

	Vector2 EnemyPos, BulletPos;

	const std::list<PlayerBullet*>& playerBullets = player->GetBullets();

	for (PlayerBullet* bullet : playerBullets) {
	
		EnemyPos = enemy->Pos();
		
		BulletPos = bullet->GetWorldPosition();

		if (EnemyPos.x + 300 >= BulletPos.x &&
			BulletPos.x + 50 >= EnemyPos.x &&
			EnemyPos.y + 300 >= BulletPos.y &&
			BulletPos.y + 50 >= EnemyPos.y) {
			
			enemy->OnCollision();
			bullet->OnCollision();
		}
	}

}