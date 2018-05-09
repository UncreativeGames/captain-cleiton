#include "../include/Wall.hpp"
#include "../include/Obstacle.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

Wall::Wall(const sf::Texture& texture, const sf::IntRect& rectangle, int tamanho_lado, int x, int y) : SquareObstacle( texture, rectangle, tamanho_lado, x, y){}
