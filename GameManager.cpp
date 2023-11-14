#include "GameManager.h"
#include <Novice.h>
const char kWindowTitle[] = "LE2B_17_マスダリュウ_タイトル";

GameManager::GameManager() {
	sceneArr_[TITLE] = std::make_unique<Title>();
	sceneArr_[STAGE] = std::make_unique<Stage>();
	sceneArr_[CLEAR] = std::make_unique<Clear>();
}

GameManager::~GameManager() {}

int GameManager::Run() {

	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		prevSceneNo_ = currentsceneNo_;

		currentsceneNo_ = IScene::sceneNo;

		if (prevSceneNo_ != currentsceneNo_) {
			sceneArr_[currentsceneNo_]->Initialize();
		}

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		Novice::ScreenPrintf(0, 0, "ENTER = Scene Change");
		Novice::ScreenPrintf(0, 20, "SPACE = Shot");

		//更新処理 ここから
		sceneArr_[currentsceneNo_]->Update();

		//描画処理　ここから
		sceneArr_[currentsceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();


	return 0;
}