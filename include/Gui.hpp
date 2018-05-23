//
// Created by olivato on 22/05/18.
//

#ifndef CAPTAIN_CLEITON_GUI_HPP
#define CAPTAIN_CLEITON_GUI_HPP

#include <SFML/Graphics.hpp>

class Gui {

private:
    int max_stamina;
    int max_life;
    int max_mana;
    int actual_stamina;
    int actual_life;
    int actual_mana;
    unsigned char transparency;
    sf::Texture tx_base_hud;
    sf::RenderTexture rt_gui;
    sf::RenderWindow* window;
    sf::Sprite spr_gui;
    void createGui();

public:
    Gui(int stamina, int life, int mana, sf::RenderWindow *window);
    void draw();
    void loadFiles();
    void set_actual_mana(int mana);
    void set_actual_stamina(int stamina);
    void set_actual_life(int life);
    void set_transparency(unsigned char transp);

};


#endif //CAPTAIN_CLEITON_GUI_HPP
