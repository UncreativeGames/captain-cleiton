#include "../include/ColisionModule.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../include/Listaestatica.hpp"
#include "../include/Lista.hpp"
#include "../include/Rigidbody.hpp"

ColisionModule::ColisionModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* obstacles, Listaestatica<Rigidbody>* player_and_monsters, Lista<Rigidbody>* projeteis)
{
	this->wall_and_floor = wall_and_floor;
	this->obstacles = obstacles;
	this->player_and_monsters = player_and_monsters;
	this->projeteis = projeteis;
}

Lista<Lista<Rigidbody> >* ColisionModule::moveRequest(Rigidbody* object_that_requests, float x, float y)
{
	Lista<Lista<Rigidbody> >* Lista_com_as_colisoes;
	int i = 0;
	object_that_requests->move(x,y);

	Lista_com_as_colisoes = new Lista<Lista<Rigidbody> >();
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Monstros/Player
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Projeteis


	while(i < wall_and_floor->length() || i < player_and_monsters->length() || i < obstacles->length() || i < projeteis->length())
	{
		if (i < wall_and_floor->length())
		{
			object_that_requests->move(object_that_requests->colision(wall_and_floor->atIndex(i)));
		}
		
		if (i < obstacles->length())
		{
			object_that_requests->move(object_that_requests->colision(obstacles->atIndex(i)));
		}
		
		if (i < player_and_monsters->length())
		{
			if(player_and_monsters->atIndex(i)->getPosition() != object_that_requests->getPosition())
			{
				object_that_requests->move(object_that_requests->colision(player_and_monsters->atIndex(i)));
				if(object_that_requests->colision(player_and_monsters->atIndex(i)) != sf::Vector2f(0,0))
					Lista_com_as_colisoes->atIndex(0)->add(player_and_monsters->atIndex(i));
			}
		}
		
		if (i < projeteis->length())
		{
			if(object_that_requests->colision(projeteis->atIndex(i)) != sf::Vector2f(0,0))
				Lista_com_as_colisoes->atIndex(1)->add(projeteis->atIndex(i));
		}

		i++;
	}

	return Lista_com_as_colisoes;
}
