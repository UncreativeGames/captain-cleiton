//
// Created by olivato on 24/05/18.
//

#ifndef CAPTAIN_CLEITON_MONSTER_HPP
#define CAPTAIN_CLEITON_MONSTER_HPP

#include <SFML/System/Thread.hpp>
#include <SFML/System/Clock.hpp>
#include "Obstacle.hpp"
#include "AnimatedSprite.hpp"

using namespace sf;
class Monster : public AnimatedSprite
{
public:

	Monster(sf::Time frameTime, bool paused , bool looped);
	int getLife() const;
	void setLife(int life);
	void moveX(int x);

    void setWalkingAnimationDown(const Animation &walkingAnimationDown);

	void setWalkingAnimationUp(const Animation &walkingAnimationUp);

	void setWalkingAnimationLeft(const Animation &walkingAnimationLeft);

	void setWalkingAnimationRight(const Animation &walkingAnimationRight);

	void setActual(Animation *actual);

	void setAnimation(unsigned char anim);

	Animation *getActual() const;

	virtual void AI()= 0;

    int getSpeed_x() const;

    void setSpeed_x(int speed_x);

    int getSpeed_y() const;

    void setSpeed_y(int speed_y);

private:
	int life;
	Animation walkingAnimationDown;
	Animation walkingAnimationUp;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
	Animation * actual;
    int speed_x = 0;
    int speed_y = 0;
    Clock * behaviour;

    void onColision(Rigidbody *another);

	void onDamageTaken(int dano_recebido);
};

#endif //CAPTAIN_CLEITON_MONSTER_HPP
