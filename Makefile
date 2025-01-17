CC=gcc
flags=-Wall -pedantic -std=c99 -MMD -g
SRC= main.c alphabet.c types.c plateau.c
TARGET= bin/main.o


all:
	@echo "Compilation de $(SRC) en $(TARGET)"
	@$(CC) $(flags) $(SRC) -o $(TARGET)

clean:
	@rm -f bin/*.o bin/*.d bin/*.out