#pragma once

enum SCENE { TITLE, STAGE, CLEAR };

class IScene
{

public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	static int sceneNo;
};

