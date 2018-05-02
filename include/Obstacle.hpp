#ifndef OBSTACLE_INCLUDE
#define OBSTACLE_INCLUDE

#include "Rigidbody.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Rect.hpp>

class Obstacle : public Rigidbody
{
public: 
	Obstacle();
	Obstacle(const sf::Texture& texture, const sf::IntRect& rectangle = sf::IntRect(), int x = 0, int y = 0);
	void setTexture(const sf::Texture& textura);
	const sf::Texture* getTexture() const;
	void setTextureRect(const sf::IntRect& rect);
	const sf::IntRect& getTextureRect() const; 


private:
	sf::Vertex m_vertices[4];
	sf::IntRect m_textureRect;
	const sf::Texture* m_texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
};

#endif
