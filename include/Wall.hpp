#ifndef WALL_INCLUDE
#define WALL_INCLUDE

#include "SquareObstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Lista.hpp"

class Wall : public SquareObstacle
{
public:
	Wall(const sf::Texture& texture, const sf::IntRect& rectangle, int tamanho_lado, int x = 0, int y = 0);
};

#endif
