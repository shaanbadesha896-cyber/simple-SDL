#include <SDL2/SDL_video.h>
#include <iostream>
#include "game_code.h"

int main(){
	Game game; 
	game.init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, true);
	while(game.running()){
	
		game.EventHandler();
		game.update();
		game.render();
	}

	game.clean();
	return 0;
}
