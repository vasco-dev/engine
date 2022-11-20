#include "TextureHandler.h"
#include "MainEngine.h"

TextureHandler* TextureHandler::textureHandlerInstance = nullptr;

SDL_Texture* TextureHandler::LoadTexture(std::string file) {

	SDL_Renderer* windowRenderer = MainEngine::GetInstance()->GetRenderer();
	if(windowRenderer == nullptr) {
		std::cout << "null window renderer" << std::endl;
		throw InitError();
	}

	SDL_Surface* texSurface = SDL_LoadBMP(file.c_str());
	if (texSurface == nullptr) {
		std::cout << "null texture surface" << std::endl;
		throw InitError();
		return nullptr;
	}	

	SDL_SetColorKey(texSurface, SDL_TRUE, SDL_MapRGB(texSurface->format, 0xFF, 0, 0xFF));

	SDL_Texture* loadedTex = SDL_CreateTextureFromSurface(windowRenderer, texSurface);	
	
	if (loadedTex == nullptr) {
		std::cout << "null texture" << std::endl;
		throw InitError();
	}

	SDL_SetTextureBlendMode(loadedTex, SDL_BLENDMODE_BLEND);

	SDL_FreeSurface(texSurface);

	//std::cout << "tex: " << file << std::endl;a

	return loadedTex;
}
bool TextureHandler::Draw(SDL_Texture* texToDraw, SDL_Rect srcRect, SDL_FRect dstRect, bool isFullcreen) {

	SDL_Renderer* windowRenderer = MainEngine::GetInstance()->GetRenderer();
	if (windowRenderer == nullptr) {
		std::cout << "windowRenderer failed" << std::endl;
		throw InitError();
		return false;
	}
	
	if (isFullcreen) {
		SDL_Window* window = MainEngine::GetInstance()->GetWindow();
		
		SDL_Rect tempDst = {dstRect.x,dstRect.y,0,0};

		SDL_GetWindowSize(window, &tempDst.w, &tempDst.h);

		dstRect.w = 2 * tempDst.w;
		dstRect.h = 2 * tempDst.h;

	}

	int error = SDL_RenderCopyF(windowRenderer, texToDraw, &srcRect, &dstRect);



	if (&texToDraw == nullptr ||  &srcRect == nullptr || &dstRect == nullptr) {
		std::cout << "render failed" << std::endl;
		throw InitError();
		return false;
	}
	if (error != 0) {
		std::cout << "render failed" << std::endl;
		throw InitError();
		return false;
	}

	return true;
}
