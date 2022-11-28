#include "MainEngine.h"
#include "Entity.h"
#include "PlayerControlledEntity.h"
#include "BackgroundEntity.h"




MainEngine* MainEngine::_engineInstance = nullptr;
SDL_Renderer* MainEngine::_currentRenderer = nullptr;
SDL_Window* MainEngine::_currentWindow = nullptr;
SDLWrapper* MainEngine::_currentWrapper = nullptr;

b2Vec2 MainEngine::_worldGravity = b2Vec2(0,-1);

b2World MainEngine::_worldInstance = b2World(_worldGravity);

b2DestructionListener* MainEngine::_destructionListener;

//static PlayerControlledEntity* playerEntity = nullptr;
//static BackgroundEntity* bgEntity = nullptr;

MainEngine::MainEngine() {
	_engineInstance = this;
	Init();
	
}

void MainEngine::AddEntityList(Entity* entityToAdd){
	if (entityToAdd == nullptr) {
		std::cout << "entity null " << std::endl;
		throw InitError();
		return;
	}
	_entityList.push_back(entityToAdd);



}
void MainEngine::RemoveEntityList(Entity* entityToAdd) {
	if (entityToAdd == nullptr) {
		std::cout << "entity null " << std::endl;
		throw InitError();
		return;
	}

	_entityList.remove(entityToAdd);
	_entityList.sort();

}

std::list<Entity*> MainEngine::GetEntityList() {
	return _entityList;
}

bool MainEngine::Init() {
	isRunning = true;
	_entityList = {};

	*_currentWrapper = SDLWrapper::SDLWrapper((SDL_INIT_VIDEO, SDL_INIT_EVENTS));	
		
	_currentWindow = SDL_CreateWindow("WAVE Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	if (_currentWindow == nullptr){		
		std::cout << "window init error" << std::endl;
		throw InitError();
	}

	_currentRenderer = SDL_CreateRenderer(_currentWindow, -1, SDL_RENDERER_ACCELERATED);
	if (_currentRenderer == nullptr){		
		std::cout << "renderer init error" << std::endl;
		throw InitError();
	}

	if (&_worldInstance == nullptr) {
		std::cout << "world instance init error" << std::endl;
		throw InitError();
	}

	SDL_Delay(16);
	
	
	std::cout << "...INIT..." << std::endl;


	return true;
}
void MainEngine::Start() {

	_worldInstance.SetDestructionListener(_destructionListener);

	std::cout << "...START..." << std::endl;

	for (Entity* entity : _entityList)
	{
		entity->EntityStart();
	}

}
void MainEngine::EventUpdate() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
				
		for (Entity* entity : _entityList)
		{
			if (entity == nullptr) {
				std::cout << "entity null " << std::endl;
				throw InitError();
				return;
			}
			entity->EntityEventUpdate(&event);
		}
	}
}

void MainEngine::Update() {

	_currentTicks = SDL_GetTicks() - _startTicks;
	_deltaTicks = _lastFrameTicks - _currentTicks;
	_lastFrameTicks = _currentTicks;

	for (Entity* entity : _entityList)
	{
		if (entity == nullptr) {
			std::cout << "entity null " << std::endl;
			throw InitError();
			return;
		}
		entity->EntityUpdate();
	}

	_worldInstance.Step(1/60.f, 8,3);


}
void MainEngine::RenderUpdate() {
	SDL_Delay(16.6f);	
	SDL_RenderClear(_currentRenderer);

	SDL_SetRenderDrawColor(_currentRenderer, 5, 5, 50, 255);	

		for (Entity* entity : _entityList)
	{
		entity->EntityRenderUpdate();
	}

	SDL_UpdateWindowSurface(_currentWindow);

	SDL_RenderPresent(_currentRenderer);

} 
void MainEngine::Quit(){
	if (Clear()) {
		MainEngine::isRunning = false;
	}
}

bool MainEngine::Clear() {


	SDL_DestroyRenderer(_currentRenderer);
	SDL_DestroyWindow(_currentWindow);

	std::cout << "cleared" << std::endl;

	SDL_Delay(1000);

	return true;
}

//int main(int argv, char** args) {
//	return 0;
//}
