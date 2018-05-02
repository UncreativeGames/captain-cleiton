/*
 * Created by olivato on 19/04/18.
 * Read The Docs!
 */
#ifndef FLOOR_H
#define FLOOR_H

#define DEFAULT_SIZE_X 13
#define DEFAULT_SIZE_Y 33

#include "TileMap.h"

class Floor {
public:
    Floor(TileMap *inicio, Floor *prox);
    TileMap * map_atual;
    Floor * proximo_floor;
    void generateFloor(int tam);
};


#endif //FLOOR_H
