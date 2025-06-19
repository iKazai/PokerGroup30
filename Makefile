# Nom de l'exécutable
EXEC = test_lotE

# Répertoires
SRC_DIR = src
INC_DIR = include

# Fichiers source
SRC = $(SRC_DIR)/board.c $(SRC_DIR)/card.c $(SRC_DIR)/player.c $(SRC_DIR)/interface.c test_lotE.c

# Objets
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I$(INC_DIR)

# Règle principale
all: $(EXEC)

# Lier les objets pour créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyer les .o et l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

fclean: clean
re: fclean all

.PHONY: all clean fclean re