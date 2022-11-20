#pragma once
#include "Entity.h"
#include "PlayerControlledEntity.h"

class BackgroundEntity : public Entity{

	public:
		BackgroundEntity();
		~BackgroundEntity();

		void EntityStart();
		void EntityEventUpdate(SDL_Event* event) override;
		void EntityUpdate(/*float deltaTime*/) override;
		void EntityRenderUpdate() override;

	private:
		float _scrollSpeed;
		PlayerControlledEntity* _playerEntity;

		int _maxWindowBorderX = 0;
		int _maxWindowBorderY = 0;
		int _maxWindowBorderTreshold = -1000;
		b2Vec2 _maxWindowBorderVec = { 0,0 };

};

