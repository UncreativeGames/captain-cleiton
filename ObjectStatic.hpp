#ifndef OBJECTSTATIC_INCLUDE
#define OBJECTSTATIC_INCLUDE

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>


//////////////////////////////////////////
// Quantos pixels deve mover por posição
#define PIXEL 1

/////////////////////////////////////////////////////////////////////////////
// Classe para objetos não-animados.
// Deve ser utilizada para objetos que não se movem e não tenham animações,
// como por exemplo pedras ou caixas espalhadas pelo mapa.
class ObjectStatic
{
public:

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// Construtor que seta o tamanho do corpo, seu ponto de referência que é levado em consideração
	// para mover (origem), sua textura, o tamanho de sua hitbox e a posição inicial.
	ObjectStatic(sf::Vector2f corpo, sf::Vector2f origem, sf::Texture& textura, int raio, int x, int y);

	//////////////////////////////////////////////////////////////////////////////////////
	// Seta a textura atual
	void setTexture(sf::Texture& textura);

	////////////////////////////////
	// Seta seu referencial
	void setOrigem(sf::Vector2f A);


	//////////////////////////////////////////////
	// Seta sua posição
	void setPosition(int x, int y);

	//////////////////////////////////////////////
	// Retorna o raio de sua hitBox
	int getRadiusHitBox();

	////////////////////////////////////////////////////////
	// Retorna um vetor com a posição atual do objeto
	sf::Vector2f getPosition();

	///////////////////////////////////////////////////
	// Retorna a textura sendo utilizada no objeto 
	const sf::Texture* getTexture();

	////////////////////////////////////////////////////////////////////////////////////////
	// Retorna um ponteiro para o corpo do objeto (Débito técnico para poder renderiza-lo)
	sf::RectangleShape* getCorpo();

	///////////////////////////////////////////////////////////////////////////////////
	// Colisão entre dois objetos, retorna um vetor com a menor distância e direção
	// para sair da colisão
	sf::Vector2f isColidindo(ObjectStatic* A);

private:
	//////////////////////////////////////
	// Atributo com a textura do objeto
	sf::Texture* textura;

	//////////////////////////////
	// Corpo visivel do objeto
	sf::RectangleShape* corpo;

	///////////////////////////////////////////////////
	// HitBox para colisões, não deve ser renderizada
	sf::CircleShape* hitBox;
};

#endif