//
// Created by olivato on 23/05/18.
//

#ifndef CAPTAIN_CLEITON_ENEMIESMODULE_HPP
#define CAPTAIN_CLEITON_ENEMIESMODULE_HPP


#include "Rigidbody.hpp"
#include "Listaestatica.hpp"
#include "Monster.hpp"

class EnemiesModule{

public:
    EnemiesModule(Listaestatica<Rigidbody> * monsters);
    void addMonster(Monster monster);
    void callAllAIs();

private:
    Listaestatica<Rigidbody> *monsters;
};


#endif //CAPTAIN_CLEITON_ENEMIESMODULE_HPP
