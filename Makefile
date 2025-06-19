# Nom de l'exécutable
EXEC = main_exec

# Répertoire source
SRC_DIR = src

# Fichiers sources (main + tous les autres .c nécessaires)
SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/board.c \
      $(SRC_DIR)/player.c \
      $(SRC_DIR)/interface.c \
      $(SRC_DIR)/card.c

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

# Règle principale : compile → exécute → clean
all: $(EXEC)
	./$(EXEC)
	$(MAKE) clean

# Compilation + édition des liens
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	- rm -f $(EXEC)

.PHONY: all clean
