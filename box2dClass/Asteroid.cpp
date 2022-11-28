#include "Asteroid.h"


Asteroid::Asteroid(): FlyingEntity() {

	_bmpFile = "./graphics/GAster32.bmp";

	_tileWidth = 32;
	_tileHeight = 32;

	_tileMapCol = 8;
	_tileMapRow = 2;

	_currentTileX = 0;
	_currentTileY = 0;

	EntityStart();
}

Asteroid::~Asteroid() {
	std::cout << "Asteroid Destroyed" << std::endl;
}

void Asteroid::EntityStart() {
	Entity::EntityStart();

	Move(0, 1, vel);

}


void Asteroid::EntityEventUpdate(SDL_Event* event) {

}


void Asteroid::EntityUpdate() {

}


void Asteroid::EntityRenderUpdate() {

	RenderTexture(true, 0, 0, false);
}