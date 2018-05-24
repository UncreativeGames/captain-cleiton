//
// Created by olivato on 23/05/18.
//

#ifndef CAPTAIN_CLEITON_ENEMY_HPP
#define CAPTAIN_CLEITON_ENEMY_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../include/AnimatedSprite.hpp"
#include "Monster.hpp"

using namespace sf;

class EnemyBat : public Monster{
public:
    EnemyBat(int x, int y, int life);
    void doDamage(int damage);
    void AI();
    ~EnemyBat() override {
        delete bat;
    };

private:
    AnimatedSprite* bat;
    void loadFiles();
    void loadAnimations();
    Texture tx_spritesheet;

};


#endif //CAPTAIN_CLEITON_ENEMY_HPP
