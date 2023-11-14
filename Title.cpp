#include "Title.h"

void Title::Initialize() {

	input = Input::GetInstance();

}

void Title::Update() {

	if (input->TriggerKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}

}

void Title::Draw() {

}