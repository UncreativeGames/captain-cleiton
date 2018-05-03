//
// Created by olivato on 19/04/18.
//
#include "../include/TileMap.hpp"
#include <iostream>
#include <random>

using namespace std;

TileMap::TileMap(int x,int y,Point index) {
    // Inicia uma sala vazia sem salas vizinhas
    this->up = nullptr;
    this->down = nullptr;
    this->right = nullptr;
    this->left = nullptr;
    this->size_x = x;
    this->size_y = y;
    this->index = index;
    // Cria um vetor de vetores (Matrix)
    auto **tab = new tile*[x];
    for (int i=0; i< x; ++i){
        tab[i] = new tile[y];
    };
    this->map = tab;
    //Cria uma sala vazia sem portas
    for(int i = 0;i<this->size_x;i++) {
        for (int j = 0; j < this->size_y; j++) {
            if (i == 0 || j == 0 || j == this->size_y-1 || i == this->size_x-1) {
                this->map[i][j] = static_cast<tile>(PAREDE);
            } else {
                this->map[i][j] = PEDRA;
            }
        }
    }

}

void TileMap::generateAlgorithmDrunkardWalk() {
    random_device rd;
    // Instanciação de um mersenne twister engine
    mt19937 eng(rd());
    // Distribuição entre 0 e 4
    uniform_int_distribution<>distr(0,4);
    int walk_y = 1;
    auto walk_x = this->size_x/2;
    this->map[walk_x][walk_y] = CHAO;
    // O "bêbado" do algorítmo anda da esquerda para a direita
    while(walk_x != (this->size_x / 2) || (walk_y != this->size_y - 2))
    {
        // Cria um PRNG baseado no range da distribuição
        switch (distr(eng))
        {
            // Norte
            case 0:
                walk_x--;
                if(walk_x-1<0)
                    walk_x++;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                // Sul
            case 1:
                walk_x++;
                if(walk_x==this->size_x-1)
                    walk_x--;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                // Leste
            case 2:
                walk_y++;
                if(walk_y>=this->size_y-1)
                    walk_y--;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;
                // Oeste
            case 3:
                walk_y--;
                if(walk_y-1<0)
                    walk_y++;
                else
                    this->map[walk_x][walk_y] = CHAO;
                break;

            default:break;
        }
    }
}
void TileMap::printMap(){
    // Printa o mapa, geralmente usado apenas para DEBUG
    for(int i = 0;i<this->size_x;i++)
    {
        for(int j = 0;j<this->size_y;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void TileMap::generateRadialHunter() {
    // Gera números aleatórios
    random_device rd;
    mt19937 eng(rd());
    int quandrant_size = this->size_y/2 * this->size_x/2;
    uniform_int_distribution<>distr(0,quandrant_size);
    uniform_int_distribution<>distr_percentage(0,100);
    for(int i = 0;i<this->size_x;i++) {
        for (int j = 0; j < this->size_y; j++) {
            if (i == 0 || j == 0 || j == this->size_y-1 || i == this->size_x-1) {
                this->map[i][j] = static_cast<tile>(PAREDE);
            } else {
                this->map[i][j] = static_cast<tile>(CHAO);
            }
        }
    }
    // Coloca objetos de um quadrante, espelhados em todos os outros
    for (int i = 1; i < this->size_x / 2; i++) {
        for (int j = 2; j < this->size_y / 2; j++) {
            if (distr(eng) >= 50) {
                this->map[i][j] = PEDRA;
                this->map[i][this->size_y - j] = PEDRA;
                this->map[this->size_x - i - 1][j] = PEDRA;
                this->map[this->size_x - i - 1][this->size_y - j] = PEDRA;
            }
        }
    }
}
//Funções que serão usadas futuramente
//no objeto 'mapa' na construção do andar
void TileMap::setLeftDoor() {
    this->map[this->size_x/2][0] = PORTA_L;
}

void TileMap::setRightDoor() {
    this->map[this->size_x/2][this->size_y-1] = PORTA_R;
}

void TileMap::setUpperDoor() {
    this->map[0][this->size_y/2] = PORTA_U;
}

void TileMap::setDownDoor() {
    this->map[this->size_x-1][this->size_y/2] = PORTA_D;
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

bool TileMap::isTreasureRoom() const {
    return this->treasure;
}

void TileMap::setTreasureRoom(bool treasure) {
    TileMap::treasure = treasure;
}

bool TileMap::isBoss() const {
    return boss;
}

void TileMap::setBoss(bool boss) {
    TileMap::boss = boss;
}

const Point &TileMap::getIndex() const {
    return index;
}

void TileMap::setIndex(const Point &index) {
    TileMap::index = index;
}

tile **TileMap::getMapMatrix() const {
    return this->map;
}
