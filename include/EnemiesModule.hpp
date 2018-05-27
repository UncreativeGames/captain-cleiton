//
// Created by olivato on 23/05/18.
//

#ifndef CAPTAIN_CLEITON_ENEMIESMODULE_HPP
#define CAPTAIN_CLEITON_ENEMIESMODULE_HPP


#include "EnemyBat.hpp"
#include "ColisionModule.hpp"

class EnemiesModule{

public:
    void callAllAIs();
    EnemiesModule(Clock * enemies, Listaestatica<Monster> * monsters, ColisionModule * move);

private:
    Clock *enemies_behaviour;
    Listaestatica<Monster> * monsters;
    ColisionModule * move;
    Monster * monster;
};


#endif //CAPTAIN_CLEITON_ENEMIESMODULE_HPP
