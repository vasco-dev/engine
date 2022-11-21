#include "PlayerControlledEntity.h"
#include "BulletEntity.h"



PlayerControlledEntity::PlayerControlledEntity() : ControlledEntity() {

	_bmpFile = "./graphics/Ship1.bmp";

	_tileWidth = 64;
	_tileHeight = 64;

	_tileMapCol = 6;
	_tileMapRow = 1;

	_currentTileX = 0;
	_currentTileY = 0;



	startPos = b2Vec2(96, 96);

	vel = 10.f;

	_bulletList.reserve(_maxBulletCount);

	EntityStart();
}
void  PlayerControlledEntity::EntityStart(){
	Entity::EntityStart();

	_body->SetLinearDamping(0.f);

	SDL_Window* tempWindow = MainEngine::GetInstance()->GetWindow();	
	SDL_GetWindowSize(tempWindow, &_maxWindowBorderX, &_maxWindowBorderY );

	_maxWindowBorderX -= _maxWindowBorderTreshold + _tileWidth;
	_maxWindowBorderY -= _maxWindowBorderTreshold + _tileHeight;

	float tempX = (float)_maxWindowBorderX;
	float tempY = (float)_maxWindowBorderY;

	_maxWindowBorderVec = b2Vec2(tempX, tempY);

	std::cout << "max window x : " << tempX << "max window y : " << tempY << std::endl;

}


void PlayerControlledEntity::EntityEventUpdate(SDL_Event* event) {


	switch (event->type) {
		case SDL_KEYDOWN: InputHandler(&event->key, true); break;
		case SDL_KEYUP: InputHandler(&event->key, false); break;
	}


	//std::cout << "player x : " << _body->GetPosition().x << "player y : " << _body->GetPosition().y << std::endl;

	b2Vec2 pos = _body->GetPosition();

	if (pos.x > _maxWindowBorderVec.x ){

		b2Vec2 newPos = { pos.x - 10, pos.y };
		_body->SetTransform(newPos, 0);
		_body->SetLinearVelocity({0,0});

	}
	if (pos.y > _maxWindowBorderVec.y) {

		b2Vec2 newPos = { pos.x, pos.y - 10 };
		_body->SetTransform(newPos, 0);
		_body->SetLinearVelocity({ 0,0 });
	}
	if (pos.x < _maxWindowBorderTreshold ) {

		b2Vec2 newPos = { pos.x + 10, pos.y};
		_body->SetTransform(newPos, 0);
		_body->SetLinearVelocity({ 0,0 });

	}
	if (pos.y < _maxWindowBorderTreshold) {

		b2Vec2 newPos = { pos.x, pos.y + 10};
		_body->SetTransform(newPos, 0);
		_body->SetLinearVelocity({0,0});
	}

}


void PlayerControlledEntity::EntityUpdate() {

}


void PlayerControlledEntity::EntityRenderUpdate() {
	
	int frameToUse = 3; // 4 is middle position

	if( _inputVec.x != 0 ){
		if (_inputVec.x < 0) {
			frameToUse = --_currentTileX;
		}
		else {
			frameToUse = ++_currentTileX;
		}
	}
	else {
		frameToUse = 3;
	}
	
	if (frameToUse > _tileMapCol) {
		frameToUse = _tileMapCol;
	}	
	if (frameToUse < 0) {
		frameToUse = 0;
	}


	RenderTexture(false, frameToUse,0, false);

	_lastFramePos = _body->GetPosition();

}


void PlayerControlledEntity::InputHandler(SDL_KeyboardEvent* keyEvent, bool isDown) {

	if (keyEvent == nullptr) {
		Move(0, 0, vel);
		return;
	}

	if (isDown) {
		SDL_Keycode pressedKey = keyEvent->keysym.sym;

		switch (pressedKey) {

			case SDLK_w: _inputVec.y = -1;	_holdMoveUp = true	; break;
			case SDLK_s: _inputVec.y = 1;	_holdMoveDown = true	; break;
			case SDLK_a: _inputVec.x = -1;	_holdMoveLeft = true	; break;
			case SDLK_d: _inputVec.x = 1;	_holdMoveRight = true; break;
		}

		Move(_inputVec.x, _inputVec.y, vel);
	}
	else {
		SDL_Keycode pressedKey = keyEvent->keysym.sym;

		switch (pressedKey) {

			case SDLK_w: _holdMoveDown ?	_inputVec.y = 1	: _inputVec.y = 0;
						_holdMoveUp = false;
						break;

			case SDLK_s: _holdMoveUp ?	_inputVec.y = -1 : _inputVec.y = 0;
						_holdMoveDown = false;
						break;

			case SDLK_a: _holdMoveRight ?	_inputVec.x = 1	: _inputVec.x = 0;
						_holdMoveLeft = false;
						break;

			case SDLK_d: _holdMoveLeft ?	_inputVec.x = -1 : _inputVec.x = 0;
						_holdMoveRight = false;
						break;

			case SDLK_SPACE: Attack(); 
						return;
						break;

		}
		Move(_inputVec.x, _inputVec.y, vel);
		
	}

}

bool PlayerControlledEntity::Attack(){

	BulletEntity* bullet = new BulletEntity();
	bullet->_body->SetTransform(_body->GetPosition() + bulletOffset, 0);
	bullet->_body->SetLinearVelocity(b2Vec2(0, -10000));
	 
	_bulletList.push_back(bullet);

	if (_bulletList.size() >= _maxBulletCount) {
		BulletEntity* tempBullet = _bulletList.front();
		tempBullet->~BulletEntity();
		_bulletList.erase(_bulletList.begin());
	}

	return true;
}