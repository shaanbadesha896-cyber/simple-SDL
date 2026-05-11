#include "map.h"
#include "texture_manager.h"
#include <fstream>
#include <sstream>

Map::Map(SDL_Renderer* ren){
    renderer = ren;
    tileTexture = TextureManager::LoadTexture("assets/PNG/pure_grass.png");
    loadMap("assets/map.csv");
}

void Map::loadMap(const char* filepath){
    std::ifstream file(filepath);
    std::string line;
    int row = 0;

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string val;
        int col = 0;
        while(std::getline(ss, val, ',')){
            mapData[row][col] = std::stoi(val);
            col++;
        }
        row++;
    }
}

void Map::DrawMap(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            SDL_Rect src = {mapData[i][j] * 32, 0, 32, 32};
            SDL_Rect dst = {j * 32, i * 32, 32, 32};
            SDL_RenderCopy(renderer, tileTexture, NULL, &dst);
        }
    }
}
