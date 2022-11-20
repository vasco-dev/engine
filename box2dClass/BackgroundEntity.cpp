#include "BackgroundEntity.h"


BackgroundEntity::BackgroundEntity() : Entity() {

	_bmpFile = "./graphics/galaxy2.bmp";

	_tileWidth = 640;
	_tileHeight = 480;

	_tileMapCol = 1;
	_tileMapRow = 1;

	_currentTileX = 0;
	_currentTileY = 0;


	startPos = b2Vec2(-320, -240);

	_scrollSpeed = 100.f;

	EntityStart();
}
void BackgroundEntity::EntityStart() {
	Entity::EntityStart();

	_body->SetTransform(startPos, 0);
	_body->SetLinearDamping(0.2f);

	SDL_Window* tempWindow = MainEngine::GetInstance()->GetWindow();
	SDL_GetWindowSize(tempWindow, &_maxWindowBorderX, &_maxWindowBorderY);

	_maxWindowBorderX *= 0.5;
	_maxWindowBorderY *= 0.5;

	float tempX = (float)_maxWindowBorderX;
	float tempY = (float)_maxWindowBorderY;

	_maxWindowBorderVec = b2Vec2(tempX, tempY);

	SDL_SetTextureBlendMode(_entityTexture ,SDL_BLENDMODE_NONE);

}

void BackgroundEntity::EntityEventUpdate(SDL_Event* event) {

	if (_playerEntity == nullptr) {
		
		std::list <Entity*> list = MainEngine::GetInstance()->GetEntityList();

		for (Entity* listItem : list){
			if ((PlayerControlledEntity*)listItem->_body != nullptr)
				_playerEntity = (PlayerControlledEntity*)listItem;
				std::cout << "found player" << std::endl;

		}
	}

}


void BackgroundEntity::EntityUpdate() {
	//b2Vec2 playerVel = _playerEntity->_body->GetLinearVelocity();
	//if (playerVel.x != 0) {
	//	_body->SetLinearVelocity({ -0.05f * playerVel.x, _body->GetLinearVelocity().y});
	//}
	//if (playerVel.y!= 0) {
	//	_body->SetLinearVelocity({ _body->GetLinearVelocity().x, -0.05f * playerVel.y });
	//}

}

void BackgroundEntity::EntityRenderUpdate() {

	//

	////_body->SetLinearVelocity({ 0, -playerVel });
 
 
 
	b2Vec2 pos = _body->GetPosition();

	pos = -_playerEntity->_body->GetPosition();
	
	pos.x -= 1000;
	pos.y -= 1000;

	pos *= 0.33;

	_body->SetTransform(pos, 0);

	//if (pos.x > _maxWindowBorderVec.x) {

	//	b2Vec2 newPos = { pos.x - 10, pos.y };
	//	_body->SetTransform(newPos, 0);
	//	_body->SetLinearVelocity({ 0,0 });

	//}
	//if (pos.y > _maxWindowBorderVec.y) {

	//	b2Vec2 newPos = { pos.x, pos.y - 10 };
	//	_body->SetTransform(newPos, 0);
	//	_body->SetLinearVelocity({ 0,0 });
	//}
	//if (pos.x < _maxWindowBorderTreshold) {

	//	b2Vec2 newPos = { pos.x + 10, pos.y };
	//	_body->SetTransform(newPos, 0);
	//	_body->SetLinearVelocity({ 0,0 });

	//}
	//if (pos.y < _maxWindowBorderTreshold) {

	//	b2Vec2 newPos = { pos.x, pos.y + 10 };
	//	_body->SetTransform(newPos, 0);
	//	_body->SetLinearVelocity({ 0,0 });
	//}




	RenderTexture(true, 0, 0, true);

}