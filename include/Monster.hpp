//
// Created by olivato on 23/05/18.
//

#ifndef CAPTAIN_CLEITON_MONSTER_HPP
#define CAPTAIN_CLEITON_MONSTER_HPP

#include "AnimatedSprite.hpp"

class Monster : public AnimatedSprite{
public:
    Monster(int x, int y,int life);

    Monster(int x, int y, int life, const Animation &walkingAnimationUp, const Animation &walkingAnimationDown,
                const Animation &walkingAnimationLeft, const Animation &walkingAnimationRight);

    void moveX(int x);
    void moveY(int y);
    int getLife() const;
    void setLife(int life);

    const Animation &getWalkingAnimationUp() const;

    void setWalkingAnimationUp(const Animation &walkingAnimationUp);

    const Animation &getWalkingAnimationDown() const;

    void setWalkingAnimationDown(const Animation &walkingAnimationDown);

    const Animation &getWalkingAnimationLeft() const;

    void setWalkingAnimationLeft(const Animation &walkingAnimationLeft);

    const Animation &getWalkingAnimationRight() const;

    void setWalkingAnimationRight(const Animation &walkingAnimationRight);

    void AI();
private:
    Animation walkingAnimationUp;
    Animation walkingAnimationDown;
    Animation walkingAnimationLeft;
    Animation walkingAnimationRight;
    Animation* currentAnimation;
    int life;


};


#endif //CAPTAIN_CLEITON_MONSTER_HPP
