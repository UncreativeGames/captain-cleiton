#include "../include/Player.hpp"

Player::Player(sf::Time frameTime, bool paused, bool looped) : AnimatedSprite(frameTime,paused,looped)
{
	alive = true;
}

int Player::getVida()
{
	return vida;
}

int Player::getVidaMax()
{
	return vida_max;
}

int Player::getMana()
{
	return mana;
}

int Player::getManaMax()
{
	return mana_max;
}

int Player::getEstamina()
{
	return estamina;
}

int Player::getEstaminaMax()
{
	return estamina_max;
}

void Player::setVida(int vida)
{
	this->vida = vida;
}

void Player::setMana(int mana)
{
	this->mana = mana;
}

void Player::setEstamina(int estamina)
{
	this->estamina = estamina;
}

void Player::setVidaMax(int vida_max)
{
	this->vida_max = vida_max;
}

void Player::setManaMax(int mana_max)
{
	this->mana_max = mana_max;
}

void Player::setEstaminaMax(int estamina_max)
{
	this->estamina_max = estamina_max;
}

Gun* Player::getWeapon()
{
	return weapon;
}

void Player::setWeapon(Gun* weapon)
{
	this->weapon = weapon;
}

void Player::onDamageTaken(int damage)
{
	vida -= damage;
	if(vida <= 0)
		alive = false;
}

bool Player::isAlive()
{
	return alive;
}

void Player::setWalkUp(Animation* A)
{
	walkUp = A;
}

void Player::setWalkDown(Animation* A)
{
	walkDown = A;
}

void Player::setWalkLeft(Animation* A)
{
	walkLeft = A;
}

void Player::setWalkRight(Animation* A)
{
	walkRight = A;
}

Animation* Player::getWalkUp()
{
	return walkUp;
}

Animation* Player::getWalkDown()
{
	return walkDown;
}
	
Animation* Player::getWalkLeft()
{
	return walkLeft;
}

Animation* Player::getWalkRight()
{
	return walkRight;
}
