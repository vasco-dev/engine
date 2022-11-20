#pragma once
#include "sdl2/SDL.h"
#include <string>
#include <iostream>
#include <map>

#include "InitError.h"

class TextureHandler
{
	public:	
		inline static TextureHandler* GetInstance() { return (textureHandlerInstance != nullptr) ? textureHandlerInstance : new TextureHandler(); };

		SDL_Texture* LoadTexture(std::string file); // loads a texture
		
		bool Draw(SDL_Texture* texToDraw, SDL_Rect srcRect, SDL_FRect dstRect, bool isFullcreen); // draw a loaded texture from a given source and destination rect

	private:
		static TextureHandler* textureHandlerInstance;

		std::string _texFilePath;

		TextureHandler(){};

};

