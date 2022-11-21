#include "GameLoop.h"

GameLoop* GameLoop::_gameLoopInstance = nullptr;

GameLoop::GameLoop() {
	return;
}

void GameLoop::RunGameLoop(){

	MainEngine::GetInstance()->Init();
	MainEngine::GetInstance()->Start();

	while (MainEngine::GetInstance()->GetIsRunning()) {
		MainEngine::GetInstance()->EventUpdate();
		MainEngine::GetInstance()->Update();
		MainEngine::GetInstance()->RenderUpdate();
	}

	exit(0);

	return;

}


