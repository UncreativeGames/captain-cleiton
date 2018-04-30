#ifndef RIGIDBODY_INCLUDE
#define RIGIDBODY_INCLUDE

#include <SFML/System/Vector2.hpp>
#include "DrawTransform.hpp"

class Rigidbody : public DrawTransform
{
public:
	Rigidbody();
	Rigidbody(int raio);
	void setRaio(int raio);
	int getRaio();
	sf::Vector2f colision(Rigidbody* another);

private:
	int raio_colisao;
};

#endif
