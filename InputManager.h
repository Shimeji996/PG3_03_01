#pragma once
#include <Novice.h>
#include "Input.h"

class InputManager {
public:
	static InputManager* GetInstance();

	void Init();
	void Update();

	bool IsTriggerKey(BYTE KeyNumber);

private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager& obj) = delete;
	InputManager& operator=(const InputManager& obj) = delete;

	char Keys[256]{};
	char preKeys[256]{};
};