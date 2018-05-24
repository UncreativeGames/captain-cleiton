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

bool ColisionModule::colisaoParede(Rigidbody* quem_colide, float x, float y)
{
	sf::Vector2f sentinela_de_retorno;
	sf::Vector2f recuo_pos_colision = sf::Vector2f(x/5,y/5);
	bool colidiu = false;

	for(int i = 0; i < wall_and_floor->length(); i++)
	{
		if(wall_and_floor->atIndex(i)->getRaio() != 0)
		{
			while(wall_and_floor->atIndex(i)->colision(quem_colide) != sf::Vector2f(0,0))
			{
				sentinela_de_retorno = wall_and_floor->atIndex(i)->colision(quem_colide);
				colidiu = true;
				if(sentinela_de_retorno.y == 1)
					{
						quem_colide->move(0,-recuo_pos_colision.y == 0 ? 0.2f : -recuo_pos_colision.y);
					}
				if(sentinela_de_retorno.x == 1)
					{
						quem_colide->move(-recuo_pos_colision.x == 0 ? 0.2f : -recuo_pos_colision.x,0);
					}
			}
		}
	}
	return colidiu;
}

bool ColisionModule::colisaoObstaculos(Rigidbody* quem_colide)
{
	sf::Vector2f armazena_retorno_da_colisao;
	bool colidiu = false;

	for(int i = 0; i < obstacles->length(); i++)
	{
		if((armazena_retorno_da_colisao = quem_colide->colision(obstacles->atIndex(i))) != sf::Vector2f(0,0))
			{
				quem_colide->move(armazena_retorno_da_colisao);
				if(colisaoParede(quem_colide,
					armazena_retorno_da_colisao.x, 
					armazena_retorno_da_colisao.y))
					colidiu = true;
			}
	}
	return colidiu;
}

bool ColisionModule::colisaoMonstros(Rigidbody* quem_colide, 
	Lista<Lista<Rigidbody> >* oque_colidiu)
{
	bool retorno = false;
	sf::Vector2f armazena_retorno_da_colisao;
	for(int i = 0; i < monsters->length(); i++)
		if(monsters->atIndex(i)->getPosition() != quem_colide->getPosition())
		{
			if((armazena_retorno_da_colisao = quem_colide->colision(monsters->atIndex(i))) != sf::Vector2f(0,0))
			{
				quem_colide->move(armazena_retorno_da_colisao);
				if(colisaoParede(quem_colide,
					armazena_retorno_da_colisao.x, 
					armazena_retorno_da_colisao.y))
					retorno = true;
				oque_colidiu->atIndex(0)->add(monsters->atIndex(i));
			}
		}
	return retorno;
}

void ColisionModule::colisaoPlayer(Rigidbody* quem_colide, 
	Lista<Lista<Rigidbody> >* oque_colidiu)
{
	sf::Vector2f armazena_retorno_da_colisao;
	if(player->getPosition() != quem_colide->getPosition())
	{
		if((armazena_retorno_da_colisao = quem_colide->colision(player)) != sf::Vector2f(0,0))
			oque_colidiu->atIndex(0)->add(player);

	}
}

Lista<Lista<Rigidbody> >* ColisionModule::moveRequest(Rigidbody* object_that_requests, float x, float y)
{
	Lista<Lista<Rigidbody> >* Lista_com_as_colisoes;
	Lista_com_as_colisoes = new Lista<Lista<Rigidbody> >();
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Monstros/Player
	Lista_com_as_colisoes->add(new Lista<Rigidbody>()); // Lista para Projeteis

	object_that_requests->move(x,y);

	colisaoParede(object_that_requests, x, y);
	colisaoObstaculos(object_that_requests);
	colisaoMonstros(object_that_requests, Lista_com_as_colisoes);
	colisaoPlayer(object_that_requests, Lista_com_as_colisoes);

	return Lista_com_as_colisoes;
}
