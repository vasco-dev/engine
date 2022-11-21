#pragma once
#define SDL_MAIN_HANDLED
#include <iostream>
#include <box2d/box2d.h>
#include <box2d/b2_settings.h>
#include <sdl2/SDL.h>
#include <string>
#include "SDLWrapper.h"
#include "sdl2/SDL_events.h"
#include "sdl2/SDL_video.h"



#include <list>

class Entity;

#undef main


class MainEngine
{
	public:
		inline static MainEngine* GetInstance(){ return (_engineInstance != nullptr) ? _engineInstance : new MainEngine(); };

		inline SDL_Renderer* GetRenderer() { return _currentRenderer; }
		inline SDL_Window* GetWindow() { return _currentWindow; }
		inline b2World* GetWorld() { return &_worldInstance; }

		std::list<Entity*> GetEntityList();
		void AddEntityList(Entity* entityToAdd);
		void RemoveEntityList(Entity* entityToAdd);

		bool GetIsRunning() { return isRunning; };

		bool Init(); // Will initialize SDL and check for errors
	
		void Start();// will run once before the loop starts, used for setup
		
		void EventUpdate(); // check for events before every update
		
		void Update(/*float deltaTime*/); // update

		void RenderUpdate(); // render everything after update
			
		bool Clear(); // clear and destroy everything before quitting
		
		void Quit(); // quit if everything has been cleared

	private:
		static MainEngine* _engineInstance;

		static b2World _worldInstance;
		static b2DestructionListener* _destructionListener;
		static b2Vec2 _worldGravity;

		static SDLWrapper* _currentWrapper;
		static SDL_Window* _currentWindow;
		static SDL_Renderer* _currentRenderer;

		std::list <Entity*> _entityList;

		bool isRunning = true;

		int windowWidth = 800;
		int windowHeight = 600;

		int _startTicks = 0;
		int _deltaTicks = 0;
		int _lastFrameTicks = 0;
		int _currentTicks = 0;




	private:	
		MainEngine();
		~MainEngine();
};

