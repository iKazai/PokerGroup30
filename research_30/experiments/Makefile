# === FICHIER : research_30/experiments/Makefile ===

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../../include
SRC = ../../src
BIN = eval

OBJ = $(SRC)/board.c $(SRC)/player.c $(SRC)/card.c

all: $(BIN)

eval: eval.c miroir.c main.c $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) eval.c miroir.c main.c $(OBJ)

run: eval
	./$(BIN)

clean:
	del /Q $(BIN).exe 2>nul || rm -f $(BIN)
