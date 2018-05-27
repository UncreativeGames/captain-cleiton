#ifndef GUN_INCLUDE
#define GUN_INCLUDE

#include "Obstacle.hpp"
#include "Projetil.hpp"
#include "Config.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Gun : public Obstacle
{
public:
	Gun(Time intervalo, const sf::Texture& texture,
	Lista<Projetil>* projeteis, int damage, const sf::Texture& textura_projetil, 
	const sf::IntRect& rectangle = GUN_RECT, int x = 0, int y = 0);

	Time getIntervalo();
	Time getTempoAtual();
	int getDamage();
	void setIntervalo(Time intervalo);
	void setTempoAtual(Time tempo_atual);
	void setDamage(int damage);

	void update(Time deltaTime);
	void atack();

private:
	Time intervalo;
	Time tempo_atual;
	int damage;
	Lista<Projetil>* projeteis;
	const sf::Texture& textura_projetil;

};

#endif
