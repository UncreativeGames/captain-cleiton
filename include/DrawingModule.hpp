#ifndef DRAWINGMODULE_INCLUDE
#define DRAWINGMODULE_INCLUDE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Listaestatica.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"


class DrawingModule
{
public:
	// Construtor que seta os ponteiros desta classe
	DrawingModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* objects_on_floor, Lista<Rigidbody>* projeteis, sf::RenderWindow* window);
	// Destrutor padrão
	virtual ~DrawingModule() = default;

	void update();

private:
	Listaestatica<Rigidbody>* wall_and_floor;
	Listaestatica<Rigidbody>* objects_on_floor;
	Lista<Rigidbody>* projeteis;
	sf::RenderWindow* window;
};

#endif
