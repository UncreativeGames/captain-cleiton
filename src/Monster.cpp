//
// Created by olivato on 23/05/18.
//

#include "../include/Monster.hpp"

void Monster::moveX(int x)
{
    this->setPosition(x,this->getPosition().y);
    if(x>0)
    {
        this->currentAnimation = &this->walkingAnimationRight;
    }
    else
    {
        this->currentAnimation = &this->walkingAnimationLeft;
    }
}

void Monster::moveY(int y) {
    this->setPosition(this->getPosition().x,y);
    if(y>0)
    {
        this->currentAnimation = &this->walkingAnimationDown;
    }
    else
    {
        this->currentAnimation = &this->walkingAnimationUp;
    }
    this->play();
}

Monster::Monster(int x, int y, int life, const Animation &walkingAnimationUp, const Animation &walkingAnimationDown,
                 const Animation &walkingAnimationLeft, const Animation &walkingAnimationRight) {
    this->life = life;
    this->setPosition(x,y);
}

int Monster::getLife() const {
    return life;
}

void Monster::setLife(int life) {
    Monster::life = life;
}

Monster::Monster(int x, int y, int life) {
    this->life = life;
    this->setPosition(x,y);
}

const Animation &Monster::getWalkingAnimationUp() const {
    return walkingAnimationUp;
}

void Monster::setWalkingAnimationUp(const Animation &walkingAnimationUp) {
    Monster::walkingAnimationUp = walkingAnimationUp;
}

const Animation &Monster::getWalkingAnimationDown() const {
    return walkingAnimationDown;
}

void Monster::setWalkingAnimationDown(const Animation &walkingAnimationDown) {
    Monster::walkingAnimationDown = walkingAnimationDown;
}

const Animation &Monster::getWalkingAnimationLeft() const {
    return walkingAnimationLeft;
}

void Monster::setWalkingAnimationLeft(const Animation &walkingAnimationLeft) {
    Monster::walkingAnimationLeft = walkingAnimationLeft;
}

const Animation &Monster::getWalkingAnimationRight() const {
    return walkingAnimationRight;
}

void Monster::setWalkingAnimationRight(const Animation &walkingAnimationRight) {
    Monster::walkingAnimationRight = walkingAnimationRight;
}

void Monster::AI() {}
