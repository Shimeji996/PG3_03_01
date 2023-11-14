#pragma once
#include <memory>
#include "IScene.h"
#include "Title.h"
#include "Stage.h"
#include "Clear.h"

class GameManager
{
private:

	std::unique_ptr<IScene> sceneArr_[3];

	int currentsceneNo_;
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();

	int Run();
};

