#include "ControlledEntity.h"
#include <vector>

ControlledEntity::ControlledEntity() : Entity(){

}
ControlledEntity::~ControlledEntity(){

}

bool ControlledEntity::Move(int x, int y, float speed) {
	
	b2Vec2 inputSpeed = b2Vec2_zero;	
	inputSpeed = { (float)x , (float)y };
	inputSpeed.Normalize();
	inputSpeed *= speed;

	_body->SetLinearVelocity(inputSpeed);

	return true;
}


bool ControlledEntity::Attack() { return true; }

void ControlledEntity::EntityStart() {}
void ControlledEntity::EntityEventUpdate(SDL_Event* event) {}
void ControlledEntity::EntityUpdate(/*float deltaTime*/) {}
void ControlledEntity::EntityRenderUpdate() {}