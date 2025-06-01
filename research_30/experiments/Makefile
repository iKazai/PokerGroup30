# Compilateur à utiliser
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Iinclude
# Fichiers sources pour poker_simulate
SRC = main.c eval.c miroir.c src/board.c src/player.c src/card.c
# Nom de l'exécutable
EXEC = poker_simulate

# Règle par défaut : compile poker_simulate
all: $(EXEC)

# Règle pour poker_simulate
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(EXEC)

# Règle pour compiler et exécuter poker_simulate
run: $(EXEC)
	.\$(EXEC).exe
