#ifndef PROJETIL_INCLUDE
#define PROJETIL_INCLUDE

#include "Obstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Config.hpp"

using namespace sf;

class Projetil : public Obstacle
{
public:
	Projetil(const Texture& textura, const IntRect& rectangle = PROJETIL_RECT,
		int x = 0, int y = 0, Vector2f direction = Vector2f(0,0), float speed = PROJETIL_SPEED, int damage = 1);
	Vector2f getDirection();
	float getSpeed();
	int getDamage();
	void setDirection(Vector2f direction);
	void setDirection(float x, float y);
	void setSpeed(float speed);
	void setDamage(int damage);
	virtual void onColision(Rigidbody* another);

private:
	Vector2f direction;
	float speed;
	int damage;
	
};

#endif
