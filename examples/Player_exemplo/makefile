cc = g++
cflags = -Wall -lsfml-graphics -lsfml-window -lsfml-system -std=c++0x 
objects = Rigidbody.o Obstacle.o Animation.o AnimatedSprite.o DrawingModule.o TileMap.o Chao.o ColisionModule.o MapModule.o Floor.o DrawTransform.o main.o Wall.o SquareObstacle.o Gui.o Projetil.o Gun.o ProjetilModule.o Player.o PlayerController.o

install: $(objects)
	$(cc) -o exemplo $(objects) ../../include/Lista.hpp ../../include/Listaestatica.hpp $(cflags)
	./exemplo

main.o: main.cpp
	$(cc) -c main.cpp $(cflags)

Floor.o:
	$(cc) -c ../../src/Floor.cpp $(cflags)

Gui.o:
	$(cc) -c ../../src/Gui.cpp $(cflags)

Rigidbody.o: 
	$(cc) -c ../../src/Rigidbody.cpp $(cflags)

Obstacle.o:
	$(cc) -c ../../src/Obstacle.cpp $(cflags)

MapModule.o:
	$(cc) -c ../../src/MapModule.cpp $(cflags)
	
Animation.o: 
	$(cc) -c ../../src/Animation.cpp $(cflags)

AnimatedSprite.o:
	$(cc) -c ../../src/AnimatedSprite.cpp $(cflags)

DrawingModule.o:
	$(cc) -c ../../src/DrawingModule.cpp $(cflags)

TileMap.o:
	$(cc) -c ../../src/TileMap.cpp $(cflags)

Chao.o:
	$(cc) -c ../../src/Chao.cpp $(cflags)

ColisionModule.o:
	$(cc) -c ../../src/ColisionModule.cpp $(cflags)

DrawTransform.o:
	$(cc) -c ../../src/DrawTransform.cpp $(cflags)

Wall.o:
	$(cc) -c ../../src/Wall.cpp $(cflags)

SquareObstacle.o:
	$(cc) -c ../../src/SquareObstacle.cpp $(cflags)

Projetil.o:
	$(cc) -c ../../src/Projetil.cpp $(cflags)

Gun.o:
	$(cc) -c ../../src/Gun.cpp $(cflags)

ProjetilModule.o:
	$(cc) -c ../../src/ProjetilModule.cpp $(cflags)

Player.o:
	$(cc) -c ../../src/Player.cpp $(cflags)

PlayerController.o:
	$(cc) -c ../../src/PlayerController.cpp $(cflags)

remove:
	rm *.o
	rm exemplo
	
