#pragma once
#include "FlyingEntity.h"

class Asteroid : public FlyingEntity{
	public:
		Asteroid();
		~Asteroid();

		void EntityStart();
		void EntityEventUpdate(SDL_Event* event) override;
		void EntityUpdate(/*float deltaTime*/) override;
		void EntityRenderUpdate() override;
};

