#include "../include/Obstacle.hpp"
#include "../include/Chao.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

Chao::Chao() : Obstacle()
{

}

Chao::Chao(const sf::Texture& texture, const sf::IntRect& rectangle, int x, int y) : Obstacle(texture,rectangle,x,y)
{
	// Manter Raio do chao == 0 para que a colisão não seja verificada
	setRaio(0);
}