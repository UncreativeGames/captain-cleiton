#ifndef COLISIONMODULE_INCLUDE
#define COLISIONMODULE_INCLUDE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Listaestatica.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"
#include "Projetil.hpp"

class ColisionModule
{
public:
	ColisionModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* obstacles, Listaestatica<Rigidbody>* monsters, Rigidbody* player, Lista<Projetil>* projeteis);
	~ColisionModule() = default;

	// Retorna uma lista de listas de objetos que colidiram com object_that_requests na seguinte ordem:
	// Lista de player e monstros
	// Lista de projeteis
	// A classe que fez o request trata as colisões
	Lista<Lista<Rigidbody> >* moveRequest(Rigidbody* object_that_requests, float x, float y);

private:
	Listaestatica<Rigidbody>* wall_and_floor;
	Listaestatica<Rigidbody>* obstacles;
	Listaestatica<Rigidbody>* monsters;
	Rigidbody* player;
	Lista<Projetil>* projeteis;

	bool colisaoParede(Rigidbody* quem_colide, float x, float y, Lista<Lista<Rigidbody> >* oque_colidiu);
	bool colisaoObstaculos(Rigidbody* quem_colide, Lista<Lista<Rigidbody> >* oque_colidiu);
	bool colisaoMonstros(Rigidbody* quem_colide, Lista<Lista<Rigidbody> >* oque_colidiu);
	void colisaoPlayer(Rigidbody* quem_colide, Lista<Lista<Rigidbody> >* oque_colidiu);
};

#endif
