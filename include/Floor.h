//
// Created by olivato on 19/04/18.
//
/*
 * Funcionamento: Read The Docs!
 */
#ifndef CAPTAIN_CLEITON_ANDAR_H
#define CAPTAIN_CLEITON_ANDAR_H

#define DEFAULT_SIZE_X 13
#define DEFAULT_SIZE_Y 33
#include "TileMap.h"

class Floor {
public:
    Floor(TileMap * inicio);
    TileMap * inicio;
    Floor *prox;
    void generateFloor(int tam);
};


#endif //CAPTAIN_CLEITON_ANDAR_H
