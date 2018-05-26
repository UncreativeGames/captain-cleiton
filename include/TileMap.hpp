//
// Created by olivato on 19/04/18.
//

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Config.hpp"

typedef char tile;

//Struct usada para indexar o mapa atual
typedef struct{
    int x,y;
}Point;

class TileMap {
public:
    // Construtor do mapa, recebe o tamanho e o index
    TileMap(int x, int y, Point index);
    // Retorna o mapa acima/abaixo/à esquerda/à direita deste
    TileMap *getUp() const;
    TileMap *getDown() const;
    TileMap *getLeft() const;
    TileMap *getRight() const;

    // Adiciona o mapa acima/abaixo/à esquerda/à direitaacima/abaixo/à esquerda/à direita deste
    void setUp(TileMap *up);
    void setDown(TileMap *down);
    void setLeft(TileMap *left);
    void setRight(TileMap *right);

    // Retorna se o player já derrotou todos os monstros deste mapa
    bool isCleared() const;

    void setCleared(bool cleared);

    // Retorna se este mapa é uma sala do tesouro
    bool isTreasureRoom() const;

    void setTreasureRoom(bool store);

    // Retorna se este mapa é uma sala de um chefe
    bool isBoss() const;

    void setBoss(bool boss);

    // Retorn um tile específico
    tile getTile(int x,int y);

    // Printa a matriz do mapa
    void printMap();

    // Algoritmo gerador de mapa
    void generateRadialHunter();

    // Algoritmo gerador de mapa
    void generateAlgorithmDrunkardWalk();

    // Retorna o index do mapa
    const Point &getIndex() const;

    // Altera o index default do mapa
    void setIndex(const Point &index);

    // Destrutor virtual, assim podemos deletar objetos via ponteiro
    // Parâmetro default define o destrutor sem um comportamento especial
    // Não precisa ser diretamente implementado
    virtual ~TileMap() = default;

private:
    tile ** map;
    int size_x;
    int size_y;
    TileMap * up;
    TileMap * down;
    TileMap * left;
    TileMap * right;
    bool cleared = false;
    bool treasure = false;
    bool boss = false;
    Point index;
    void setLeftDoor();
    void setRightDoor();
    void setUpperDoor();
    void setDownDoor();
};

#endif //TILEMAP_H
