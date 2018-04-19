#include "ObjectStatic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

ObjectStatic::ObjectStatic(sf::Vector2f corpo, sf::Vector2f origem, sf::Texture& textura, int raio, int x, int y){
	this->corpo = new sf::RectangleShape(corpo);
	this->corpo->setOrigin(origem);
	this->textura = &textura;
	this->corpo->setTexture(this->textura);
	this->hitBox = new sf::CircleShape(raio);
	this->hitBox->setOrigin(raio, raio);
	this->hitBox->setPosition(x*PIXEL,y*PIXEL);
	this->corpo->setPosition(x*PIXEL,y*PIXEL);
}

void ObjectStatic::setTexture(sf::Texture& textura){
	this->textura = &textura;
}

void ObjectStatic::setOrigem(sf::Vector2f A){
	this->corpo->setOrigin(this->corpo->getPosition()+A);
}

void ObjectStatic::setPosition(int x, int y){
	this->corpo->setPosition(x*PIXEL,y*PIXEL);
	this->hitBox->setPosition(x*PIXEL,y*PIXEL);
}

int ObjectStatic::getRadiusHitBox(){
	return this->hitBox->getRadius();
}

sf::Vector2f ObjectStatic::getPosition(){
	return this->hitBox->getPosition();
}

sf::Texture* ObjectStatic::getTexture(){
	return this->textura;
}

sf::RectangleShape* ObjectStatic::getCorpo(){
	return this->corpo;
}

sf::Vector2f ObjectStatic::isColidindo(ObjectStatic* A){
	sf::Vector2f B = this->getPosition() - A->getPosition();
	float dist = sqrt(B.x*B.x + B.y*B.y);
	int radius_this = this->getRadiusHitBox();
	int radius_A = A->getRadiusHitBox();
	if(dist >= radius_A + radius_this){
		return sf::Vector2f(0,0);
	}
	else{
		return (B/dist)*(radius_this - dist + radius_A );
	}
}