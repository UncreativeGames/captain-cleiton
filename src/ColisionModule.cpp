#include "../include/ColisionModule.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../include/Listaestatica.hpp"
#include "../include/Lista.hpp"
#include "../include/Rigidbody.hpp"

ColisionModule::ColisionModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* obstacles,
								Listaestatica<Rigidbody>* monsters, Rigidbody* player,
								Lista<Rigidbody>* projeteis)
{
	this->wall_and_floor = wall_and_floor;
	this->obstacles = obstacles;
	this->monsters = monsters;
	this->player = player;
	this->projeteis = projeteis;
}

Lista<Lista<Rigidbody> >* ColisionModule::moveRequest(Rigidbody* object_that_requests, float x, float y)
{
	Lista<Lista<Rigidbody> >* Lista_com_as_colisoes;
	int i = 0;
	bool isPlayer = object_that_requests->getPosition() == player->getPosition();
	sf::Vector2f sentinela_de_retorno;
	sf::Vector2f recuo_pos_colision = sf::Vector2f(x/5,y/5);
	object_that_requests->move(x,y);

	Lista_com_as_colisoes = new Lista<Lista<Rigidbody> >();
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Monstros/Player
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Projeteis


	while(i < wall_and_floor->length() || i < monsters->length() || i < obstacles->length() || i < projeteis->length())
	{
		if (i < wall_and_floor->length())
		{	
			if(wall_and_floor->atIndex(i)->getRaio() != 0)
			{
				while(wall_and_floor->atIndex(i)->colision(object_that_requests) != sf::Vector2f(0,0))
				{
					sentinela_de_retorno = wall_and_floor->atIndex(i)->colision(object_that_requests);
					if(sentinela_de_retorno.y == 1)
						{
							object_that_requests->move(0,-recuo_pos_colision.y == 0 ? 0.2f : -recuo_pos_colision.y);
						}
					if(sentinela_de_retorno.x == 1)
						{
							object_that_requests->move(-recuo_pos_colision.x == 0 ? 0.2f : -recuo_pos_colision.x,0);
						}
				}
			}
		}
		
		if (i < obstacles->length())
		{
			object_that_requests->move(object_that_requests->colision(obstacles->atIndex(i)));
		}
		
		if (i < monsters->length())
		{
			if(monsters->atIndex(i)->getPosition() != object_that_requests->getPosition())
			{
				object_that_requests->move(object_that_requests->colision(monsters->atIndex(i)));
				if(object_that_requests->colision(monsters->atIndex(i)) != sf::Vector2f(0,0))
					Lista_com_as_colisoes->atIndex(0)->add(monsters->atIndex(i));
			}
		}
		
		if (i < projeteis->length())
		{
			if(object_that_requests->colision(projeteis->atIndex(i)) != sf::Vector2f(0,0))
				Lista_com_as_colisoes->atIndex(1)->add(projeteis->atIndex(i));
		}

		i++;
	}

	if(!isPlayer)
	{
		if(object_that_requests->colision(player) != sf::Vector2f(0,0))
			Lista_com_as_colisoes->atIndex(0)->add(player);
	}

	return Lista_com_as_colisoes;
}
