FLAGS=-lglfw -lGLEW -lGL -ldl -std=c++11

all: game

game: main.o untouchable.o grid.o cuboid.o
	g++ -o game main.o untouchable.o grid.o cuboid.o $(FLAGS)

main.o: main.cpp
	g++ -c main.cpp $(FLAGS)

untouchable.o: untouchable.cpp
	g++ -c untouchable.cpp $(FLAGS)

grid.o: grid.cpp
	g++ -c grid.cpp $(FLAGS)

cuboid.o: cuboid.cpp
	g++ -c cuboid.cpp $(FLAGS)

clean:
	rm game *.o
