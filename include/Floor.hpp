/*
 * Created by olivato on 19/04/18.
 * Read The Docs!
 */
#ifndef FLOOR_H
#define FLOOR_H


#include "Config.hpp"
#include "TileMap.hpp"

class Floor {
public:
    Floor(TileMap *init, Floor *next);
    // void generateFloor(int tam);
    void generateSimpleFloor();
    void printSimpleFloor();
private:
    TileMap * map_atual;
    Floor * proximo_floor;
    void generateFloor();
};


#endif //FLOOR_H
