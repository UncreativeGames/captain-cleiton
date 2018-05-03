//
// Created by olivato on 02/05/18.
//
#include "../../include/Floor.hpp"

int main(){
    Point p{0,0};
    auto * m = new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y,p);
    auto * f = new Floor(m, nullptr);
    f->generateSimpleFloor();
    f->printSimpleFloor();

}