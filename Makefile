CXX = g++
LIBS = -lSDL2 -lSDL2_image
SRC = $(wildcard *.cpp)

all:
	$(CXX) $(SRC) -o game $(LIBS)

run:
	./game

clean:
	rm -f game
