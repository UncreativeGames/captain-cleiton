#ifndef PLAYERCONTROLLER_INCLUDE
#define PLAYERCONTROLLER_INCLUDE

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "ColisionModule.hpp"
#include "Lista.hpp"
#include "Rigidbody.hpp"
#include "Animation.hpp"
#include "Gui.hpp"

#define speed 150.f

class PlayerController
{
public:
	PlayerController(Player* player, sf::RenderWindow* window, ColisionModule* colisoes, Gui* gui);
	void update(sf::Time deltatime);

private:
	Player* player;
	sf::RenderWindow* window;
	ColisionModule* colisoes;
	Gui* gui;
	sf::Time current_time;
};

#endif
