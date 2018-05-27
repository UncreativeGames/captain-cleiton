#include "../include/Gun.hpp"
#include <cmath>

Gun::Gun(Time intervalo, const sf::Texture& texture,
	Lista<Projetil>* projeteis, int damage, const sf::Texture& textura_projetil, 
	const sf::IntRect& rectangle, int x, int y) : Obstacle(texture,rectangle,x,y), textura_projetil(textura_projetil)
{
	this->intervalo = intervalo;
	this->tempo_atual = sf::seconds(0.f);
	this->projeteis = projeteis;
	this->damage = damage;
	//this->textura_projetil = textura_projetil;
}

Time Gun::getIntervalo()
{
	return intervalo;
}

Time Gun::getTempoAtual()
{
	return tempo_atual;
}

int Gun::getDamage()
{
	return damage;
}

void Gun::setIntervalo(Time intervalo)
{
	this->intervalo = intervalo;
}

void Gun::setTempoAtual(Time tempo_atual)
{
	this->tempo_atual = tempo_atual;
}

void Gun::setDamage(int damage)
{
	this->damage = damage;
}

void Gun::update(Time deltaTime)
{
	this->tempo_atual += deltaTime;
}

void Gun::atack()
{
	if(tempo_atual >= intervalo)
	{
		tempo_atual = sf::microseconds(0/*tempo_atual.asMicroseconds() % intervalo.asMicroseconds()*/);
		float x = 24*cos(getRotation()*3.141592/180);
		float y = 24*sin(getRotation()*3.141592/180);
		projeteis->add(new Projetil(textura_projetil,PROJETIL_RECT,(int)(getPosition().x+x),(int)(getPosition().y+y),
			sf::Vector2f(x,y),(float)PROJETIL_SPEED, (int)damage));
	}
}
