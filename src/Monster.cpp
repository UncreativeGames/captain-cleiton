//
// Created by olivato on 24/05/18.
//

#include "../include/Monster.hpp"

Monster::Monster(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true) : AnimatedSprite(frameTime,paused,looped){
    this->actual = &this->walkingAnimationDown;
}

int Monster::getLife() const {
    return life;
}

void Monster::setLife(int life) {
    Monster::life = life;
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

int Monster::getSpeed_x() const {
    return speed_x;
}

void Monster::setSpeed_x(int speed_x) {
    Monster::speed_x = speed_x;
}

int Monster::getSpeed_y() const {
    return speed_y;
}

void Monster::setSpeed_y(int speed_y) {
    Monster::speed_y = speed_y;
}

void Monster::setAnimation(unsigned char anim) {
    switch (anim)
    {
        case 0:
            this->setActual(&this->walkingAnimationRight);
            break;
        case 1:
            this->setActual(&this->walkingAnimationLeft);
            break;
        case 2:
            this->setActual(&this->walkingAnimationUp);
            break;
        case 3:
            this->setActual(&this->walkingAnimationDown);
            break;
        default:
            this->setActual(&this->walkingAnimationDown);
            break;

    }
}

void Monster::onColision(Rigidbody* another)
{
    another->onDamageTaken(1);
}

void Monster::onDamageTaken(int dano_recebido)
{
    this->setLife(this->getLife()-dano_recebido);
}


