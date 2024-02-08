#include "InputManager.h"

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;

}

void InputManager::Init() { Novice::GetHitKeyStateAll(Keys); }

void InputManager::Update() {
	// キー入力を受け取る
	memcpy(preKeys, Keys, 256);
	Novice::GetHitKeyStateAll(Keys);
}

bool InputManager::IsTriggerKey(BYTE KeyNumber) {
	return preKeys[KeyNumber] == 0 && Keys[KeyNumber] != 0;
}