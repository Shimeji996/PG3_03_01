#include "Clear.h"

void Clear::Initialize() {

	input = Input::GetInstance();
}

void Clear::Update() {

	if (input->TriggerKey(DIK_RETURN)) {
		sceneNo = TITLE;
	}

}

void Clear::Draw() {

}