#pragma once
#include "ControlledEntity.h"

class FlyingEntity : public ControlledEntity {
	public:
		FlyingEntity();
		~FlyingEntity();

		void EntityStart();
		void EntityEventUpdate(SDL_Event* event) override;
		void EntityUpdate(/*float deltaTime*/) override;
		void EntityRenderUpdate() override;

};

