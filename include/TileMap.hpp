//
// Created by olivato on 19/04/18.
//

#ifndef TILEMAP_H
#define TILEMAP_H

// Remover isto futuramente e adicionar em config.hpp
#define PAREDE 'P'
#define PEDRA 'F'
#define CHAO 'O'
#define DEBUG 0
#define DEBUG_SPEED (100*1000)
#define PORTA_L 'L'
#define PORTA_R 'R'
#define PORTA_U 'U'
#define PORTA_D 'D'
#define MAP_CENTER 'C'

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

    // Retorna a matrix que compõe o mapa
    tile **getMapMatrix() const;

    // Retorn um tile específico
    tile getTile(int x,int y);

    // Printa a matriz do mapa
    void printMap();

    // Algoritmo gerador de mapa
    void generateRadialHunter();

    // Algoritmo gerador de mapa
    void generateAlgorithmDrunkardWalk();

    void setLeftDoor();

    void setRightDoor();

    void setUpperDoor();

    void setDownDoor();

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
    bool cleared;
    bool treasure;
    bool boss;
    Point index;

};

#endif //TILEMAP_H
