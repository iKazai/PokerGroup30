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

clean:
    rm -rf $(OBJ)*.o