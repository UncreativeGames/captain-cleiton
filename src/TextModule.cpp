//
// Created by olivato on 26/05/18.
//

#include "../include/TextModule.hpp"
#include "../include/Config.hpp"

void TextModule::showText(string text) {
    this->text.setString(text);
    this->text.setPosition(this->player->getPosition().x-32,this->player->getPosition().y-48);
    this->color = Color(static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256));
    this->text.setOutlineColor(color);
    window->draw(this->text);
}


TextModule::TextModule(RenderWindow *window,AnimatedSprite * player) {
    this->window = window;
    this->player = player;
    loadFiles();
}

void TextModule::loadFiles() {
    if (!this->font.loadFromFile("../../resources/fipps.otf"))
    {
        cout << "Font indisponível";
    }
    this->text.setFont(font);
    this->color = Color(255, 0, 0);
    this->text.setOutlineThickness(2.0f);
    this->text.setCharacterSize(12);
    this->text.setOutlineColor(color);

}