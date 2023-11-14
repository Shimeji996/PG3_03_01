#include <Novice.h>
#include "GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	std::unique_ptr<GameManager> sceneManager = std::make_unique<GameManager>();
	sceneManager->Run();
	return 0;
}