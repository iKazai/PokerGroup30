#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/board.h" 

board create_board() {
    board b = malloc(sizeof(struct board_base));
    if (!b) return NULL;

    b->teams = calloc(2 , sizeof(player*));
    if (!b->teams) {
        free(b);
        return NULL;
    }

    for (int i = 0; i < 2; i++) {
        b->teams[i] = calloc(2 , sizeof(player));
        if (!b->teams[i]) {
            for (int j = 0; j < i; j++) free(b->teams[j]);
            free(b->teams);
            free(b);
            return NULL;
        }
    }

    b->score = calloc(2 , sizeof(int));
    if (!b->score) {
        for (int i = 0; i < 2; i++) free(b->teams[i]);
        free(b->teams);
        free(b);
        return NULL;
    }

    b->score[0] = 0;
    b->score[1] = 0;
    b->c = NULL;

    return b;
}

void free_board(board b) 
{
    for (int i = 0; i < 2; i++) 
    {
        free(b->teams[i]);
    }
    free(b->teams);
    free(b->score);
    if (b->c) {
        for (int i = 0; b->c[i]; i++) {
            free_card(b->c[i]);
        }
        free(b->c);
    }
    free(b);
}

void add_team(board b) {
    if (!b) return;

    // NE PAS libérer les joueurs (et donc leurs cartes), car ils viennent juste d’être créés

    // Réinitialisation simple de la structure
    b->teams = malloc(2 * sizeof(player*));
    for (int i = 0; i < 2; i++) {
        b->teams[i] = malloc(2 * sizeof(player));
        for (int j = 0; j < 2; j++) {
            b->teams[i][j] = NULL;
        }
    }

    b->score = malloc(2 * sizeof(int));
    b->score[0] = 0;
    b->score[1] = 0;
}

void add_player_to_team(board b, int team_id, player p) 
{
    for (int i = 0; i < 2; i++) 
    {
        if (b->teams[team_id][i] == NULL) 
        {
            b->teams[team_id][i] = p;
            return;
        }
    }
}

int get_number_of_teams() 
{

    return 2;
}

int get_number_of_players_in_team(board b, int team_id) 
{
    int count = 0;
    for (int i = 0; i < 2; i++) 
    {
        if (b->teams[team_id][i] != NULL) 
        {
            count++;
        }
    }
    return count;
}

player get_player(board b, int team_id, int player_index) 
{
    if (team_id < 0 || team_id >= 2) 
    {
        return NULL;
    }
    else if (player_index < 0 || player_index >= 2) 
    {
        return NULL;
    }
    else 
    {
        return b->teams[team_id][player_index];
    }
}

int get_score_of_team(board b, int team_id) 
{
    if (team_id < 0 || team_id >= 2) 
    {
        return -1;
    }
    else 
    {
        return b->score[team_id];
    }
}

void set_score_of_team(board b, int team_id, int score) 
{
    if (team_id < 0 || team_id >= 2) 
    {
        return;
    }
    b->score[team_id] = score;
}

void add_out_of_game_card(board b, card c) 
{
    int count = 0;
    while (b->c && b->c[count])
    {
        count++;
    } 

    card* new_cards = malloc((count + 2) * sizeof(card)); 
    for (int i = 0; i < count; i++) 
    {
        new_cards[i] = b->c[i];
    }
    new_cards[count] = c;
    new_cards[count + 1] = NULL;
    free(b->c);
    b->c = new_cards;
}

int get_number_of_out_of_game_cards(board b) 
{
    int count = 0;
    while (b->c && b->c[count])
    {
        count++;
    }

    return count;
}

card get_out_of_game_card(board b, int card_index) 
{
    int count = get_number_of_out_of_game_cards(b);
    if (card_index < 0 || card_index >= count)
    {
       return NULL; 
    }
    else 
    {
        return b->c[card_index];
    }
}

void remove_out_of_game_card(board b, card c) 
{
    int count = get_number_of_out_of_game_cards(b);
    int index = -1;
    for (int i = 0; i < count; i++) 
    {
        if (get_card_id(b->c[i]) == get_card_id(c)) 
        {
            index = i;
            return;
        }
    }
    if (index == -1) 
    {
        return;
    }
    free_card(b->c[index]);
    card* new_cards = malloc(count * sizeof(card));
    int j = 0;
    for (int i = 0; i < count; i++) 
    {
        if (i != index) 
        {
            new_cards[j++] = b->c[i];
        }
    }
    new_cards[j] = NULL;
    free(b->c);
    b->c = new_cards;
}