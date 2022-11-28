#include "AsteroidSpawner.h"


AsteroidSpawner::AsteroidSpawner(){
	AsteroidSpawner::EntityStart();
}

AsteroidSpawner::~AsteroidSpawner() {

}

void AsteroidSpawner::SpawnAsteroid(float posX, float posY) {

	Asteroid* asteroidToSpawn = new Asteroid();
	asteroidToSpawn->_body->SetTransform({posX, posY}, 0);

	_asteroidList.push_back(asteroidToSpawn);

	if (_asteroidList.size() >= _maxAsteroidCount) {
		Asteroid* tempAsteroid = _asteroidList.front();
		tempAsteroid->~Asteroid();
		_asteroidList.erase(_asteroidList.begin());
	}
}


void AsteroidSpawner::EntityStart() {

	MainEngine::GetInstance()->AddEntityList((Entity*)this);

}


void AsteroidSpawner::EntityEventUpdate(SDL_Event* event) {

}


void AsteroidSpawner::EntityUpdate() {

	float randX = rand()/(float)RAND_MAX;

	if (randX < spawnChancePercent * percentScalar) {

		randX *= 100.f * maxSpawnCoordX * 1/spawnChancePercent;
		randX = (randX < minSpawnCoordX ? minSpawnCoordX : randX);

		std::cout << "rand spawn: " << randX << std::endl;	

		SpawnAsteroid(randX, spawnCoordY);
	}

}


void AsteroidSpawner::EntityRenderUpdate() {

}
