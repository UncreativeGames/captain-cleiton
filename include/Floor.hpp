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
    void generateSimpleFloor();
    void printSimpleFloor();
    char getFloor_index() const;
    TileMap *getMap_atual() const;
    bool getMap_Left();
    bool getMap_Right();
    bool getMap_Up();
    bool getMap_Down();


private:
    TileMap * map_atual;
    char floor_index;
};


#endif //FLOOR_HPP
