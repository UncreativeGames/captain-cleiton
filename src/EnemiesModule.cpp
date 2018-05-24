//
// Created by olivato on 23/05/18.
//

#include "../include/EnemiesModule.hpp"

void EnemiesModule::callAllAIs()
{
    for(int i =0;i<this->monsters->length();i++)
    {
        this->monsters->atIndex(i)->AI(enemies);
    }
}

void EnemiesModule::addMonster(EnemyBat *enemy)
{
    this->monsters->add(enemy);
}

EnemiesModule::EnemiesModule(Clock *enemies) {
    this->enemies = enemies;
}

void EnemiesModule::clear() {
    this->monsters->removerAll();
}

bool EnemiesModule::isEmpty() {
    return this->monsters->length()==0;
}
