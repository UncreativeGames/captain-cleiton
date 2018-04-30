cc = g++
cflags = -Wall -lsfml-graphics -lsfml-window -lsfml-system
objects = Rigidbody.o Obstacle.o Animation.o AnimatedSprite.o DrawingModule.o

install: main.o
	$(cc) -o exemplo main.o $(objects) ../../include/Lista.hpp ../../include/Listaestatica.hpp ../../src/DrawTransform.cpp $(cflags)
	./exemplo

main.o: main.cpp $(objects)
	$(cc) -c main.cpp $(objects) $(cflags)

Rigidbody.o: 
	$(cc) -c ../../src/Rigidbody.cpp ../../src/DrawTransform.cpp $(cflags)

Obstacle.o: Rigidbody.o
	$(cc) -c ../../src/Obstacle.cpp Rigidbody.o $(cflags)

Animation.o: 
	$(cc) -c ../../src/Animation.cpp $(cflags)

AnimatedSprite.o: Animation.o Rigidbody.o
	$(cc) -c ../../src/AnimatedSprite.cpp $(cflags)

DrawingModule.o: Rigidbody.o 
	$(cc) -c ../../src/DrawingModule.cpp Rigidbody.o ../../include/Listaestatica.hpp ../../include/Lista.hpp $(cflags)

remove:
	rm *.o
	rm exemplo
	