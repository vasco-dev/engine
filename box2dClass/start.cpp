#include "GameLoop.h"
#include "MainEngine.h"

#include "Entity.h"
#include "PlayerCharacter.h"
#include "Background.h"
#include "AsteroidSpawner.h"
#include "FlyingEntity.h"

static Background* _background = nullptr;

static AsteroidSpawner* _asteroidSpawner = nullptr;

static PlayerCharacter* _playerCharacter = nullptr;


void AddEntities() {
	//MainEngine::GetInstance();

	_background = new Background;

	_asteroidSpawner = new AsteroidSpawner;

	_playerCharacter = new PlayerCharacter;

}
 


int main(int argv, char** args) {

	GameLoop::GetInstance()->StartGameLoop();

	AddEntities();

	GameLoop::GetInstance()->RunGameLoop();
	return 0;
}

