#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../../include/Animation.hpp"
#include "../../include/AnimatedSprite.hpp"
#include "../../include/Obstacle.hpp"
#include "../../include/Rigidbody.hpp"
#include "../../include/Floor.hpp"
#include "../../include/Listaestatica.hpp"
#include "../../include/Lista.hpp"
#include "../../include/DrawingModule.hpp"
#include "../../include/TileMap.hpp"
#include "../../include/Chao.hpp"
#include "../../include/ColisionModule.hpp"
#include "../../include/MapModule.hpp"
#include <iostream>
#include <cmath>

#define speed 150.f
using namespace std;
int main()
{
    srand(time(NULL));
    Lista<Rigidbody> projeteis;
    Lista<Lista<Rigidbody> >* Lista_para_deletar_retorno_modulo_colisao;
    Listaestatica<Rigidbody> walls_and_floor;
    Listaestatica<Rigidbody> obstacles;
    Listaestatica<Rigidbody> monsters;
    // setup window
    sf::Vector2i screenDimensions(DEFAULT_SIZE_X*32,DEFAULT_SIZE_Y*32);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Captain Cleiton.");
    window.setFramerateLimit(60);

    sf::Texture personagem;
    if(!personagem.loadFromFile("../../media/player.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    /* ----------- Player INICIO ------------*/
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(personagem);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(personagem);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(personagem);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(personagem);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    Animation* currentAnimation = &walkingAnimationDown;
    // set up AnimatedSprite
    AnimatedSprite* dut = new AnimatedSprite(sf::seconds(0.2), true, false);
    dut->setOrigin(16,24);
    dut->setPosition(Vector2f(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
    dut->setRaio(10);
    /* ----------- Player FIM ------------*/
    /* ----------- SHADER INICIO ----------*/
    if (!sf::Shader::isAvailable())
    {
        cout << "Shader indisponível";
    }
    /* ----------- SHADER FIM ----------*/
    /* ----------- FONTS/TEXTO INICIO---------*/
    Font font;
    if (!font.loadFromFile("../../resources/fipps.otf"))
    {

        cout << "Font indisponível";
    }
    Text text;
    text.setFont(font);
    Color color(255, 0, 0);

    text.setOutlineThickness(2.0f);
    text.setCharacterSize(12);
    text.setString("Press E");
    /* ----------- FONTS/TEXTO FIM---------*/
    /* ----------- Inicio declaração de Módulos ------------*/
    MapModule mapModule(&walls_and_floor,&obstacles,dut,&monsters);
    DrawingModule designer(&walls_and_floor,&obstacles,&monsters,dut,&projeteis,&window);
    ColisionModule colisor(&walls_and_floor,&obstacles,&monsters,dut,&projeteis);
    /* ----------- Fim declaração de Módulos ------------*/

    sf::Clock frameClock;
    /* ----------- Inicio declaração de Cursor ------------*/
    sf::Texture cursor_tex;
    if(!cursor_tex.loadFromFile("../../resources/cursor.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    sf::Sprite cursor;
    cursor.setTexture(cursor_tex);
    cursor.setScale(0.5f,0.5f);
    window.setMouseCursorVisible(false);
    /* ----------- Fim declaração de Cursor ------------*/
    /* ----------- Checagem de portas inicio -----------*/

    IntRect upper_door_trigger ((DEFAULT_SIZE_X*32/2),32,32,32);
    IntRect down_door_trigger ((DEFAULT_SIZE_X*32/2),(DEFAULT_SIZE_Y*32)-64,32,32);
    IntRect left_door_trigger (64,(DEFAULT_SIZE_Y*32)/2,32,32);
    IntRect right_door_trigger ((DEFAULT_SIZE_X*32)-64,(DEFAULT_SIZE_Y*32)/2,32,32);
    IntRect Player (0, 0, 32, 32);

    /* ----------- Checagem de portas fim -----------*/
    while (window.isOpen())
    {
        Player = IntRect(dut->getPosition().x,dut->getPosition().y,32,32);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        sf::Time frameTime = frameClock.restart();
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            currentAnimation = &walkingAnimationDown;
            movement.y += speed;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            currentAnimation = &walkingAnimationLeft;
            movement.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            currentAnimation = &walkingAnimationRight;
            movement.x += speed;
        }
        float norma = sqrt(movement.x*movement.x + movement.y*movement.y);
        movement = (movement/(norma ? norma : 1)) * speed;

        dut->play(*currentAnimation);
        movement = movement * frameTime.asSeconds();

        Lista_para_deletar_retorno_modulo_colisao = colisor.moveRequest(dut,movement.x,movement.y);

        // deleta todas as listas dentro desta lista sem deletar os itens delas
        Lista_para_deletar_retorno_modulo_colisao->removerAll();
        delete(Lista_para_deletar_retorno_modulo_colisao);

        // if no key was pressed stop the animation
        if (movement.x == 0 && movement.y == 0)
        {
            dut->stop();
        }
        cursor.setPosition(Mouse::getPosition(window).x,Mouse::getPosition(window).y);
        // update AnimatedSprite
        dut->update(frameTime);
        designer.update();
        window.draw(cursor);
        /* ----------- Checagem de portas inicio -----------*/
        if(Player.intersects(upper_door_trigger) || Player.intersects(down_door_trigger) || Player.intersects(right_door_trigger) || Player.intersects(left_door_trigger) )
        {
            text.setPosition(dut->getPosition().x-32,dut->getPosition().y-48);
            color = Color(dut->getPosition().x,dut->getPosition().y,dut->getPosition().x+dut->getPosition().y);
            text.setOutlineColor(color);
            window.draw(text);
        }
        /* ----------- Checagem de portas FIM -----------*/
        window.display();
    }

    return 0;
}
