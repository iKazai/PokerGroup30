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


# === Compilation du programme research ===
RESEARCH_DIR = research_30/experiments
RESEARCH_SRC = $(RESEARCH_DIR)/eval.c \
               $(RESEARCH_DIR)/miroir.c \
               $(RESEARCH_DIR)/main.c \
               src/board.c \
               src/player.c \
               src/card.c

RESEARCH_OBJ = $(patsubst %.c, obj/%.o, $(notdir $(RESEARCH_SRC)))
RESEARCH_OBJ_FULL = $(addprefix obj/, $(notdir $(RESEARCH_SRC:.c=.o)))
RESEARCH_BIN = bin/research

research: $(RESEARCH_BIN)

$(RESEARCH_BIN): $(RESEARCH_OBJ_FULL) | $(BINDIR)
	$(CC) $(RESEARCH_OBJ_FULL) -o $@

# Compile les .o nécessaires pour research
obj/research_%.o: $(RESEARCH_DIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

obj/research_%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@




# Nettoyage
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
