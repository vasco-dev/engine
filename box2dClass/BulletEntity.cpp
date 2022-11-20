#include "BulletEntity.h"



BulletEntity::BulletEntity() : ControlledEntity() {

	_bmpFile = "./graphics/missile.bmp";

	_tileWidth = 16;
	_tileHeight = 12;

	_tileMapCol = 2;
	_tileMapRow = 1;

	_currentTileX = 0;
	_currentTileY = 0;

	startPos = b2Vec2(0,0);

	vel = -1000;

	std::cout << "bullet created: " << this << std::endl;

	EntityStart();

}
BulletEntity::~BulletEntity() {


	MainEngine::GetInstance()->GetWorld()->DestroyBody(_body);

	std::cout << "dropped Bullet" << std::endl;

	MainEngine::GetInstance()->RemoveEntityList(this);

}

void  BulletEntity::EntityStart() {
	Entity::EntityStart();

	_body->SetBullet(true);

	b2MassData massData;
	massData.mass = 0.1;

	_body->SetMassData(&massData);	

	_body->SetType(b2_kinematicBody);

	_bodyShape.SetAsBox(_tileWidth / 5.f, _tileHeight / 5.f);

}
void BulletEntity::EntityEventUpdate(SDL_Event* event) {
	return;
}

void BulletEntity::EntityUpdate() {
	Entity::EntityUpdate();
}

void BulletEntity::EntityRenderUpdate() {
	RenderTexture(true, 0, 0, false);
}
