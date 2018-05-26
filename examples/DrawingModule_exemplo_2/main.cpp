#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/Audio.hpp>

#include "../../include/Animation.hpp"
#include "../../include/Monster.hpp"
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
#include "../../include/Gui.hpp"
#include "../../include/EnemyBat.hpp"
#include "../../include/TextModule.hpp"

#include <iostream>
#include <cmath>
#include <random>

#define speed 700.f
//dash_coold têm de ser maior do que dash_tempo
#define DASH_TEMPO sf::seconds(2.0)
#define DASH_COOLD sf::seconds(6.0)
using namespace std;

int main()
{

    sf::Music music;
    if (!music.openFromFile("../../media/Overworld.ogg"))
        return -1; // error
    music.play();
    srand(time(NULL));
    Lista<Rigidbody> projeteis;
    Lista<Lista<Rigidbody> >* Lista_para_deletar_retorno_modulo_colisao;
    Listaestatica<Rigidbody> walls_and_floor;
    Listaestatica<Rigidbody> obstacles;
    Listaestatica<Monster> monsters;
    // setup window
    Vector2i screenDimensions(DEFAULT_SIZE_X*32,DEFAULT_SIZE_Y*32);
    RenderWindow window(VideoMode(screenDimensions.x, screenDimensions.y), "Captain Cleiton.");
    window.setFramerateLimit(60);
    Clock shift;
    Clock enemies_behaviour;

    Texture personagem;
    if(!personagem.loadFromFile("../../media/Panda.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    Gui gui(0,3,0,&window);
    gui.set_actual_life(3);

    /* ----------- Player INICIO ------------*/
    Animation stop;
    stop.setSpriteSheet(personagem);
    stop.addFrame(IntRect(32, 0, 32, 32));
    stop.addFrame(IntRect(0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(personagem);
    walkingAnimationLeft.addFrame(IntRect(0, 96, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(32, 96, 32, 32));
    walkingAnimationLeft.addFrame(IntRect(64, 96, 32, 32));


    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(personagem);
    walkingAnimationRight.addFrame(IntRect(0, 96, 32, 32));
    walkingAnimationRight.addFrame(IntRect(32, 96, 32, 32));
    walkingAnimationRight.addFrame(IntRect(64, 96, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(personagem);
    walkingAnimationUp.addFrame(IntRect(0, 64, 32, 32));
    walkingAnimationUp.addFrame(IntRect(32, 64, 32, 32));
    walkingAnimationUp.addFrame(IntRect(64, 64, 32, 32));

    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(personagem);
    walkingAnimationDown.addFrame(IntRect(0, 32, 32, 32));
    walkingAnimationDown.addFrame(IntRect(32, 32, 32, 32));
    walkingAnimationDown.addFrame(IntRect(64, 32, 32, 32));
    Animation* currentAnimation = &walkingAnimationLeft;
    AnimatedSprite* dut = new AnimatedSprite(seconds(0.1), true, false);


    dut->setOrigin(16,24);
    dut->setPosition(Vector2f(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
    dut->setRaio(15);
    /* ----------- Player FIM ------------*/

    /* ----------- SHADER INICIO ----------*/
    if (!Shader::isAvailable())
    {
        cout << "Shader indisponível";
    }
    /* ----------- SHADER FIM ----------*/
    /* ----------- Inicio declaração de Módulos ------------*/
    ColisionModule colisor(&walls_and_floor,&obstacles,&monsters,dut,&projeteis);
    EnemiesModule enemiesModule(&enemies_behaviour,&monsters,&colisor);
    TextModule textModule(&window,dut);
    MapModule mapModule(&walls_and_floor,&obstacles,dut,&monsters,&textModule);
    DrawingModule designer(&walls_and_floor,&obstacles,&monsters,dut,&projeteis,&window);
    /* ----------- Fim declaração de Módulos ------------*/


    Clock frameClock;
    /* ----------- Inicio declaração de Cursor ------------*/
    Texture cursor_tex;
    if(!cursor_tex.loadFromFile("../../resources/cursor.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    Sprite cursor;
    cursor.setTexture(cursor_tex);
    cursor.setColor(Color::Red);
    window.setMouseCursorVisible(false);
    /* ----------- Fim declaração de Cursor ------------*/

    /* ----------- Checagem de portas inicio -----------*/

    IntRect upper_door_trigger ((DEFAULT_SIZE_X*32/2),32,32,32);
    IntRect down_door_trigger ((DEFAULT_SIZE_X*32/2),(DEFAULT_SIZE_Y*32)-64,32,32);
    IntRect left_door_trigger (64,(DEFAULT_SIZE_Y*32)/2,32,32);
    IntRect right_door_trigger ((DEFAULT_SIZE_X*32)-64,(DEFAULT_SIZE_Y*32)/2,32,32);
    IntRect Player (0, 0, 32, 32);

    /* ----------- Checagem de portas fim -----------*/

    bool sent = 0;
    while (window.isOpen())
    {
        mapModule.checkRoom();
        Player = IntRect(static_cast<int>(dut->getPosition().x), static_cast<int>(dut->getPosition().y), 32, 32);
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }
        Time frameTime = frameClock.restart();

        if(Keyboard::isKeyPressed(Keyboard::LShift) && sent == 0 && shift.getElapsedTime() >= DASH_COOLD)
        {
            sent = 1;
            shift.restart();
        }

        //Parar de dar dash
        if(shift.getElapsedTime() > DASH_TEMPO || !Keyboard::isKeyPressed(Keyboard::LShift))
        {
            sent = 0;
        }

        Vector2f movement(0.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            currentAnimation = &walkingAnimationDown;
            movement.y += speed;
        }
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            dut->setScale({ -1, 1 });
            if(sent)
            {
                //currentAnimation = &dashingAnimationLeft;
            }
            else
            {
                currentAnimation = &walkingAnimationLeft;
            }
            movement.x -= speed;
        } else{
            dut->setScale({ 1, 1 });
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {

            if(sent)
            {
                //currentAnimation = &dashingAnimationRight;
            }
            else
            {
                currentAnimation = &walkingAnimationLeft;
            }
            movement.x += speed;
        }
        float norma = sqrt(movement.x*movement.x + movement.y*movement.y);
        movement = (movement/(norma ? norma : 1)) * (sent ? 1.5f : 1) * speed;

        dut->play(*currentAnimation);
        enemiesModule.callAllAIs();
        movement = movement * frameTime.asSeconds();

        Lista_para_deletar_retorno_modulo_colisao = colisor.moveRequest(dut,movement.x,movement.y);

        // deleta todas as listas dentro desta lista sem deletar os itens delas
        Lista_para_deletar_retorno_modulo_colisao->removerAll();
        delete(Lista_para_deletar_retorno_modulo_colisao);

        // if no key was pressed stop the animation
        if (movement.x == 0 && movement.y == 0)
        {
            currentAnimation = &stop;
            dut->stop();
        }
        cursor.setPosition(Mouse::getPosition(window).x,Mouse::getPosition(window).y);
        // update Monster
        dut->update(frameTime);
        designer.update();
        window.draw(cursor);
        /* ----------- Checagem de portas inicio -----------*/
        if(Player.intersects(upper_door_trigger) || Player.intersects(down_door_trigger) || Player.intersects(right_door_trigger) || Player.intersects(left_door_trigger) )
        {

            if(Player.intersects(down_door_trigger))
                mapModule.setDoorText(PORTA_D);

            if(Player.intersects(upper_door_trigger))
                mapModule.setDoorText(PORTA_U);

            if(Player.intersects(right_door_trigger))
                mapModule.setDoorText(PORTA_R);

            if(Player.intersects(left_door_trigger))
                mapModule.setDoorText(PORTA_L);

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::E)
                {

                    if(Player.intersects(down_door_trigger))
                        mapModule.changeDirection(PORTA_R);

                    if(Player.intersects(upper_door_trigger))
                        mapModule.changeDirection(PORTA_L);

                    if(Player.intersects(right_door_trigger))
                        mapModule.changeDirection(PORTA_D);

                    if(Player.intersects(left_door_trigger))
                        mapModule.changeDirection(PORTA_U);

                }
            }

        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            cursor.setColor(Color::Blue);
        }
        else
        {
            cursor.setColor(Color::Red);
        }
        /* ----------- Checagem de portas FIM -----------*/

        gui.draw();
        window.display();
    }

    return 0;
}