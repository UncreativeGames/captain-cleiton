#ifndef SQUAREOBSTACLE_INCLUDE
#define SQUAREOBSTACLE_INCLUDE

#include "Obstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Lista.hpp"

class SquareObstacle : public Obstacle
{
public:
	SquareObstacle(const sf::Texture& texture, const sf::IntRect& rectangle, int tamanho_lado, int x = 0, int y = 0);
	~SquareObstacle() = default;
	void setTamanhoLado(int a);
	int getTamanhoLado();
	virtual sf::Vector2f colision(Rigidbody* another);

private:
	int tamanho_lado;
};

#endif
