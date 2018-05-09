#include "../include/SquareObstacle.hpp"
#include "../include/Obstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cmath>

// Macro para distancia em função de Vector2f
#define norma(a) sqrt((a).x * (a).x + (a).y * (a).y)
#define modulo(a) ((a) > 0 ? (a) : (-a))

SquareObstacle::SquareObstacle(const sf::Texture& texture, const sf::IntRect& rectangle,
				 int tamanho_lado, int x, int y) : Obstacle(texture, rectangle, x, y)
{
	setNLados(4);
	setOrigin(tamanho_lado/2,tamanho_lado/2);
	setRaio(tamanho_lado/sqrt(2.f));
	
	this->tamanho_lado = tamanho_lado;
}

void SquareObstacle::setTamanhoLado(int a)
{
	this->tamanho_lado = a;
}

int SquareObstacle::getTamanhoLado()
{
	return tamanho_lado;
}

sf::Vector2f SquareObstacle::colision(Rigidbody* another)
{	
	sf::Vector2f another_position = another->getPosition();

	if ( another->getNLados() == 1 )
	{
		// Caso esteja longe nem faz o resto das verificações
		if(norma(another_position - getPosition()) >= another->getRaio() + getRaio())
			return sf::Vector2f(0,0);

		sf::Vector2f vetor_posicao_relativa = another_position - getPosition();
		// se vetor_posicao_relativa.x > 0 ==> another está à direita do objeto
		// se vetor_posicao_relativa.x < 0 ==> another está à esquerda do objeto
		// se vetor_posicao_relativa.y > 0 ==> another está à abaixo do objeto
		// se vetor_posicao_relativa.y < 0 ==> another está à direita do objeto
		// se ambos == 0 então ferrou

		if (modulo(vetor_posicao_relativa.x) >= tamanho_lado/2.f + another->getRaio() ||
			modulo(vetor_posicao_relativa.y) >= tamanho_lado/2.f + another->getRaio() ||
			(modulo(vetor_posicao_relativa.x) >= tamanho_lado && 
				modulo(vetor_posicao_relativa.y) >= tamanho_lado && 
				norma(vetor_posicao_relativa - sf::Vector2f(tamanho_lado/2.f,tamanho_lado/2.f)) 
				>= another->getRaio()))
			return sf::Vector2f(0,0);

		if (modulo(vetor_posicao_relativa.x) >= tamanho_lado/2.f && 
			modulo(vetor_posicao_relativa.x) < tamanho_lado/2.f + another->getRaio() &&
			modulo(vetor_posicao_relativa.y) < tamanho_lado/2.f)
			return sf::Vector2f(1,0);

		if (modulo(vetor_posicao_relativa.y) >= tamanho_lado/2.f && 
			modulo(vetor_posicao_relativa.y) < tamanho_lado/2.f + another->getRaio() &&
			modulo(vetor_posicao_relativa.x) < tamanho_lado/2.f)
			return sf::Vector2f(0,1);
			
		if(modulo(vetor_posicao_relativa.x) > modulo(vetor_posicao_relativa.y))
			return sf::Vector2f(1,0);
		else if(modulo(vetor_posicao_relativa.x) < modulo(vetor_posicao_relativa.y))
			return sf::Vector2f(0,1);
		else
			return sf::Vector2f(1,1);
	}

	return sf::Vector2f(0,0);
}
