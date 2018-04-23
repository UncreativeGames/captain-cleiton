#include "Rigidbody.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <cmath>

Rigidbody::Rigidbody(){
}

Rigidbody::Rigidbody(int raio){
	this->raio = raio;
}

void Rigidbody::setRaio(int raio){
	this->raio = raio;
}

int Rigidbody::getRaio(){
	return this->raio;
}

sf::Vector2f Rigidbody::colision(Rigidbody* another){
	sf::Vector2f B = this->getPosition() - another->getPosition();
	float dist = sqrt(B.x*B.x + B.y*B.y);
	int radius_this = this->raio;
	int radius_A = another->getRaio();
	if(dist >= radius_A + radius_this){
		return sf::Vector2f(0,0);
	}
	else{
		return (B/dist)*(radius_this - dist + radius_A );
	}
}
