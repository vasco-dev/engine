#include "GameLoop.h"
#include "MainEngine.h"

#include "Entity.h"
#include "PlayerCharacter.h"
#include "Background.h"

static Background* _background = nullptr;
static PlayerCharacter* _playerCharacter = nullptr;

void AddEntities() {
	MainEngine::GetInstance();

	_background = new Background;
	_playerCharacter = new PlayerCharacter;
}



int main(int argv, char** args) {

	GameLoop::GetInstance()->StartGameLoop();

	AddEntities();

	GameLoop::GetInstance()->RunGameLoop();
	return 0;
}

