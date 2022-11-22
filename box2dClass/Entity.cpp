#include "Entity.h"




Entity::Entity(){

	_entityTexture = nullptr;
	_body = nullptr;

	_tileWidth = 96;
	_tileHeight = 96;

	_tileMapCol = 5;
	_tileMapRow = 5;

	_currentTileX = 0;
	_currentTileY = 0;

	startPos = b2Vec2(96, 96);

	_bodyDef.enabled = true;
	_bodyDef.type = b2_dynamicBody;
	_bodyDef.position = startPos;
	_bodyDef.gravityScale = 0;
	_bodyDef.linearDamping = 0;
	_bodyDef.awake = true;

	MainEngine::GetInstance()->AddEntityList(this);
}
Entity::~Entity() {

}


bool Entity::CreateTexture() {
	
	//if (_entityTexture == nullptr) {
	//	std::cout << "render failed" << std::endl;
	//	throw InitError();
	//	return false;
	//}
	_entityTexture = TextureHandler::GetInstance()->LoadTexture(_bmpFile);


	return true;
}
bool Entity::RenderTexture(bool autoSkipFrames, int frameToJumpX, int frameToJumpY, bool isFullcreen) {
	
	if (autoSkipFrames == false) {
		JumpToFrame(frameToJumpX, frameToJumpY);
	}

	SDL_Rect srcRect = { _currentTileX * _tileWidth, _currentTileY * _tileHeight, _tileWidth, _tileHeight };	// posX, posY is the position in the texture, width and height is size of each tile in the texture
	SDL_FRect dstRect = { _body->GetPosition().x, _body->GetPosition().y, _tileHeight, _tileHeight };	// posX, posY is the position in the window that the rect is going to be drawn

	//std::cout << "x: " << _body->GetPosition().x << " y: " << _body->GetPosition().y << std::endl;

	if (!TextureHandler::GetInstance()->Draw(_entityTexture, srcRect, dstRect, isFullcreen)) {
		std::cout << "draw failed" << std::endl;
		throw InitError();
		return false;
	}

	if (autoSkipFrames == true) {
		NextTileFrame();
	}

	return true;
}
bool  Entity::FreeTexture() {
	return true;
}

bool Entity::NextTileFrame() {
	
	++_currentTileX;

	if (_currentTileX >= _tileMapCol) {
		_currentTileX = 0;
		++_currentTileY;
	}
	if (_currentTileY >= _tileMapRow) {
		_currentTileX = 0;
		_currentTileY = 0;
	}


	return true;
}

bool Entity::JumpToFrame(int frameToJumpX, int frameToJumpY) {
	_currentTileX = frameToJumpX;
	_currentTileY = frameToJumpY;
	return true;
}

void Entity::EntityStart() {

	//std::cout << "entity started" << std::endl;

	_body = MainEngine::GetInstance()->GetWorld()->CreateBody(&_bodyDef);

	if (&_body == nullptr) {
		std::cout << "body failed" << std::endl;
		throw InitError();
	}

	_bodyShape.SetAsBox(_tileWidth / 2.f / 64.f, _tileHeight / 2.f / 64.f);

	_fixDef.shape = &_bodyShape;
	_fixDef.density = 1;
	_fixDef.friction = 0;

	if (&_fixDef == nullptr) {
		std::cout << "fixture failed" << std::endl;
		throw InitError();
	}

	_bodyFix = _body->CreateFixture(&_fixDef);

	_bodyFix->SetSensor(true);

	_body->SetLinearVelocity(b2Vec2(0, 0));

	transform = _body->GetTransform();

	CreateTexture();

}// will run once before the loop starts, used for setup

void Entity::EntityEventUpdate(SDL_Event* event) {} // check for events before every update
void Entity::EntityUpdate(/*float deltaTime*/) {} // update
void Entity::EntityRenderUpdate() {} // render everything after update