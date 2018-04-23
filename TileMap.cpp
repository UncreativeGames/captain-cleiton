//
// Created by olivato on 19/04/18.
//
#include "TileMap.h"
#include <iostream>
#include <zconf.h>
#include <random>

using namespace std;

void TileMap::generateAlgorithmDrunkardWalk(void) {
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<>distr(0,4);
    int walk_y = 1;
    int walk_x = int(this->size_x/2);
    this->map[walk_x][walk_y] = CHAO;
    //From left to Right
    while(walk_x != int(this->size_x/2) || walk_y!=int(this->size_y-2))
    {
        switch (distr(eng))
        {
            //Norte
            case 0:
                walk_x--;
                if(walk_x-1<0)
                    walk_x++;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                //Sul
            case 1:
                walk_x++;
                if(walk_x==this->size_x-1)
                    walk_x--;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                //Leste
            case 2:
                walk_y++;
                if(walk_y>=this->size_y-1)
                    walk_y--;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                //Oeste
            case 3:
                walk_y--;
                if(walk_y-1<0)
                    walk_y++;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
        }
        if(DEBUG)
        {
            printMap();
            cout << endl << "size_y:" << size_y << endl;
            cout << endl << "size_x:" << size_x << endl;
            cout << endl << "[" << walk_x << "][" << walk_y << "]" << endl;
            usleep(DEBUG_SPEED);
            system("clear");
        }

    }
}
void TileMap::printMap(void){
    for(int i = 0;i<this->size_x;i++)
    {
        for(int j = 0;j<this->size_y;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void TileMap::generateRadialHunter(void) {
    //Define the inner matrix
    //Generate random objects
    random_device rd;
    mt19937 eng(rd());
    int quandrant_size = this->size_y/2 * this->size_x/2;
    if(DEBUG)
        cout << endl << "Quadrant Size:" << quandrant_size << endl;
    uniform_int_distribution<>distr(0,quandrant_size);
    uniform_int_distribution<>distr_percentage(0,100);
    quandrant_size = distr(eng);
    for(int i = 0;i<this->size_x;i++) {
        for (int j = 0; j < this->size_y; j++) {
            if (i == 0 || j == 0 || j == this->size_y-1 || i == this->size_x-1) {
                this->map[i][j] = PAREDE;
            } else {
                this->map[i][j] = CHAO;
            }
        }
    }
    //Put objects in the first quadrant
    for(int i = 1;i<this->size_x/2-1;i++)
    {
        for(int j = 2;j<this->size_y/2-1;j++)
        {
            if(distr(eng) >= 50)
            {
                this->map[i][j] = PEDRA;
                this->map[i][this->size_y-j] = PEDRA;
                this->map[this->size_x-i-1][j] = PEDRA;
                this->map[this->size_x-i-1][this->size_y-j] = PEDRA;
            }
        }
    }
}
//Funções que serão usadas futuramente
//no objeto 'mapa' na construção do andar
void TileMap::setLeftDoor(void) {
    this->map[int(this->size_x/2)][0] = PORTA_L;
}

void TileMap::setRightDoor(void) {
    this->map[int(this->size_x/2)][int(this->size_y-1)] = PORTA_R;
}

void TileMap::setUpperDoor(void) {
    this->map[0][int(this->size_y/2)] = PORTA_U;
}

void TileMap::setDownDoor(void) {
    this->map[int(this->size_x-1)][int(this->size_y/2)] = PORTA_D;
}

tile ** TileMap::getGeneratedMap() {
    return this->map;
}

int TileMap::getSize_x() const {
    return size_x;
}

void TileMap::setSize_x(int size_x) {
    TileMap::size_x = size_x;
}

int TileMap::getSize_y() const {
    return size_y;
}

void TileMap::setSize_y(int size_y) {
    TileMap::size_y = size_y;
}
TileMap *TileMap::getUp() const {
    return up;
}

void TileMap::setUp(TileMap *up) {
    TileMap::up = up;
}

TileMap *TileMap::getDown() const {
    return down;
}

void TileMap::setDown(TileMap *down) {
    TileMap::down = down;
}

TileMap *TileMap::getLeft() const {
    return left;
}

void TileMap::setLeft(TileMap *left) {
    TileMap::left = left;
}

TileMap *TileMap::getRight() const {
    return right;
}

void TileMap::setRight(TileMap *right) {
    TileMap::right = right;
}

bool TileMap::isCleared() const {
    return cleared;
}

void TileMap::setCleared(bool cleared) {
    TileMap::cleared = cleared;
}

bool TileMap::isStore() const {
    return store;
}

void TileMap::setStore(bool store) {
    TileMap::store = store;
}

bool TileMap::isBoss() const {
    return boss;
}

void TileMap::setBoss(bool boss) {
    TileMap::boss = boss;
}

TileMap::TileMap(int x,int y) {
    this->up = NULL;
    this->down = NULL;
    this->right = NULL;
    this->left = NULL;
    this->size_x = x;
    this->size_y = y;
    tile **tab = new tile*[x];
    for (int i=0; i< x; ++i){
        tab[i] = new tile[y];
    };
    this->map = tab;
    for(int i = 0;i<this->size_x;i++) {
        for (int j = 0; j < this->size_y; j++) {
            if (i == 0 || j == 0 || j == this->size_y-1 || i == this->size_x-1) {
                this->map[i][j] = PAREDE;
            } else {
                this->map[i][j] = PEDRA;
            }
        }
    }

}


