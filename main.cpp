#include "TileMap.h"

int main() {

    TileMap * mapa = new TileMap(13, 33);
    TileMap * mapa1 = new TileMap(13, 33);
    mapa1->generateRadialHunter();
    mapa->setDown(mapa1);
    mapa->generateAlgorithmDrunkardWalk();
    mapa->printMap();
    mapa1->printMap();
    return 0;
}