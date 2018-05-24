//
// Created by olivato on 24/05/18.
//

#ifndef CAPTAIN_CLEITON_MONSTER_HPP
#define CAPTAIN_CLEITON_MONSTER_HPP

#include <SFML/System/Thread.hpp>
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
	void moveY(int y);
	void setWalkingAnimationDown(const Animation &walkingAnimationDown);

	void setWalkingAnimationUp(const Animation &walkingAnimationUp);

	void setWalkingAnimationLeft(const Animation &walkingAnimationLeft);

	void setWalkingAnimationRight(const Animation &walkingAnimationRight);

	void setActual(Animation *actual);

	Animation *getActual() const;
private:
	int life;
	Animation walkingAnimationDown;
	Animation walkingAnimationUp;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
	Animation * actual;

};



#endif //CAPTAIN_CLEITON_MONSTER_HPP
