# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
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

# Nettoyage
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
