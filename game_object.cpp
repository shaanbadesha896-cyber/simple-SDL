#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_image.h"
#include "game_object.h"
#include "texture_manager.h"

GameObject::GameObject(const char* texturesheet){
	renderer = ren; 
	ObjTexture = TextureManager::LoadTexture(texturesheet); 

}

void GameObject::update(int& currentFrame, Uint64& lastFrame, int& totalFrames){
	xpos = 0; 
	ypos = 0;

	Uint64 Current_Time = SDL_GetTicks64();
	if(Current_Time - lastFrame >= 75){
	currentFrame = (currentFrame + 1) % totalFrames;
	lastFrame = Current_Time;
        }
}

void GameObject::render(int currentFrame, int frameWidth, int frameHeight){
	SDL_Rect src = {currentFrame * frameWidth, 0, frameWidth, frameHeight};
        SDL_Rect dst = {xpos, ypos, 128, 128};
        SDL_RenderCopy(renderer, ObjTexture, &src, &dst);
}
