CC=gcc
flags=-Wall -pedantic -std=gnu99 -MMD -g `sdl2-config --cflags`
LDFLAGS = -lSDL2 -lSDL2_ttf
SRC= src/main.c src/alphabet.c src/types.c src/plateau.c src/gestion_tour_jeu.c
TARGET= bin/main.o 
LIBS=`sdl2-config --libs`

all:
	@echo "Compilation de $(SRC) en $(TARGET)"
	@$(CC) $(flags) $(SRC) -o $(TARGET) $(LIBS) $(LDFLAGS)

clean:
	@rm -f bin/*.o bin/*.d bin/*.out