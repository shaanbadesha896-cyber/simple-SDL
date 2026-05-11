#include "game_code.h"
#include "texture_manager.h"
#include "game_object.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>


SDL_Texture* player_texture;
TextureManager manager;
GameObject* player; 

void Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen){
	int flags =0; 

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		IMG_Init(IMG_INIT_PNG);
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);


		renderer = SDL_CreateRenderer(window, -1, 0);
		IsRunning = true; 
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 139, 40, 93, 255);
		}
		player = new GameObject("assets/PNG/HMMWalkBare.png", renderer);
		int textureWidth, textureHeight;
		SDL_QueryTexture(player->ObjTexture, NULL, NULL, &textureWidth, &textureHeight);
		totalFrames = textureWidth / frameWidth;
	}
}

void Game::EventHandler(){
	SDL_Event event; 
	SDL_PollEvent(&event); 
	switch(event.type){
		case SDL_QUIT: {
			IsRunning = false;
			break;	       
		}
		default: { 
			break;	 
		} 
	
	}
}

void Game::update(){
	player->update(currentFrame, lastFrame, totalFrames);
	}


void Game::render(){
	SDL_RenderClear(renderer); 
	player->render(currentFrame, frameWidth, frameHeight);
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer); 
	SDL_Quit();
}
