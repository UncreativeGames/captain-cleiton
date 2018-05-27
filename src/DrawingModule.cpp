#include "../include/DrawingModule.hpp"

DrawingModule::DrawingModule(Listaestatica<Rigidbody>* wall_and_floor, Listaestatica<Rigidbody>* obstacles, 
							Listaestatica<Rigidbody>* monsters, Player* player, Lista<Projetil>* projeteis, 
							sf::RenderWindow* window)
{
	this->wall_and_floor = wall_and_floor;
	this->obstacles = obstacles;
	this->monsters = monsters;
	this->player = player;
	this->projeteis = projeteis;
	this->window = window;
	
	// só precisa ordenar uma vez, pois obstaculos não se movem a priori
	obstacles->ordena();
}

// Complexidade total O(n log n + n + n + n²) = O(n log n + 2n + n²)  = O(n²)
// Sem considerar as funções de window pois a complexidade é desconhecida
void DrawingModule::update() {
	int i, j;
	bool player_is_printed = false;

	// wall_and_floor não precisa ser ordenado, uma vez que ele aparece 
	// abaixo de tudo e nao tem sobreposição
	
	// Ordena os elementos de obstacles
	// O(n log n)
	monsters->ordena();	
	obstacles->ordena();

	// Printa os elementos de wall_and_floor
	// O(n), pois O(n) * O(1)
	for (i = 0; i < wall_and_floor->length(); i++) 
	{
		window->draw(*wall_and_floor->atIndex(i) /*complexidade atIndex O(1)*/);
	}
	
	i = 0;
	j = 0;

	// Printa os elementos de obstacles
	// O(2n) = O(n)
	while (j < obstacles->length() || i < monsters->length())
	{
		if (j < obstacles->length() && i < monsters->length())
		{
			if (obstacles->atIndex(j)->getPosition().y < monsters->atIndex(i)->getPosition().y || (obstacles->atIndex(j)->getPosition().y == monsters->atIndex(i)->getPosition().y && obstacles->atIndex(j)->getPosition().x <= monsters->atIndex(i)->getPosition().x))
			{
				if(obstacles->atIndex(j)->getPosition().y < player->getPosition().y || (obstacles->atIndex(j)->getPosition().y == player->getPosition().y && obstacles->atIndex(j)->getPosition().x <= player->getPosition().x) || player_is_printed)
				{	
					window->draw(*obstacles->atIndex(j) /*complexidade atIndex O(1)*/);
					j++;
				}
				else
				{
					window->draw(*player);
					window->draw(*player->getWeapon());
					player_is_printed = true;	
				}
			}
			else
			{
				if(monsters->atIndex(i)->getPosition().y < player->getPosition().y || (monsters->atIndex(i)->getPosition().y == player->getPosition().y && monsters->atIndex(i)->getPosition().x <= player->getPosition().x) || player_is_printed)	
				{
					window->draw(*monsters->atIndex(i) /*complexidade atIndex O(1)*/);
					i++;
				}
				else
				{
					window->draw(*player);
					window->draw(*player->getWeapon());
					player_is_printed = true;
				}
			}
		}
		else //Se j >= obstacles->length ou i >= monsters->length()
		{
			if (j < obstacles->length())
			{
				if(obstacles->atIndex(j)->getPosition().y < player->getPosition().y || (obstacles->atIndex(j)->getPosition().y == player->getPosition().y && obstacles->atIndex(j)->getPosition().x <= player->getPosition().x) || player_is_printed)
				{	
					window->draw(*obstacles->atIndex(j) /*complexidade atIndex O(1)*/);
					j++;
				}
				else
				{
					window->draw(*player);
					window->draw(*player->getWeapon());
					player_is_printed = true;
				}
			}
			else
			{
				if(monsters->atIndex(i)->getPosition().y < player->getPosition().y || (monsters->atIndex(i)->getPosition().y == player->getPosition().y && monsters->atIndex(i)->getPosition().x <= player->getPosition().x) || player_is_printed)	
				{
					window->draw(*monsters->atIndex(i) /*complexidade atIndex O(1)*/);
					i++;
				}
				else
				{
					window->draw(*player);
					window->draw(*player->getWeapon());
					player_is_printed = true;
				}
			}
		}
	}
	if (!player_is_printed)
	{
		window->draw(*player);
		window->draw(*player->getWeapon());
	}
	// Printa os possiveis projeteis que estejam no jogo
	// Esta é uma lista encadeada pois não temos um numero máximo de projeteis no mapa
	// O(n²), pois O(n) * O(n)
	for (i = 0; i < projeteis->length(); i++)
	{
		window->draw(*projeteis->atIndex(i) /*complexidade atIndex O(n) pois esta lista é encadeada*/);
	}

}
