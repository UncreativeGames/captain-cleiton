	#ifndef PROJETILMODULE_INCLUDE
#define	PROJETILMODULE_INCLUDE

#include "Projetil.hpp"
#include "ColisionModule.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class ProjetilModule
{
public:
	ProjetilModule(ColisionModule* modulo_colisao, Lista<Projetil>* projeteis, Rigidbody* player);

	void update(Time deltatime);

private:
	ColisionModule* modulo_colisao;
	Lista<Projetil>* projeteis;
	Rigidbody* player;
	
};

#endif
