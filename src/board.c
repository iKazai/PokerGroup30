#include <stdio.h>
#include <stdlib.h>
#include "board.h"

board create_board()
{
    board b = malloc(sizeof(board));
    b->p = NULL;
    b->c = NULL;
    return b;
}

void free_board(board b)
{
    free(b->p);
    free(b->c);
    free(b);
}

void add_team(board b)
{
    
}