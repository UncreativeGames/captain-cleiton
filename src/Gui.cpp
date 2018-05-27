//
// Created by olivato on 22/05/18.
//

#include "../include/Gui.hpp"
#include "../include/Config.hpp"
#include <iostream>
#define GUI_OFFSET_BAR_X 88
using namespace std;

void Gui::draw()
{
    this->window->draw(spr_gui);
}
void Gui::createGui()
{
    if(max_life > max_stamina && max_life > max_mana)
        rt_gui.create(80+max_life*8+42,90);
    if(max_stamina > max_life && max_stamina > max_mana)
        rt_gui.create(80+max_stamina*8+42,90);
    if(max_mana > max_stamina && max_mana > max_life)
        rt_gui.create(80+max_mana*8+42,90);
    int i =0;
    sf::Sprite spr_aux;
    spr_aux.setTexture(tx_base_hud);
    spr_aux.setTextureRect(sf::IntRect(443,174,90,80));
    rt_gui.draw(spr_aux);
    spr_aux.setTexture(tx_base_hud);
    spr_aux.setTextureRect(sf::IntRect(532,183,10,20));
    for(i =0 ;i<max_life;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,9);
        rt_gui.draw(spr_aux);
    }
    for(i =0 ;i<max_mana;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,29);
        rt_gui.draw(spr_aux);
    }
    for(i =0 ;i<max_stamina;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,49);
        rt_gui.draw(spr_aux);
    }
    spr_aux.setTextureRect(sf::IntRect(550,181,35,20));
    spr_aux.setPosition(GUI_OFFSET_BAR_X+max_life*8,7);
    rt_gui.draw(spr_aux);
    spr_aux.setTextureRect(sf::IntRect(551,202,35,20));
    spr_aux.setPosition(GUI_OFFSET_BAR_X+max_mana*8,28);
    rt_gui.draw(spr_aux);
    spr_aux.setTextureRect(sf::IntRect(550,222,35,20));
    spr_aux.setPosition(GUI_OFFSET_BAR_X+max_stamina*8,48);
    rt_gui.draw(spr_aux);
    rt_gui.display();
    spr_gui.setTexture(rt_gui.getTexture());
}


void Gui::loadFiles()
{
    string file = "gui/ui_big_pieces.png";
    if(!tx_base_hud.loadFromFile(file))
    {
        cout << "File:" << file << " Not loaded" << endl;
    }
    set_actual_life(max_life);
    set_actual_mana(max_mana);
    set_actual_stamina(max_stamina);
}

Gui::Gui(int stamina, int life, int mana,sf::RenderWindow *window)
{
    this->max_life = life;
    this->max_mana = mana;
    this->max_stamina = stamina;
    this->window = window;
    loadFiles();
}

void Gui::set_actual_mana(int mana) {
    createGui();
    if(mana> max_mana)
        mana = max_mana;
    sf::Sprite spr_aux;
    spr_aux.setTexture(tx_base_hud);
    spr_aux.setTextureRect(sf::IntRect(600,205,10,15));
    for(int i =0 ;i<mana;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,30);
        rt_gui.draw(spr_aux);
    }
}

void Gui::set_actual_stamina(int stamina) {
    createGui();
    if(stamina>max_stamina)
        stamina = max_stamina;
    sf::Sprite spr_aux;
    spr_aux.setTexture(tx_base_hud);
    spr_aux.setTextureRect(sf::IntRect(600,225,10,15));
    for(int i =0 ;i<stamina;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,50);
        rt_gui.draw(spr_aux);
    }
}

void Gui::set_actual_life(int life) {
    createGui();
    if(life>max_life)
        life = max_life;
    sf::Sprite spr_aux;
    spr_aux.setTexture(tx_base_hud);
    spr_aux.setTextureRect(sf::IntRect(600,185,12,15));
    for(int i =0 ;i<life;i++)
    {
        spr_aux.setPosition(GUI_OFFSET_BAR_X+i*8,10);
        rt_gui.draw(spr_aux);
    }
}

void Gui::set_transparency(unsigned char transp) {
    spr_gui.setColor(sf::Color(255,255,255,transp));
}
