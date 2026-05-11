#pragma once 
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_image.h" 
#include "game_code.h"

class TextureManager{
public: 
	static SDL_Texture* LoadTexture(const char* texture); 

};
