#include "PlayerCharacter.h"



PlayerCharacter::PlayerCharacter() : PlayerControlledEntity() {

	vel = 200.f;

	startPos = { 350.f, 400.f };

	_body->SetTransform(startPos, 0);

}
PlayerCharacter::~PlayerCharacter(){

	
}
