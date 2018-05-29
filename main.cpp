#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/Audio.hpp>

#include "include/Animation.hpp"
#include "include/Monster.hpp"
#include "include/Obstacle.hpp"
#include "include/Rigidbody.hpp"
#include "include/Floor.hpp"
#include "include/Listaestatica.hpp"
#include "include/Lista.hpp"
#include "include/DrawingModule.hpp"
#include "include/TileMap.hpp"
#include "include/Chao.hpp"
#include "include/ColisionModule.hpp"
#include "include/MapModule.hpp"
#include "include/Gui.hpp"
#include "include/EnemyBat.hpp"
#include "include/TextModule.hpp"
#include "include/Projetil.hpp"
#include "include/Player.hpp"
#include "include/PlayerController.hpp"
#include "include/Gun.hpp"
#include "include/ProjetilModule.hpp"
#include <iostream>
#include <cmath>
#include <random>

#define speed 150.f
//dash_coold têm de ser maior do que dash_tempo
#define DASH_TEMPO sf::seconds(2.0)
#define DASH_COOLD sf::seconds(6.0)
using namespace std;

int main()
{

    sf::Music music;
    if (!music.openFromFile("media/Overworld.ogg"))
        return -1; // error
    music.play();
    srand(time(NULL));
    Lista<Projetil> projeteis;
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
    if(!personagem.loadFromFile("media/Panda.png")){
        std::cout << "Deu Ruim" << std::endl;
    }

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
    Player* dut = new Player(seconds(0.2), true, false);
    dut->setOrigin(16,24);
    dut->setPosition(Vector2f(DEFAULT_SIZE_X,DEFAULT_SIZE_Y));
    dut->setRaio(15);
    dut->setVidaMax(3);
    dut->setVida(3);
    dut->setManaMax(0);
    dut->setMana(0);
    dut->setEstaminaMax(0);
    dut->setEstamina(0);
    Texture textura_arma;
    if(!textura_arma.loadFromFile("media/weapon1.png")){
        std::cout << "Deu Ruim" << std::endl;
    }

    Texture textura_projetil;
    if(!textura_projetil.loadFromFile("media/beams.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    Gun* arma = new Gun(seconds(0.2f),textura_arma, &projeteis, 2, textura_projetil, GUN_RECT,0,0);
    arma->setOrigin(8,16);
    arma->setPosition(dut->getPosition());

    dut->setWeapon(arma);
    dut->setWalkUp(&walkingAnimationUp);
    dut->setWalkDown(&walkingAnimationDown);
    dut->setWalkLeft(&walkingAnimationLeft);
    dut->setWalkRight(&walkingAnimationRight);

    Gui gui(0,3,0,&window);
    gui.set_actual_life(dut->getVida());
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
    MapModule mapModule(&walls_and_floor,&obstacles,dut,&monsters,&textModule,&projeteis);
    DrawingModule designer(&walls_and_floor,&obstacles,&monsters,dut,&projeteis,&window);
    ProjetilModule tiros(&colisor,&projeteis,dut);
    PlayerController controle(dut,&window,&colisor,&gui);
    /* ----------- Fim declaração de Módulos ------------*/


    Clock frameClock;
    /* ----------- Inicio declaração de Cursor ------------*/
    Texture cursor_tex;
    if(!cursor_tex.loadFromFile("resources/cursor.png")){
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
    while (window.isOpen() )
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
        cursor.setPosition(Mouse::getPosition(window).x,Mouse::getPosition(window).y);
        controle.update(frameTime);
        designer.update();
        tiros.update(frameTime);
        window.draw(cursor);
        enemiesModule.callAllAIs();
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