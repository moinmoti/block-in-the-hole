FLAGS=-lglfw -lGLEW -lGL -ldl -std=c++11

all: game

game: main.o
	g++ -o game main.o $(FLAGS)

main.o: main.cpp
	g++ -c main.cpp $(FLAGS)

clean:
	rm game *.o
