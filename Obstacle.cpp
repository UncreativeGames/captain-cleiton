#include "Obstacle.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Rect.hpp>

Obstacle::Obstacle() : m_texture(NULL)
{
	m_textureRect = sf::IntRect();
}

Obstacle::Obstacle(const sf::Texture& texture, const sf::IntRect& rectangle, int x, int y){
	sf::IntRect rect;	

	this->m_texture = &texture;

	if(rectangle == sf::IntRect()) {
		rect = sf::IntRect(0,0,texture.getSize().x,texture.getSize().y);
	}
	else {
		rect = rectangle;
	}

	m_textureRect = rect;

	m_vertices[0].position = sf::Vector2f(0.f, 0.f);
    m_vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    m_vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    m_vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);

    m_vertices[0].texCoords = sf::Vector2f(left, top);
    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
    m_vertices[2].texCoords = sf::Vector2f(right, bottom);
    m_vertices[3].texCoords = sf::Vector2f(right, top);

    this->setPosition(x,y);
    this->setRaio(0);
}

void Obstacle::setTexture(const sf::Texture& textura){
	this->m_texture = &textura;
	sf::IntRect rect = sf::IntRect(0,0,textura.getSize().x,textura.getSize().y);
	m_textureRect = rect;

	m_vertices[0].position = sf::Vector2f(0.f, 0.f);
    m_vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    m_vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    m_vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);

    m_vertices[0].texCoords = sf::Vector2f(left, top);
    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
    m_vertices[2].texCoords = sf::Vector2f(right, bottom);
    m_vertices[3].texCoords = sf::Vector2f(right, top);
}

const sf::Texture* Obstacle::getTexture() const
{
	return m_texture;
}

void Obstacle::setTextureRect(const sf::IntRect& rect){
	m_textureRect = rect;

	m_vertices[0].position = sf::Vector2f(0.f, 0.f);
    m_vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
    m_vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
    m_vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

    float left = static_cast<float>(rect.left) + 0.0001f;
    float right = left + static_cast<float>(rect.width);
    float top = static_cast<float>(rect.top);
    float bottom = top + static_cast<float>(rect.height);

    m_vertices[0].texCoords = sf::Vector2f(left, top);
    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
    m_vertices[2].texCoords = sf::Vector2f(right, bottom);
    m_vertices[3].texCoords = sf::Vector2f(right, top);
}

const sf::IntRect& Obstacle::getTextureRect() const
{
	return m_textureRect;
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_texture)
    {
        states.transform *= getTransform();
        states.texture = m_texture;
        target.draw(m_vertices, 4, sf::TriangleStrip, states);
    }
}
