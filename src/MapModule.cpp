//
// Created by olivato on 07/05/18.
//

#include "../include/MapModule.hpp"
#include "../include/Obstacle.hpp"
#include "../include/Config.hpp"
#include "../include/Chao.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace sf;


void MapModule::changeRoom(TileMap *m) {
    if(m==nullptr)
        return;
    // Limpa tudo se for trocar de mapa
    this->obstacles->limpar();
    this->wall_and_floor->limpar();
    this->monsters->limpar();
    srand(time(NULL));
    // Variacoes de chão
    int tx_floor_choice[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int randomIndex = rand() % 12;

    /* ---- Fim do carregamento dos arquivos ---- */
    // Obstáculo dinâmico
    Obstacle * obstacle;
    // Chão dinâmico
    Chao * chao;
    // Offset do mapa
    const char offset = 16;
    char sprite_cut_x = 0;
    char sprite_cut_y = 0;
    for(int i = 0;i<DEFAULT_SIZE_X;i++)
    {
        for(int j = 0;j<DEFAULT_SIZE_Y;j++) {
            randomIndex = rand() % 12;
            chao = new Chao(tx_floor,sf::IntRect(0,(32*tx_floor_choice[randomIndex]), 32, 32));
            chao->setOrigin(16,16);
            chao->setPosition(i*32+offset,j*32+offset);
            wall_and_floor->add(chao);
            if(m->getTile(i,j)==PEDRA)
            {
                randomIndex = rand() % 2;
                obstacle = new Obstacle(tx_rock,sf::IntRect(0, 32*randomIndex, 32, 32));
                obstacle->setRaio(16);
                obstacle->setOrigin(16,16);
                obstacle->setPosition(i*32+offset,j*32+offset);
                obstacles->add(obstacle);
            }
            if(m->getTile(i,j)==PAREDE || m->getTile(i,j) == PORTA_D || m->getTile(i,j) == PORTA_L || m->getTile(i,j) == PORTA_U || m->getTile(i,j) == PORTA_R )
            {
                if(i!=0 && j!=0)
                {
                    sprite_cut_x = 0;
                    sprite_cut_y = 0;
                }
                if(i==0 && j!=0)
                {
                    sprite_cut_x = 32;
                    sprite_cut_y = 0;
                }
                if(i==DEFAULT_SIZE_X-1 && j!=0)
                {
                    sprite_cut_x = 64;
                    sprite_cut_y = 0;
                }
                if(j==0 && i!=0)
                {
                    sprite_cut_x = 96;
                    sprite_cut_y = 0;
                }
                if(i==DEFAULT_SIZE_X-1 && j==0)
                {
                    sprite_cut_x = 96;
                    sprite_cut_y = 32;
                }
                if(i==0 && j == 0) {
                    sprite_cut_x = 64;
                    sprite_cut_y = 32;
                }
                if(i==0 && j == DEFAULT_SIZE_Y-1)
                {
                    sprite_cut_x = 0;
                    sprite_cut_y = 32;
                }
                if(i==DEFAULT_SIZE_X-1 && j == DEFAULT_SIZE_Y-1)
                {
                    sprite_cut_x = 32;
                    sprite_cut_y = 32;
                }
                if(m->getTile(i,j)==PORTA_R)
                {
                    sprite_cut_x = 0;
                    sprite_cut_y = 64;
                }
                if(m->getTile(i,j)==PORTA_D)
                {
                    sprite_cut_x = 64;
                    sprite_cut_y = 64;

                }
                if(m->getTile(i,j)==PORTA_L)
                {
                    sprite_cut_x = 96;
                    sprite_cut_y = 64;
                }
                if(m->getTile(i,j)==PORTA_U)
                {
                    sprite_cut_x = 32;
                    sprite_cut_y = 64;
                }
                obstacle = new Obstacle(tx_wall, sf::IntRect(sprite_cut_x,sprite_cut_y, 32, 32));
                obstacle->setRaio(16);
                obstacle->setOrigin(16,16);
                obstacle->setPosition(i*32+offset,j*32+offset);
                wall_and_floor->add(obstacle);
            }
        }
    }
}

void MapModule::loadFiles() {
    // Palavras usadas nos arquivos
    string ambient[4] = {"floor","wall","rock",".png"};
    /* ---- Início do carregamento dos arquivos ---- */
    // Pega o nome do arquivo a ser usado
    // 'a' ambiente
    string base_path_name = "../../media/a";
    // floor index = numero do ambient
    // Exemplo: 'a1'
    base_path_name+=to_string(this->floor->getFloor_index());
    string file = base_path_name+ambient[2]+ambient[3];
    if(!tx_rock.loadFromFile(file))
    {
        cout << "File:" << file << " Not loaded" << endl;
    }
    file = base_path_name+ambient[1]+ambient[3];
    if(!tx_wall.loadFromFile(file)){
        cout << "File:" << file << " Not loaded" << endl;
    }
    file = base_path_name+ambient[0]+ambient[3];
    if(!tx_floor.loadFromFile(file)){
        cout << "File:" << file << " Not loaded" << endl;
    }
}

MapModule::MapModule(Listaestatica<Rigidbody> *wall_and_floor, Listaestatica<Rigidbody> *obstacles,
                     AnimatedSprite *player, Listaestatica<Rigidbody> *monsters) {
    auto * f = new Floor();
    f->generateSimpleFloor();
    this->floor = f;
    this->wall_and_floor = wall_and_floor;
    this->obstacles = obstacles;
    this->player = player;
    this->monsters = monsters;
    loadFiles();
    changeRoom(floor->getMap_atual());
}

void MapModule::changeDirection(char dir) {
    switch (dir)
    {
        case PORTA_U:
            if(this->floor->getMap_Up())
            {
                player->setPosition((DEFAULT_SIZE_X*32)-64,(DEFAULT_SIZE_Y*32)/2);
                changeRoom(this->floor->getMap_atual());
            }
            break;
        case PORTA_D:
            if(this->floor->getMap_Down())
            {
                player->setPosition(64,(DEFAULT_SIZE_Y*32)/2);
                changeRoom(this->floor->getMap_atual());
            }
            break;
        case PORTA_R:
            if(this->floor->getMap_Right())
            {
                player->setPosition((DEFAULT_SIZE_X*32/2),32);
                changeRoom(this->floor->getMap_atual());
            }
            break;
        case PORTA_L:
            if(this->floor->getMap_Left())
            {
                player->setPosition((DEFAULT_SIZE_X*32/2),(DEFAULT_SIZE_Y*32)-64);
                changeRoom(this->floor->getMap_atual());
            }
            break;
        default:
            this->floor->getMap_atual();

    }

}

void MapModule::setDoorText(char dir) {

    switch (dir)
    {
        case PORTA_U:
            if(floor->hasMap(PORTA_U))

            break;
        case PORTA_D:

            break;
        case PORTA_R:

            break;
        case PORTA_L:

            break;
        default:
            break;

    }
}
