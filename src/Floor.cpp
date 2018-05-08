//
// Created by olivato on 19/04/18.
//

#include "../include/Floor.hpp"
#include <iostream>

using namespace std;

Floor::Floor(){
    Point p {0,0};
    TileMap * m = new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y,p);
    this->map_atual = m;
    this->floor_index = 1;
}
static bool checkUpNeighbor(TileMap * map)
{
    return map->getUp() != nullptr;
}
static bool checkDownNeighbor(TileMap * map)
{
    return map->getDown() != nullptr;
}
static bool checkRightNeighbor(TileMap * map)
{
    return map->getRight() != nullptr;
}
static bool checkLeftNeighbor(TileMap * map)
{
    return map->getLeft() != nullptr;
}

void Floor::generateFloor(){
}

// Generate fixed floor, for testing purposes only
void Floor::generateSimpleFloor()
{
    // Dynamic map generation
    TileMap * new_map;
    TileMap * constructor = this->map_atual;
    // Instruction path
    // 0 = Right,
    // 1 = Down,
    // 2=Left,
    // 3=Up
    // Hardcoded path
    char path[8]  = {0,0,1,1,2,2,3,0};
    char path_actual_position = 0;
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            Point p{i,j};
            new_map = new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y,p);
            new_map->generateRadialHunter();
            switch(path[path_actual_position])
            {
                case 0:
                    constructor->setRight(new_map);
                    constructor->setRightDoor();
                    constructor = constructor->getRight();
                    constructor->setLeftDoor();
                    break;
                case 1:
                    constructor->setDown(new_map);
                    constructor->setDownDoor();
                    constructor = constructor->getDown();
                    constructor->setUpperDoor();
                    break;
                case 2:
                    constructor->setLeft(new_map);
                    constructor->setLeftDoor();
                    constructor = constructor->getLeft();
                    constructor->setRightDoor();
                    break;
                case 3:
                    constructor->setUp(new_map);
                    constructor->setUpperDoor();
                    constructor = constructor->getUp();
                    constructor->setDownDoor();
                    break;
                default:break;
            }
            path_actual_position++;
        }
    }
}

void Floor::printSimpleFloor(){
    char path_size = 8;
    char path[8]  = {0,0,1,1,2,2,3,0};
    char path_actual_position = 0;
    TileMap * watcher = map_atual;
    watcher->printMap();
    while(path_actual_position!=path_size)
    {
            switch(path[path_actual_position])
            {
                case 0:
                    watcher = watcher->getRight();
                    break;
                case 1:
                    watcher = watcher->getDown();
                    break;
                case 2:
                    watcher = watcher->getLeft();
                    break;
                case 3:
                    watcher = watcher->getUp();
                    break;
                default:break;
            }
            watcher->printMap();
            path_actual_position++;
    }

}

char Floor::getFloor_index() const {
    return floor_index;
}

TileMap *Floor::getMap_atual() const {
    return map_atual;
}

Floor::~Floor() {

}
