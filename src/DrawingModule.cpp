#include "../include/DrawingModule.hpp"

DrawingModule::DrawingModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* the_rest, Lista<Rigidbody>* projeteis, sf::RenderWindow* window){
	this->wall_and_floor = wall_and_floor;
	this->the_rest = the_rest;
	this->projeteis = projeteis;
	this->window = window;
}

DrawingModule::~DrawingModule() {

}

// Complexidade total O(log n + n + n + n²) = O(log n + 2n + n²)  = O(n²)
// Sem considerar as funções de window pois a complexidade é desconhecida
void DrawingModule::update() {
	int i;
	
	// wall_and_floor não precisa ser ordenado, uma vez que ele aparece 
	// abaixo de tudo e nao tem sobreposição
	
	// Ordena os elementos de the_rest
	// O(log n)
	the_rest->ordena();
	
	// Limpa a tela
	window->clear();
	
	// Printa os elementos de wall_and_floor
	// O(n), pois O(n) * O(1)
	for (i = 0; i < wall_and_floor->length(); i++) 
	{
		window->draw(*wall_and_floor->atIndex(i) /*complexidade atIndex O(1)*/);
	}
	
	// Printa os elementos de the_rest
	// O(n), pois O(n) * O(1)
	for (i = 0; i < the_rest->length(); i++)
	{
		window->draw(*the_rest->atIndex(i) /*complexidade atIndex O(1)*/);
	}
	
	// Printa os possiveis projeteis que estejam no jogo
	// Esta é uma lista encadeada pois não temos um numero máximo de projeteis no mapa
	// O(n²), pois O(n) * O(n)
	for (i = 0; i < projeteis->length(); i++)
	{
		window->draw(*projeteis->atIndex(i) /*complexidade atIndex O(n) pois esta lista é encadeada*/);
	}
	
	window->display();

}