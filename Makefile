# Compilateur et options
CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LFLAGS=

# Dossiers
SRC_DIR = ./src
INC_DIR = ./include
OBJ_DIR = ./obj
BIN_DIR = ./bin

# Fichiers
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
TARGET = $(BIN_DIR)/my_game

# Dependencies explicites (headers)
$(OBJ_DIR)/board.o: $(INC_DIR)/board.h $(INC_DIR)/player.h $(INC_DIR)/card.h
$(OBJ_DIR)/interface.o: $(INC_DIR)/interface.h $(INC_DIR)/board.h $(INC_DIR)/player.h $(INC_DIR)/card.h
$(OBJ_DIR)/player.o: $(INC_DIR)/player.h $(INC_DIR)/card.h

# Règle par défaut
all: $(TARGET)

# Édition des liens
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# Compilation des objets dans obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean