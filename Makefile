CC=gcc
flags=-Wall -pedantic -std=c99 -MMD -g `sdl2-config --cflags`
SRC= main.c alphabet.c types.c plateau.c gestion_tour_jeu.c
TARGET= bin/main.o 
LIBS=`sdl2-config --libs`

all:
	@echo "Compilation de $(SRC) en $(TARGET)"
	@$(CC) $(flags) $(SRC) -o $(TARGET) $(LIBS)

clean:
	@rm -f bin/*.o bin/*.d bin/*.out