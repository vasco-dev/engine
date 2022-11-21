#pragma once
#include "MainEngine.h"

class GameLoop
{
	GameLoop();

	public:
		inline static GameLoop* GetInstance() { return (_gameLoopInstance != nullptr) ? _gameLoopInstance : new GameLoop(); };
	
	public:
		void StartGameLoop();
		void RunGameLoop();


	private:
		static GameLoop* _gameLoopInstance;

};