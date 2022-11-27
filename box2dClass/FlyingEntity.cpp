#include "FlyingEntity.h"


FlyingEntity::FlyingEntity() : ControlledEntity() {

	_bmpFile = "./graphics/MAster32.bmp";

	_tileWidth = 32;
	_tileHeight = 32;

	_tileMapCol = 8;
	_tileMapRow = 2;

	_currentTileX = 0;
	_currentTileY = 0;

	vel = 1000.f;

	EntityStart();
}

FlyingEntity::~FlyingEntity() {

}

void  FlyingEntity::EntityStart() {
	Entity::EntityStart();

	Move(0, 1, vel);

}


void FlyingEntity::EntityEventUpdate(SDL_Event* event) {

}


void FlyingEntity::EntityUpdate() {

}


void FlyingEntity::EntityRenderUpdate() {

	RenderTexture(true, 0, 0, false);
}