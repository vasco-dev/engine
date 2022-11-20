#pragma once
#define SDL_MAIN_HANDLED
#include "Entity.h"
#include <iostream>
#include <sdl2/SDL.h>
#include <box2d/box2d.h>

class ControlledEntity : public Entity{
	public:
		ControlledEntity();
		~ControlledEntity();

		void EntityEventUpdate(SDL_Event* event) override; 
		void EntityStart() override;
		void EntityUpdate(/*float deltaTime*/) override; 
		void EntityRenderUpdate() override;

		float vel;

	protected:

		virtual bool Move(int x, int y, float speed);
		virtual bool Attack();

	private:

};