#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#define ROWS 30
#define COLS 20

class Map {
public:
    Map(SDL_Renderer* ren);
    void loadMap(const char* filepath);
    void DrawMap();
private:
    SDL_Renderer* renderer;
    SDL_Texture* tileTexture;
    int mapData[ROWS][COLS];
}; 
