#ifndef DRAWINGMODULE_INCLUDE
#define DRAWINGMODULE_INCLUDE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Listaestatica.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"
#include "Monster.hpp"
#include "Projetil.hpp"
#include "Player.hpp"


class DrawingModule
{
public:
	// Construtor que seta os ponteiros desta classe
	DrawingModule(Listaestatica<Rigidbody>* wall_and_floor,
				  Listaestatica<Rigidbody>* obstacles,
				  Listaestatica<Monster>* monsters,
				  Player* player,
				  Lista<Projetil>* projeteis,
				  sf::RenderWindow* window);
	// Destrutor padrão
	~DrawingModule() = default;

	void update();

private:
	Listaestatica<Rigidbody>* wall_and_floor;
	Listaestatica<Rigidbody>* obstacles;
	Listaestatica<Monster>* monsters;
	Player* player;
	Lista<Projetil>* projeteis;
	sf::RenderWindow* window;
};

#endif
