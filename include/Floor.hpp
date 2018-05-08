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
    Floor();
    ~Floor();
    // void generateFloor(int tam);
    void generateSimpleFloor();
    void printSimpleFloor();
    char getFloor_index() const;

private:
    TileMap * map_atual;
public:
    TileMap *getMap_atual() const;

private:
    char floor_index;
    void generateFloor();
};


#endif //FLOOR_H
