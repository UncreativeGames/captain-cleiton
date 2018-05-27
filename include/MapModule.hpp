//
// Created by olivato on 07/05/18.
//

#ifndef MAPMODULE_HPP
#define MAPMODULE_HPP

#include <SFML/Graphics/Texture.hpp>
#include "Floor.hpp"
#include "Rigidbody.hpp"
#include "Listaestatica.hpp"
#include "Lista.hpp"
#include "Config.hpp"
#include "AnimatedSprite.hpp"
#include "EnemiesModule.hpp"
#include "TextModule.hpp"
#include "Projetil.hpp"

using namespace sf;

class MapModule {
public:
    MapModule(Listaestatica<Rigidbody> *wall_and_floor,
              Listaestatica<Rigidbody> *obstacles,
              AnimatedSprite *player,
              Listaestatica<Monster> *monsters,
              TextModule * textModule,
              Lista<Projetil> *projetil);
    void changeRoom(TileMap *m);
    void loadFiles();
    void changeDirection(char dir);
    void setDoorText(char dir);
    void checkRoom();
private:
    Floor * floor;
    Listaestatica<Rigidbody>* wall_and_floor;
    Listaestatica<Rigidbody>* obstacles;
    Listaestatica<Monster>* monsters;
    Lista<Projetil>* projetil;
    TextModule * textModule;
    AnimatedSprite* player;
    Texture tx_rock;
    Texture tx_floor;
    Texture tx_wall;

};

#endif // MAPMODULE_HPP
