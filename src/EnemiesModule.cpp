//
// Created by olivato on 23/05/18.
//

#include "../include/EnemiesModule.hpp"

void EnemiesModule::callAllAIs()
{
    for(int i =0;i<this->monsters->length();i++)
    {
        monster = this->monsters->atIndex(i);
        monster->AI();
        move->moveRequest(monster,monster->getSpeed_x(),monster->getSpeed_y());
        if(monster->getLife()<=0)
        {
            monsters->remover(0);
        }
    }
}

EnemiesModule::EnemiesModule(Clock *enemies, Listaestatica<Monster> *monsters, ColisionModule * move) {
    this->enemies_behaviour = enemies;
    this->monsters = monsters;
    this->move = move;
}
