#include "../include/Rigidbody.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cmath>

Rigidbody::Rigidbody(){
	this->raio_colisao = 0;
}

Rigidbody::Rigidbody(int raio){
	this->raio_colisao = raio;
}

void Rigidbody::setRaio(int raio){
	this->raio_colisao = raio;
}

int Rigidbody::getRaio(){
	return this->raio_colisao;
}

sf::Vector2f Rigidbody::colision(Rigidbody* another){
	sf::Vector2f B = this->getPosition() - another->getPosition();
	float dist = sqrt(B.x*B.x + B.y*B.y);
	int radius_this = this->raio_colisao;
	int radius_A = another->getRaio();
	if(dist >= radius_A + radius_this){
		return sf::Vector2f(0,0);
	}
	else{
		return (B/dist)*(radius_this - dist + radius_A );
	}
}
