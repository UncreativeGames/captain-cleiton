//
// Created by olivato on 23/05/18.
//

#include "../include/EnemyBat.hpp"
#include "../include/Animation.hpp"
#include "../include/AnimatedSprite.hpp"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <random>


using namespace std;
using namespace sf;

void EnemyBat::AI()
{
    unsigned char side;
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<>distr(0,100);
    side = distr(eng);
    if(side >= 75) {
        moveX(this->getPosition().x+1);
    }
    if(side >= 50 && side <75)
    {
        moveX(this->getPosition().x-1);
    }
    if(side>=25 && side <50) {
        moveY(this->getPosition().y-1);
    }
    if(side >=0 && side <25) {
        moveY(this->getPosition().y+1);
    }
}
void EnemyBat::loadFiles() {
    string file = "../../media/enemies/enemy_bat.png";
    if(!tx_spritesheet.loadFromFile(file))
    {
        cout << "File:" << file << " Not loaded" << endl;
    }

}

void EnemyBat::doDamage(int damage) {
    this->setLife(this->getLife()-damage);
    if(this->getLife()<=0)
        delete(this);
}

EnemyBat::EnemyBat(int x, int y, int life) : Monster(x, y, life) {
    loadFiles();
    loadAnimations();
}

void EnemyBat::loadAnimations() {
    this->setRaio(16);

    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(tx_spritesheet);
    walkingAnimationDown.addFrame(IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(IntRect( 0, 0, 32, 32));
    this->setWalkingAnimationDown(walkingAnimationDown);

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(tx_spritesheet);
    walkingAnimationLeft.addFrame(IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(IntRect( 0, 32, 32, 32));
    this->setWalkingAnimationLeft(walkingAnimationLeft);

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(tx_spritesheet);
    walkingAnimationRight.addFrame(IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(IntRect( 0, 64, 32, 32));
    this->setWalkingAnimationRight(walkingAnimationRight);

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(tx_spritesheet);
    walkingAnimationUp.addFrame(IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(IntRect( 0, 96, 32, 32));
    this->setWalkingAnimationUp(walkingAnimationUp);

}



