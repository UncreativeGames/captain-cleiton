//
// Created by olivato on 19/04/18.
//

#include "Floor.h"
#include <cstdio>
#include <iostream>
#include <random>

using namespace std;
Floor::Floor(TileMap *inicio) {
    this->inicio = inicio;
    this->prox = NULL;

}
static bool checkUpNeighbor(TileMap * map)
{
    return map->getUp() != NULL;
}
static bool checkDownNeighbor(TileMap * map)
{
    return map->getDown() != NULL;
}
static bool checkRightNeighbor(TileMap * map)
{
    return map->getRight() != NULL;
}
static bool checkLeftNeighbor(TileMap * map)
{
    return map->getLeft() != NULL;
}

void Floor::generateFloor(int tam) {
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<>distr(0,100);
    bool isBossGenerated = false;
    bool isStoreGenerated = false;
    TileMap * atual = this->inicio;
    int chance = 50;
    while(tam<=0)
    {
        if(!checkDownNeighbor(atual->getDown()))
        {
            if(distr(eng) <= chance )
            {
                atual->setDown(new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
                tam--;
                atual->setDownDoor();
            }
        }
        if(!checkUpNeighbor(atual->getUp()))
        {
            if(distr(eng) <= chance )
            {
                atual->setUp(new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
                tam--;
                atual->setUpperDoor();
            }
        }
        if(!checkRightNeighbor(atual->getRight()))
        {
            if(distr(eng) <= chance )
            {
                atual->setRight(new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
                tam--;
                atual->setRightDoor();
            }
        }
        if(!checkLeftNeighbor(atual->getLeft())) {
            if (distr(eng) <= chance) {
                atual->setLeft(new TileMap(DEFAULT_SIZE_X, DEFAULT_SIZE_Y));
                atual->setLeftDoor();
                tam--;
            }
        }
        chance-=5;
    }

}
