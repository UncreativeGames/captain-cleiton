//
// Created by olivato on 19/04/18.
//

#ifndef CAPTAIN_CLEITON_MAPA_H
#define CAPTAIN_CLEITON_MAPA_H


#define PAREDE 219
#define PEDRA 1
#define CHAO 'O'
#define DEBUG 0
#define DEBUG_SPEED 100*1000
#define PORTA_L 'L'
#define PORTA_R 'R'
#define PORTA_U 'U'
#define PORTA_D 'D'
#define MAP_CENTER 'C'

typedef char tile;
class TileMap {
public:

    TileMap(int x, int y);

    TileMap *getUp() const;

    void setUp(TileMap *up);

    TileMap *getDown() const;

    void setDown(TileMap *down);

    TileMap *getLeft() const;

    void setLeft(TileMap *left);

    TileMap *getRight() const;

    void setRight(TileMap *right);

    bool isCleared() const;

    void setCleared(bool cleared);

    bool isStore() const;

    void setStore(bool store);

    bool isBoss() const;

    void setBoss(bool boss);

    tile **getActual() const;

    void setActual(tile **actual);

    int getActual_size_x() const;

    void setActual_size_x(int actual_size_x);

    int getActual_size_y() const;

    void setActual_size_y(int actual_size_y);

    void generateRadialHunter(void);

    void printMap(void);

    void generateAlgorithmDrunkardWalk(void);

    void setLeftDoor(void);

    void setRightDoor(void);

    void setUpperDoor(void);

    void setDownDoor(void);
private:
    tile ** map;
    int size_x;
    int size_y;
    TileMap * up;
    TileMap * down;
    TileMap * left;
    TileMap * right;
    bool cleared;
    bool store;
    bool boss;

    tile **getGeneratedMap();

    int getSize_x() const;

    void setSize_x(int size_x);

    int getSize_y() const;

    void setSize_y(int size_y);


};


#endif //CAPTAIN_CLEITON_MAPA_H
