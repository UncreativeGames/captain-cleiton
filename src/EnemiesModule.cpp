//
// Created by olivato on 23/05/18.
//

#include "../include/EnemiesModule.hpp"
#include "../include/Lista.hpp"
#include "../include/Rigidbody.hpp"

void EnemiesModule::callAllAIs()
{
    for(int i =0;i<this->monsters->length();i++)
    {
        Lista<Lista<Rigidbody> >* retorno_request;
        monster = this->monsters->atIndex(i);
        monster->AI();
        retorno_request = move->moveRequest(monster,monster->getSpeed_x(),monster->getSpeed_y());

        retorno_request->removerAll();
        delete(retorno_request);

        if(monster->getLife()<=0)
        {
            monsters->remover(i);
            i--;
        }
    }
}

EnemiesModule::EnemiesModule(Clock *enemies, Listaestatica<Monster> *monsters, ColisionModule * move) {
    this->enemies_behaviour = enemies;
    this->monsters = monsters;
    this->move = move;
}
