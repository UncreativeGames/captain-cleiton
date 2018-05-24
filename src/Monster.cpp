//
// Created by olivato on 24/05/18.
//

#include "../include/Monster.hpp"

Monster::Monster(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true) : AnimatedSprite(frameTime,paused,looped){}

int Monster::getLife() const {
    return life;
}

void Monster::setLife(int life) {
    Monster::life = life;
}

void Monster::moveX(int x) {
    if(x>0)
        actual = &walkingAnimationRight;
    else
        actual = &walkingAnimationLeft;
    this->setPosition(x,this->getPosition().y);
}

void Monster::moveY(int y) {
    if(y>0)
        actual = &walkingAnimationDown;
    else
        actual = &walkingAnimationUp;
    this->setPosition(this->getPosition().x,y);
}

void Monster::setWalkingAnimationDown(const Animation &walkingAnimationDown) {
    Monster::walkingAnimationDown = walkingAnimationDown;
}

void Monster::setWalkingAnimationUp(const Animation &walkingAnimationUp) {
    Monster::walkingAnimationUp = walkingAnimationUp;
}

void Monster::setWalkingAnimationLeft(const Animation &walkingAnimationLeft) {
    Monster::walkingAnimationLeft = walkingAnimationLeft;
}

void Monster::setWalkingAnimationRight(const Animation &walkingAnimationRight) {
    Monster::walkingAnimationRight = walkingAnimationRight;
}

void Monster::setActual(Animation *actual) {
    Monster::actual = actual;
}

Animation *Monster::getActual() const {
    return actual;
}

