#ifndef CHAO_INCLUDE
#define CHAO_INCLUDE

#include "Obstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class Chao : public Obstacle
{
public:
	Chao();
	Chao(const sf::Texture& texture, const sf::IntRect& rectangle, int x = 0, int y = 0);
	~Chao() = default;
};

#endif
