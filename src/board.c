#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "card.h" 

board create_board() {
    board b = malloc(sizeof(struct board_base));

    b->teams = NULL;
    b->team_sizes = NULL;
    b->score = NULL;
    b->num_teams = 0;

    b->c = NULL;
    b->out_card_count = 0;

    return b;
}

void free_board(board b) 
{
    free(b->teams[0]);
    free(b->teams[1]);
    free(b->teams);
    free(b->team_sizes);
    free(b->score);
    free(b->c);
    free(b);
}

void add_team(board b) 
{
    if (b->num_teams > 0)
    {
        return;
    }
    b->teams = malloc(2 * sizeof(player*));
    b->team_sizes = malloc(2 * sizeof(int));
    b->score = malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++) 
    {
        b->teams[i] = malloc(2 * sizeof(player));
        b->team_sizes[i] = 0;
        b->score[i] = 0;
    }
    b->num_teams = 2;
}

void add_player_to_team(board b, int team_id, player p) 
{
    if (team_id < 0 || team_id > 1 || b->team_sizes[team_id] >= 2)
    {
        return;
    }
    b->teams[team_id][b->team_sizes[team_id]] = p;
    b->team_sizes[team_id]++;
}

int get_number_of_teams(board b) 
{
    return 2;
}

int get_number_of_players_in_team(board b, int team_id) 
{
    if (team_id < 0 || team_id > 1)
    {
        return 0;
    }
    else 
    {
        return b->team_sizes[team_id];
    }
}

player get_player(board b, int team_id, int player_index) 
{
    if (team_id < 0 || team_id > 1)
    {
        return NULL;
    }
    else if (player_index < 0 || player_index >= b->team_sizes[team_id]) 
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
    if (team_id < 0 || team_id > 1)
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
    if (team_id < 0 || team_id > 1) 
    {
        return;
    }
    b->score[team_id] = score;
}

void add_out_of_game_card(board b, card c) 
{
    card* ca = malloc((b->out_card_count + 1) * sizeof(card));
    for (int i = 0; i < b->out_card_count; i++) 
    {
        ca[i] = b->c[i];
    }
    ca[b->out_card_count] = c;

    free(b->c);
    b->c = ca;
    b->out_card_count++;
}

int get_number_of_out_of_game_cards(board b) 
{
    return b->out_card_count;
}

card get_out_of_game_card(board b, int card_index) 
{
    if (card_index < 0 || card_index >= b->out_card_count)
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
    int index = -1;
    for (int i = 0; i < b->out_card_count; i++) 
    {
        if (get_card_id(b->c[i]) == get_card_id(c)) 
        {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    card* ca = malloc((b->out_card_count - 1) * sizeof(card));
    int j = 0;
    for (int i = 0; i < b->out_card_count; i++) 
    {
        if (i != index) 
        {
            ca[j] = b->c[i];
            j++;
        }
    }

    free(b->c);
    b->c = ca;
    b->out_card_count--;
}
