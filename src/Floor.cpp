//
// Created by olivato on 19/04/18.
//

#include "../include/Floor.hpp"
#include <iostream>

using namespace std;

Floor::Floor() {
    Point p{0, 0};
    auto *m = new TileMap(DEFAULT_SIZE_X, DEFAULT_SIZE_Y, p);
    this->map_atual = m;
    this->floor_index = 1;
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
    unsigned char path[8]  = {0,0,1,1,2,2,3,0};
    unsigned char path_actual_position = 0;
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
                    new_map->setLeft(constructor);
                    constructor = constructor->getRight();
                    break;
                case 1:
                    constructor->setDown(new_map);
                    new_map->setUp(constructor);
                    constructor = constructor->getDown();
                    break;
                case 2:
                    constructor->setLeft(new_map);
                    new_map->setLeft(constructor);
                    constructor = constructor->getLeft();
                    break;
                case 3:
                    constructor->setUp(new_map);
                    new_map->setDown(constructor);
                    constructor = constructor->getUp();
                    break;
                default:break;
            }
            path_actual_position++;
        }
    }
}

void Floor::printSimpleFloor(){
    char path_size = 8;
    char unsigned path[8]  = {0,0,1,1,2,2,3,0};
    char unsigned path_actual_position = 0;
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
        cout << endl;
        path_actual_position++;
    }

}

char Floor::getFloor_index() const {
    return floor_index;
}

TileMap *Floor::getMap_atual() const {
    return map_atual;
}

Floor::~Floor() = default;

bool Floor::getMap_Left() {
    if(map_atual->getLeft()!= nullptr) {
        map_atual = map_atual->getLeft();
        return true;
    }
    return false;
}

bool Floor::getMap_Right() {
    if(map_atual->getRight()!= nullptr)
    {
        map_atual =  map_atual->getRight();
        return true;
    }
    return false;
}

bool Floor::getMap_Up() {
    if(map_atual->getUp()!=nullptr) {
        map_atual = map_atual->getUp();
        return true;
    }
    return false;
}

bool Floor::getMap_Down() {
    if(map_atual->getDown()!= nullptr)
    {
        map_atual = map_atual->getDown();
        return true;
    }
    return false;

}
