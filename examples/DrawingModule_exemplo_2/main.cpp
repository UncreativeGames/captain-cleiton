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
#include <iostream>
#include <cmath>

#define speed 100.f

int main()
{
    int x;
    int y;
    srand(time(NULL));
    int floor_choice[4] = {0,1,2,3};
    int randomIndex = rand() % 4;
    Listaestatica<Rigidbody> walls_and_floor;
    Listaestatica<Rigidbody> obstacles;
    Listaestatica<Rigidbody> player_and_monsters;
    Lista<Rigidbody> projeteis;

    Lista<Lista<Rigidbody> >* Lista_para_deletar_retorno_modulo_colisao;

    // setup window
    sf::Vector2i screenDimensions(DEFAULT_SIZE_X*32,DEFAULT_SIZE_Y*32);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Captain Cleiton.");
    window.setFramerateLimit(60);

    DrawingModule designer(&walls_and_floor,&obstacles,&player_and_monsters,&projeteis,&window);
    ColisionModule colisor(&walls_and_floor,&obstacles,&player_and_monsters,&projeteis);

    sf::Texture personagem;
    if(!personagem.loadFromFile("player.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    sf::Texture pedra;
    if(!pedra.loadFromFile("cave.png")){
        std::cout << "Deu Ruim" << std::endl;
    }
    sf::Texture wall;
    if(!wall.loadFromFile("Tile.png")){
        std::cout << "Deu Ruim Na Wall" << std::endl;
    }
    sf::Texture floor;
    if(!floor.loadFromFile("a1floor.png")){
        std::cout << "Deu Ruim Na Wall" << std::endl;
    }

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
    dut->setPosition(sf::Vector2f(400,300));
    dut->setRaio(10);

    player_and_monsters.add(dut);
    Point p {0,0};
    TileMap * m = new TileMap(DEFAULT_SIZE_X,DEFAULT_SIZE_Y,p);
    m->generateRadialHunter();
    Obstacle* rock;
    Chao* chao;
    char offset = 16;
    for(int i = 0;i<DEFAULT_SIZE_X;i++)
    {
        for(int j = 0;j<DEFAULT_SIZE_Y;j++) {
            if(m->getTile(i,j)==PEDRA)
            {
                rock = new Obstacle(pedra,sf::IntRect(0, 0, 32, 32));
                rock->setRaio(16);
                rock->setOrigin(16,16);
                rock->setPosition(i*32+offset,j*32+offset);
                obstacles.add(rock);
            }
            if(m->getTile(i,j)==PAREDE)
            {
                rock = new Obstacle(wall,sf::IntRect(32, 32, 32, 32));
                rock->setRaio(16);
                rock->setOrigin(16,16);
                rock->setPosition(i*32+offset,j*32+offset);
                walls_and_floor.add(rock);
            }
            else
            {
                randomIndex = rand() % 4;
                chao = new Chao(floor,sf::IntRect(0,(32*floor_choice[randomIndex]), 32, 32));
                chao->setOrigin(16,16);
                chao->setPosition(i*32+offset,j*32+offset);
                walls_and_floor.add(chao);
            }
        }
    }

    sf::Clock frameClock;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        x = 0;
        y = 0;

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            m->generateRadialHunter();
            obstacles.limpar();
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

        // update AnimatedSprite
        dut->update(frameTime);


        //x += dut->colision(rock).x;
        //y += dut->colision(rock).y;

        //dut->move(x,y);

        designer.update();
    }

    return 0;
}
