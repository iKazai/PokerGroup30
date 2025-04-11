CC=gcc
CFLAGS=-Wall -Wextra -std=c99
LFLAGS=
INC=-I include/
SRC=src/
EXEC=main
OBJ=obj/

all: $(EXEC)

main: $(SRC)main.c $(SRC)article.o 
    $(CC) -o $(SRC)$@ $^ $(CFLAGS) 

$(SRC)%.o : $(SRC)%.c
    $(CC) -o $@ -c $< $(CFLAGS)

RESEARCH_PATH = research_30/experiments/production/

research: $(RESEARCH_PATH)miroir.c $(RESEARCH_PATH)miroir.o 
    $(CC) -o $(SRC)$@ $^ $(CFLAGS)

clean:
    rm -rf $(OBJ)*.o