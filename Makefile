FLAGS=-lglfw -lGLEW -lGL -ldl -std=c++11

all: game

game: main.o untouchable.o
	g++ -o game main.o untouchable.o $(FLAGS)

main.o: main.cpp
	g++ -c main.cpp $(FLAGS)

untouchable.o: untouchable.cpp
	g++ -c untouchable.cpp $(FLAGS)

clean:
	rm game *.o
