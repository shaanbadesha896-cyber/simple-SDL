#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_image.h"

class GameObject{
	public:
		GameObject(const char* texturesheet);
		~GameObject();

		SDL_Texture* ObjTexture; 
		void update(int& currentFrame, Uint64& lastFrame, int& totalFrames);
		void render(int currentFrame, int frameWidth, int frameHeight);
	private: 
		int xpos;
		int ypos;
		SDL_Rect srcRect, dstRect; 
		SDL_Renderer* renderer; 
};
