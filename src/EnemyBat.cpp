//
// Created by olivato on 23/05/18.
//

#include "../include/EnemyBat.hpp"
#include "../include/Animation.hpp"
#include "../include/AnimatedSprite.hpp"
#include "../include/ColisionModule.hpp"
#include <iostream>
#include "../include/Config.hpp"
#include <SFML/System/Clock.hpp>
#include <random>


using namespace std;
using namespace sf;

void EnemyBat::AI()
{
    if((int)AIClock.getElapsedTime().asSeconds() % 2) {
        move = rand() % 4;
        AIClock.restart();
    }
    switch(move)
    {
        case 0:
            this->setSpeed_x(bat_speed);
            setAnimation(0);
            break;
        case 1:
            this->setSpeed_x(-bat_speed);
            setAnimation(1);
            break;
        case 2:
            this->setSpeed_y(bat_speed);
            setAnimation(3);
            break;
        case 3:
            setAnimation(2);
            this->setSpeed_y(-bat_speed);
            break;
        default:
            break;

    }
    this->play(*getActual());
    this->update(frameClock.restart());
}
void EnemyBat::loadFiles()
{
    string file = "media/enemies/enemy_bat.png";
    if(!tx_spritesheet.loadFromFile(file))
    {
        cout << "File:" << file << " Not loaded" << endl;
    }
    loadAnimations();
}

void EnemyBat::loadAnimations() {
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(tx_spritesheet);
    walkingAnimationDown.addFrame(IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(IntRect(96, 0, 32, 32));
    this->setWalkingAnimationDown(walkingAnimationDown);

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(tx_spritesheet);
    walkingAnimationLeft.addFrame(IntRect(32, 64, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(64, 64, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(96, 64, 32, 32));
    this->setWalkingAnimationLeft(walkingAnimationLeft);

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(tx_spritesheet);
    walkingAnimationRight.addFrame(IntRect(32, 32, 32, 32));
    walkingAnimationRight.addFrame(IntRect(64, 32, 32, 32));
    walkingAnimationRight.addFrame(IntRect(96, 32, 32, 32));
    this->setWalkingAnimationRight(walkingAnimationRight);

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(tx_spritesheet);
    walkingAnimationUp.addFrame(IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(IntRect(96, 96, 32, 32));
    this->setWalkingAnimationUp(walkingAnimationUp);

}
EnemyBat::EnemyBat(const Time &frameTime, bool paused, bool looped, int x, int y) : Monster(frameTime, paused, looped)
{
    this->setOrigin(16,16);
    float scale = rand() % 2 + 1;
    bat_speed = 1/scale +1;
    this->setColor(sf::Color(rand() % 256 +1,rand() % 256 +1,rand() % 256 +1));
    this->setScale(1*scale,1*scale);
    this->setRaio(15*scale);
    this->setPosition(x,y);
    loadFiles();
}





