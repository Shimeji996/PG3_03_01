#pragma once
#include "IScene.h"
#include <Novice.h>

class ClearScene : public IScene
{
public:

	void Initialize() override;

	void Update() override;

	void Draw() override;

private:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

};

