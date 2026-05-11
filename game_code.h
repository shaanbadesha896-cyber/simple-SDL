#pragma once 
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "SDL2/SDL_image.h"

class Game {
	
public: 
	bool IsRunning;
	SDL_Window* window; 
	static SDL_Renderer* renderer;

	int frameWidth = 256;
	int frameHeight = 256;
	int totalFrames;
	int currentFrame =0; 
	int playerX = 100;
	int playerY = 100;
	Uint64 lastFrame = 0;
	const int fps = 60; 
	const int frame_delay = 1000/fps; 
	
	
	void init(const char* title, int xpos, int ypos, int width,int height, bool fullscreen);
	void EventHandler();
	void update();
	void render();
	void clean();

	bool running(){
	return IsRunning; 
	}
};
