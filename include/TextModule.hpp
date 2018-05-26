//
// Created by olivato on 26/05/18.
//
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Lista.hpp"
#include "AnimatedSprite.hpp"
#include <iostream>

#ifndef CAPTAIN_CLEITON_TEXTMODULE_HPP
#define CAPTAIN_CLEITON_TEXTMODULE_HPP

using namespace sf;
using namespace std;

class TextModule {

public:
    TextModule(RenderWindow * window, AnimatedSprite * player);
    void showText(string text);
    void showCenteredBigText(string text);

private:
    void loadFiles();
    RenderWindow * window;
    AnimatedSprite * player;
    Clock ck;
    Text text;
    Font font;
    Color color;
};


#endif //CAPTAIN_CLEITON_TEXTMODULE_HPP

