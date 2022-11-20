#pragma once
#define SDL_MAIN_HANDLED
#include <iostream>
#include <sdl2/SDL.h>
#include <box2d/box2d.h>

#include "TextureHandler.h"
#include "MainEngine.h"

class Entity
{
	public:
		Entity();
		~Entity();

		b2Body* _body;
		b2Vec2 startPos;
		b2Transform transform;

	public:
		bool CreateTexture();
		bool RenderTexture(bool autoSkipFrames, int frameToJumpX, int frameToJumpY, bool isFullscreen);
		bool FreeTexture();

		virtual void EntityStart();// will run once before the loop starts, used for setup
		virtual void EntityEventUpdate(SDL_Event*); // check for events before every update
		virtual void EntityUpdate(/*float deltaTime*/); // update
		virtual void EntityRenderUpdate(); // render everything after update


	protected:
		std::string  _bmpFile;

		SDL_Texture* _entityTexture;
		SDL_Rect _drawRect;		

		b2BodyDef _bodyDef;

		b2FixtureDef _fixDef;
		b2Fixture* _bodyFix;

		b2PolygonShape _bodyShape;
		b2BlockAllocator _BlockAlloc;

		int _tileWidth = 0;
		int _tileHeight = 0;

		int _tileMapCol = 0;
		int _tileMapRow = 0;

		int _currentTileX = 0;
		int _currentTileY = 0;

	protected:
		bool NextTileFrame();
		bool JumpToFrame(int frameToJumpX, int frameToJumpY);

};
