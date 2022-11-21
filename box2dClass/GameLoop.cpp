#include "GameLoop.h"

GameLoop* GameLoop::_gameLoopInstance = nullptr;

GameLoop::GameLoop() {
	return;
}
void GameLoop::StartGameLoop() {
	MainEngine::GetInstance()->Init();
	MainEngine::GetInstance()->Start();
	return;
}

void GameLoop::RunGameLoop(){

	while (MainEngine::GetInstance()->GetIsRunning()) {
		MainEngine::GetInstance()->EventUpdate();
		MainEngine::GetInstance()->Update();
		MainEngine::GetInstance()->RenderUpdate();
	}

	exit(0);

	return;

}


