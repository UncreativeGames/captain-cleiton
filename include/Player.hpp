#ifndef PLAYER_INCLUDE
#define PLAYER_INCLUDE

#include "AnimatedSprite.hpp"
#include "Gun.hpp"
#include "Animation.hpp"

using namespace sf;

class Player : public AnimatedSprite
{
public:
	Player(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);

	int getVida();
	int getVidaMax();
	int getMana();
	int getManaMax();
	int getEstamina();
	int getEstaminaMax();
	void setVida(int vida);
	void setMana(int mana);
	void setEstamina(int estamina);
	void setVidaMax(int vida_max);
	void setManaMax(int mana_max);
	void setEstaminaMax(int estamina_max);

	Gun* getWeapon();
	void setWeapon(Gun* weapon);

	virtual void onDamageTaken(int damage);

	bool isAlive();

	void setWalkUp(Animation* A);
	void setWalkDown(Animation* A);
	void setWalkLeft(Animation* A);
	void setWalkRight(Animation* A);

	Animation* getWalkUp();
	Animation* getWalkDown();
	Animation* getWalkLeft();
	Animation* getWalkRight();


private:
	Gun* weapon;
	int vida;
	int vida_max;
	int mana;
	int mana_max;
	int estamina;
	int estamina_max;
	bool alive;
	Animation* walkUp;
	Animation* walkDown;
	Animation* walkLeft;
	Animation* walkRight;
	
};

#endif
