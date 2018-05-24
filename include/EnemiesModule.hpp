//
// Created by olivato on 23/05/18.
//

#ifndef CAPTAIN_CLEITON_ENEMIESMODULE_HPP
#define CAPTAIN_CLEITON_ENEMIESMODULE_HPP


#include "Rigidbody.hpp"
#include "Lista.hpp"
#include "EnemyBat.hpp"
#include "ColisionModule.hpp"

class EnemiesModule{

public:
    void callAllAIs();
    void addMonster(EnemyBat * enemy);
    EnemiesModule(Clock * enemies);
    bool isEmpty();
    void clear();
private:
    Lista<EnemyBat> *monsters = new Lista<EnemyBat> ();
    Clock *enemies;
};


#endif //CAPTAIN_CLEITON_ENEMIESMODULE_HPP
