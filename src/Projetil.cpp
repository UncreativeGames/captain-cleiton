#include "../include/Projetil.hpp"
#include <cmath>

Projetil::Projetil(const Texture& textura, const IntRect& rectangle,
		int x, int y, Vector2f direction, float speed, int damage) : Obstacle(textura, rectangle, x, y)
{
	this->speed = speed;
	this->direction = direction/(float)(sqrt(direction.x * direction.x + direction.y * direction.y));
	this->damage = damage;
	setOrigin(16,16);
	setRaio(8);
}

Vector2f Projetil::getDirection()
{
	return direction;
}

float Projetil::getSpeed()
{
	return speed;
}

int Projetil::getDamage()
{
	return damage;
}

void Projetil::setDirection(Vector2f direction)
{
	this->direction = direction/(float)(sqrt(direction.x * direction.x + direction.y * direction.y));
}

void Projetil::setDirection(float x, float y)
{
	this->direction = sf::Vector2f(x,y)/(float)(sqrt(direction.x * direction.x + direction.y * direction.y));
}

void Projetil::setSpeed(float speed)
{
	this->speed = speed;
}

void Projetil::setDamage(int damage)
{
	this->damage = damage;
}

void Projetil::onColision(Rigidbody* another)
{
	another->onDamageTaken(damage);
}
