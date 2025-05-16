# Variables
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c99 -Iinclude
OBJDIR = obj
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/main

# Fichiers sources
SRC = $(SRCDIR)/board.c \
      $(SRCDIR)/player.c \
      $(SRCDIR)/interface.c \
      $(SRCDIR)/card.c \
      $(SRCDIR)/main.c

# Fichiers objets
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(OBJ) -o $@

# Compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création des répertoires si besoin
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)


SEARCH_DIR = research_30/experiments
# Fichiers sources
SEARCH_SRC = $(SEARCH_DIR)/eval.c \
      $(SEARCH_DIR)/miroir.c \
      $(SEARCH_DIR)/main.c

SEARCH_TARGET = research_30/experiments/test_eval
SEARCH_OBJ = $(patsubst $(SEARCH_DIR)/%.c, $(SEARCH_DIR)/%.o, $(SEARCH_SRC))

research_30: $(SEARCH_TARGET)

$(SEARCH_DIR)/%.o: $(SEARCH_DIR)/%.c

$(SEARCH_TARGET): $(SEARCH_OBJ) $(OBJDIR)/board.o $(OBJDIR)/player.o $(OBJDIR)/card.o 
	$(CC) $^ -o $@



# Nettoyage
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	rm research_30/experiments/*.o

.PHONY: all clean
