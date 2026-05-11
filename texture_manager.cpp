#include "texture_manager.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_image.h"

SDL_Texture* TextureManager :: LoadTexture(const char* texture){
	SDL_Surface* surface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	return tex; 
}
