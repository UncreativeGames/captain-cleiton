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
    srand(time(NULL));
    // Variacoes de chão
    int tx_floor_choice[4] = {0,1,2,3};
    int randomIndex = rand() % 4;
    // Limpa tudo
    //wall_and_floor->limpar();
    //player_and_monsters->limpar();
    /* ---- Fim do carregamento dos arquivos ---- */
    // Obstáculo dinâmico
    Obstacle * obstacle;
    // Chão dinâmico
    Chao * chao;
    // Offset do mapa
    const char offset = 16;;
    for(int i = 0;i<DEFAULT_SIZE_X;i++)
    {
        for(int j = 0;j<DEFAULT_SIZE_Y;j++) {
            if(m->getTile(i,j)==PEDRA)
            {
                obstacle = new Obstacle(tx_rock,sf::IntRect(0, 0, 32, 32));
                obstacle->setRaio(16);
                obstacle->setOrigin(16,16);
                obstacle->setPosition(i*32+offset,j*32+offset);
                obstacles->add(obstacle);
            }
            if(m->getTile(i,j)==PAREDE)
            {
                obstacle = new Obstacle(tx_wall,sf::IntRect(32, 32, 32, 32));
                obstacle->setRaio(16);
                obstacle->setOrigin(16,16);
                obstacle->setPosition(i*32+offset,j*32+offset);
                wall_and_floor->add(obstacle);
            }
            else
            {
                randomIndex = rand() % 4;
                chao = new Chao(tx_floor,sf::IntRect(0,(32*tx_floor_choice[randomIndex]), 32, 32));
                chao->setOrigin(16,16);
                chao->setPosition(i*32+offset,j*32+offset);
                wall_and_floor->add(chao);
            }
        }
    }
}

void MapModule::loadFiles() {
    // Palavras usadas nos arquivos
    string ambient[4] = {"floor","wall","rocks",".png"};
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
                     Rigidbody *player, Listaestatica<Rigidbody> *monsters) {
    auto * f = new Floor();
    f->generateSimpleFloor();
    this->floor = f;
    this->wall_and_floor = wall_and_floor;
    this->obstacles = obstacles;
    this->player = player;
    this->monsters = monsters;
    loadFiles();
    changeRoom(f->getMap_atual());
}



