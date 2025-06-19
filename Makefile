# Nom de l'exécutable
EXEC = test_E_exec

# Répertoires
SRC_DIR = src
INC_DIR = include
TEST_DIR = test_E

# Fichiers sources
SRC = $(SRC_DIR)/board.c \
      $(SRC_DIR)/card.c \
      $(SRC_DIR)/interface.c \
      $(SRC_DIR)/player.c \
      $(TEST_DIR)/test_E.c

# Objets
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I$(INC_DIR)

# Règle principale
all: $(EXEC)

# Génération de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	rm -f $(OBJ) $(EXEC)

fclean: clean
re: fclean all

.PHONY: all clean fclean re