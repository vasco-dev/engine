#pragma once
#include "ControlledEntity.h"

class BulletEntity : public ControlledEntity 
{
	public:
		BulletEntity();
		~BulletEntity();

		void EntityStart() override;

		void EntityEventUpdate(SDL_Event* event) override;
		void EntityUpdate(/*float deltaTime*/) override;
		void EntityRenderUpdate() override;

	protected:


};