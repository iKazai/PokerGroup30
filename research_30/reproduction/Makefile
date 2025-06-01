# Compilateur à utiliser
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Iinclude
# Fichiers sources pour poker_probabiliste
SRC = main.c probabiliste.c src/board.c src/player.c src/card.c
# Nom de l'exécutable
EXEC = poker_probabiliste

# Règle par défaut : compile poker_probabiliste
all: $(EXEC)

# Règle pour poker_probabiliste
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Règle pour compiler et exécuter poker_probabiliste
run: $(EXEC)
	.\$(EXEC).exe