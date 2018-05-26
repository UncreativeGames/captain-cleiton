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

class EnemyBat : public Monster {
public:
    EnemyBat(const Time &frameTime, bool paused, bool looped, int x, int y);
    void doDamage(int damage);
    void AI();
    void loadFiles();
    void loadAnimations();

private:
    Texture tx_spritesheet;
    Clock frameClock;
    Clock AIClock;
    int rodando_e_ganhando =0;
};


#endif //CAPTAIN_CLEITON_ENEMY_HPP
