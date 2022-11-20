#pragma once
#include "ControlledEntity.h"
#include "BulletEntity.h"
#include <vector>


class PlayerControlledEntity : public ControlledEntity
{
	public:
		PlayerControlledEntity();
		~PlayerControlledEntity();

		void EntityStart();
		void EntityEventUpdate(SDL_Event* event) override;
		void EntityUpdate(/*float deltaTime*/) override;
		void EntityRenderUpdate() override;

		void InputHandler(SDL_KeyboardEvent* keyEvent, bool isDown);

		bool Attack() override;

	protected:

		//int _currentTileY = 0;
	
	private:

		b2Vec2 _inputVec = {0,0};

		b2Vec2 _lastFramePos = {0,0};
		int _maxWindowBorderX = 0;
		int _maxWindowBorderY = 0;
		int _maxWindowBorderTreshold = -10;
		b2Vec2 _maxWindowBorderVec = { 0,0 };

		bool _holdMoveUp = false;
		bool _holdMoveDown = false;
		bool _holdMoveLeft = false;
		bool _holdMoveRight = false;

		b2Vec2 bulletOffset = { _tileWidth / 2 - 20, -30 };

		std::vector<BulletEntity*> _bulletList;

};

