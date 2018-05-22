//
// Created by olivato on 22/05/18.
//

#include "../include/Gui.hpp"
#include "../include/Config.hpp"
#include <iostream>

using namespace std;

void Gui::Draw(){
    window->draw(spr_hud_status_container);
}

void Gui::loadFiles()
{
    // Palavras usadas nos arquivos
    /* ---- Início do carregamento dos arquivos ---- */
    // Pega o nome do arquivo a ser usado
    string base_path_name = "../../gui/ui_big_pieces.png";
    // Mantenha assim caso seja necessária alguma alteração futura
    string file = base_path_name;
    if(!tx_base_life_hud.loadFromFile(file))
    {
        cout << "File:" << file << " Not loaded" << endl;
    }
    spr_hud_status_container.setTexture(tx_base_life_hud);
    spr_hud_status_container.setTextureRect(sf::IntRect(443,174,89,77));
}

Gui::Gui(int stamina, int life, int mana, sf::RenderWindow *window) : stamina(stamina), life(life), mana(mana),
                                                                      window(window) {
    loadFiles();
}
