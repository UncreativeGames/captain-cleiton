#include "../include/ProjetilModule.hpp"

ProjetilModule::ProjetilModule(ColisionModule* modulo_colisao, Lista<Projetil>* projeteis, Rigidbody* player)
{
	this->modulo_colisao = modulo_colisao;
	this->projeteis = projeteis;
	this->player = player;
}

void ProjetilModule::update(Time deltatime)
{
	Lista<Lista<Rigidbody> >* colisoes;
	Projetil* auxiliar;
	sf::Vector2f direcao;
	sf::Vector2f player_position = player->getPosition();

	for (int i = 0; i < projeteis->length(); i++)
	{
		bool colidiu = false;
		auxiliar = projeteis->atIndex(i);
		direcao = auxiliar->getDirection();
		direcao *= auxiliar->getSpeed();
		direcao *= deltatime.asSeconds();
		colisoes = modulo_colisao->moveRequest(auxiliar,direcao.x,direcao.y);
		for(int j = 0; j < colisoes->atIndex(0)->length(); j++)
		{
			if(colisoes->atIndex(0)->atIndex(j)->getPosition() != player_position)
			{
				auxiliar->onColision(colisoes->atIndex(0)->atIndex(j));
				colidiu = true;
			}
		}
		for(int j = 0; j < colisoes->atIndex(1)->length(); j++)
		{
			auxiliar->onColision(colisoes->atIndex(1)->atIndex(j));
			colidiu = true;
		}
		if(colisoes->atIndex(2)->length() > 0)
			colidiu = true;
		if(colidiu)
		{
			colisoes->removerAll();
			delete(colisoes);
			projeteis->remover(i);
			i--;
		}
	}
}
