//
// Created by olivato on 22/05/18.
//

#ifndef CAPTAIN_CLEITON_GUI_HPP
#define CAPTAIN_CLEITON_GUI_HPP

#include <SFML/Graphics.hpp>

class Gui {

private:
    int stamina;
    int life;
    int mana;
    sf::Sprite spr_hud_status_container;
    sf::Sprite spr_hud_stamina;
    sf::Sprite spr_hud_life;
    sf::Sprite spr_hud_mana;
    sf::Sprite spr_hud_item;
    sf::Texture tx_base_life_hud;
public:
    Gui(int stamina, int life, int mana, sf::RenderWindow *window);

private:
    sf::RenderWindow* window;
public:
    Gui(int stamina, int life, int mana, const sf::Texture &item);
    void Draw();
    void loadFiles();
};


#endif //CAPTAIN_CLEITON_GUI_HPP
