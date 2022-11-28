#pragma once

#include "Entity.h"
#include "Asteroid.h"

#include <vector>

class AsteroidSpawner : Entity{
	public:
		AsteroidSpawner();
		~AsteroidSpawner();

		void EntityStart();
		void EntityEventUpdate(SDL_Event* event);
		void EntityUpdate(/*float deltaTime*/);
		void EntityRenderUpdate();
	private:
		void SpawnAsteroid(float posX, float posY);

	private:

		float percentScalar = 1 / 100.f;

		float spawnChancePercent = 0.5;

		int spawnCoordY = 10;

		int minSpawnCoordX = 10;
		int maxSpawnCoordX = 790;


		std::vector<Asteroid*> _asteroidList;
		int _maxAsteroidCount = 10;


};

