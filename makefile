cc = g++
cflags = -I SFML-2.5.0/include -L SFML-2.5.0/lib -Wall -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++0x
objects = Rigidbody.o Obstacle.o Animation.o AnimatedSprite.o DrawingModule.o TileMap.o Chao.o ColisionModule.o MapModule.o Floor.o DrawTransform.o main.o Wall.o SquareObstacle.o Gui.o EnemyBat.o Monster.o EnemiesModule.o TextModule.o

install: $(objects)
	$(cc) -o captain-cleiton $(objects) include/Lista.hpp include/Listaestatica.hpp $(cflags)
	.export LD_LIBRARY_PATH=SFML-2.5.0/lib && ./captain-cleiton

main.o: main.cpp
	$(cc) -c main.cpp $(cflags)

EnemyBat.o:
	$(cc) -c src/EnemyBat.cpp $(cflags)

Monster.o:
	$(cc) -c src/Monster.cpp $(cflags)

TextModule.o:
	$(cc) -c src/TextModule.cpp $(cflags)

EnemiesModule.o:
	$(cc) -c src/EnemiesModule.cpp $(cflags)

Floor.o:
	$(cc) -c src/Floor.cpp $(cflags)

Gui.o:
	$(cc) -c src/Gui.cpp $(cflags)

Rigidbody.o:
	$(cc) -c src/Rigidbody.cpp $(cflags)

Obstacle.o:
	$(cc) -c src/Obstacle.cpp $(cflags)

MapModule.o:
	$(cc) -c src/MapModule.cpp $(cflags)

Animation.o:
	$(cc) -c src/Animation.cpp $(cflags)

AnimatedSprite.o:
	$(cc) -c src/AnimatedSprite.cpp $(cflags)

DrawingModule.o:
	$(cc) -c src/DrawingModule.cpp $(cflags)

TileMap.o:
	$(cc) -c src/TileMap.cpp $(cflags)

Chao.o:
	$(cc) -c src/Chao.cpp $(cflags)

ColisionModule.o:
	$(cc) -c src/ColisionModule.cpp $(cflags)

DrawTransform.o:
	$(cc) -c src/DrawTransform.cpp $(cflags)

Wall.o:
	$(cc) -c src/Wall.cpp $(cflags)

SquareObstacle.o:
	$(cc) -c src/SquareObstacle.cpp $(cflags)

remove:
	rm -rf *.o
	rm captain-cleiton

