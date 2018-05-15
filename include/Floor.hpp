/*
 * Created by olivato on 19/04/18.
 * Read The Docs!
 */
#ifndef FLOOR_HPP
#define FLOOR_HPP


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
    TileMap *getMap_atual() const;

private:
    TileMap * map_atual;
    char floor_index;
    void generateFloor();
};


#endif //FLOOR_HPP
