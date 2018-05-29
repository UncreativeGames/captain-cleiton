#include "../include/PlayerController.hpp"
#include <cmath>
#include <iostream>
#define RAD_to_DEG 180.0/3.141592

PlayerController::PlayerController(Player* player, sf::RenderWindow* window, 
	ColisionModule* colisoes, Gui* gui) : player(player), window(window), colisoes(colisoes), gui(gui)
{
	current_time = sf::seconds(0.0f);
}

void PlayerController::update(sf::Time deltatime)
{
	bool ja_hitou = false;
	Animation* currentAnimation = player->getWalkDown();
	sf::Vector2f movement(0,0);
	player->getWeapon()->update(deltatime);
	sf::Vector2f player_to_mouse = (player->getPosition() - sf::Vector2f(20,20))- (sf::Vector2f)sf::Mouse::getPosition(*window);
	sf::Vector2f eixo_x(1,0);
	float norma = (float)sqrt(player_to_mouse.x * player_to_mouse.x + player_to_mouse.y * player_to_mouse.y);
	float produto_interno = player_to_mouse.x; // eixo y é 0
	float angulo = 180 - RAD_to_DEG * acos(produto_interno / ((norma == 0) ? 1 : norma));
	if(player_to_mouse.y > 0)
		angulo = 360 - angulo;
	Lista<Lista<Rigidbody> >* retorno_request;	

	player->getWeapon()->setRotation(angulo);
	player->update(deltatime);

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.y -= speed;
		currentAnimation = player->getWalkUp();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.y += speed;
		currentAnimation = player->getWalkDown();
	}
	if(Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed;
		currentAnimation = player->getWalkLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		movement.x += speed;
		currentAnimation = player->getWalkRight();
	}
	
	norma = sqrt(movement.x*movement.x + movement.y*movement.y);
	movement = (movement/(norma ? norma : 1)) * speed;
	movement = movement * deltatime.asSeconds();
	retorno_request = colisoes->moveRequest(player, movement.x, movement.y);

	this->current_time += deltatime;
	
	for(int i = 0; i < retorno_request->atIndex(0)->length(); i++)
	{
		if(this->current_time > sf::seconds(2.0f) && !ja_hitou)
		{
			this->current_time = sf::seconds(0.0f);
			ja_hitou = true;
			retorno_request->atIndex(0)->atIndex(i)->onColision(player);
			gui->set_actual_life(player->getVida());
		}
	}



	player->play(*currentAnimation);
	if (movement.x == 0 && movement.y == 0)
	{
		player->stop();
	}
	for(int i = 0; i < retorno_request->atIndex(0)->length(); i++)
	{
		retorno_request->atIndex(0)->atIndex(i)->onColision(player);
	}
	retorno_request->removerAll();
	delete(retorno_request);
	player->getWeapon()->setPosition(player->getPosition());
	if(Mouse::isButtonPressed(Mouse::Left))
	{
		player->getWeapon()->atack();
	}
	player->update(deltatime);
}

