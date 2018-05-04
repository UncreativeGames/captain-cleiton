cc = g++
cflags = -Wall -lsfml-graphics -lsfml-window -lsfml-system
objects = Rigidbody.o Obstacle.o Animation.o AnimatedSprite.o DrawingModule.o ColisionModule.o main.o

install: $(objects)
	$(cc) -o exemplo $(objects) ../../include/Lista.hpp ../../include/Listaestatica.hpp ../../src/DrawTransform.cpp $(cflags)
	./exemplo

main.o: main.cpp
	$(cc) -c main.cpp $(cflags)

Rigidbody.o: 
	$(cc) -c ../../src/Rigidbody.cpp ../../src/DrawTransform.cpp $(cflags)

Obstacle.o:
	$(cc) -c ../../src/Obstacle.cpp $(cflags)

Animation.o: 
	$(cc) -c ../../src/Animation.cpp $(cflags)

AnimatedSprite.o:
	$(cc) -c ../../src/AnimatedSprite.cpp $(cflags)

DrawingModule.o:
	$(cc) -c ../../src/DrawingModule.cpp $(cflags)

ColisionModule.o:
	$(cc) -c ../../src/ColisionModule.cpp $(cflags)

remove:
	rm *.o
	rm exemplo
	