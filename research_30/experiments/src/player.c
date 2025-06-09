#include <stdlib.h>
#include <stdbool.h>
#include "constante.h"
#include "player.h"

player players[NUM_PLAYERS]; // E.2 : Utilisation de NUM_PLAYERS
int player_count = 0;
int player_id = 0;

player create_player(void) {
    if (player_count >= NUM_PLAYERS) return NULL; // E.2 : Utilisation de NUM_PLAYERS
    
    player new_player = malloc(sizeof(struct player_base));
    if (!new_player) return NULL;
    
    new_player->deck = NULL;
    new_player->deck_size = 0;
    new_player->laids = NULL;
    new_player->laids_size = 0;
    new_player->slate = false;
    new_player->id = player_id++;
    new_player->team_id = -1;
    new_player->tokens = 0;
    new_player->current_bet = 0;
    new_player->bet_color = -1; // E.2 : Initialisation de la couleur pariée

    players[player_count] = new_player;
    player_count++;
    return new_player;
}

void free_player(player p) {
    if (!p) return;

    // Retirer le joueur du tableau
    for (int i = 0; i < player_count; i++) {
        if (players[i] == p) {
            for (int j = i; j < player_count - 1; j++) {
                players[j] = players[j + 1];
            }
            players[player_count - 1] = NULL;
            break;
        }
    }
    player_count--;

    // Libérer les cartes de la main
    if (p->deck) {
        for (int i = 0; i < p->deck_size; i++) {
            if (p->deck[i]) free_card(p->deck[i]);
        }
        free(p->deck);
    }

    // Libérer les cartes posées
    if (p->laids) {
        for (int i = 0; i < p->laids_size; i++) {
            if (p->laids[i]) free_card(p->laids[i]);
        }
        free(p->laids);
    }

    free(p);
}


int get_player_id(player p) {
    return p ? p->id : -1;
}


void add_card_to_hand(player p, card c) {
    if (!p || !c) return;

    card* temp = realloc(p->deck, (p->deck_size + 1) * sizeof(card));
    if (!temp) return;

    p->deck = temp;
    p->deck[p->deck_size++] = c;
}

int get_size_of_hand(player p) {
    return p ? p->deck_size : 0;
}

card get_card_in_hand(player p, int index) {
    if (!p || index < 0 || index >= p->deck_size) return NULL;
    return p->deck[index];
}

void remove_card_from_hand(player p, card c) {
    if (!p || !c || p->deck_size == 0) return;

    int index = -1;
    for (int i = 0; i < p->deck_size; i++) {
        if (p->deck[i] && p->deck[i]->id == c->id) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    for (int i = index; i < p->deck_size - 1; i++) {
        p->deck[i] = p->deck[i + 1];
    }
    p->deck_size--;

    if (p->deck_size == 0) {
        free(p->deck);
        p->deck = NULL;
    } else {
        card* temp = realloc(p->deck, p->deck_size * sizeof(card));
        if (temp) p->deck = temp;
    }
}

void play_card(player p, card c) {
    if (!p || !c) {
        perror("[play_card] Player or card is NULL.");
        exit(EXIT_FAILURE);
    }

    if (p->laids_size >= 2) {
        perror("[play_card] Too many cards laid.");
        exit(EXIT_FAILURE);
    }

    p->laids[p->laids_size++] = c;
}

int get_number_of_played_cards(player p) {
    return p ? p->laids_size : 0;
}

card get_played_card(player p, int index) {
    if (!p || index < 0 || index >= p->laids_size) return NULL;
    return p->laids[index];
}

void remove_played_card(player p, card c) {
    if (!p || !c || p->laids_size == 0) return;

    int index = -1;
    for (int i = 0; i < p->laids_size; i++) {
        if (p->laids[i] && p->laids[i]->id == c->id) {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    for (int i = index; i < p->laids_size - 1; i++) {
        p->laids[i] = p->laids[i + 1];
    }

    p->laids_size--;

    if (p->laids_size == 0) {
        free(p->laids);
        p->laids = NULL;
    } else {
        card* temp = realloc(p->laids, p->laids_size * sizeof(card));
        if (temp) p->laids = temp;
    }
}

int get_slate(player p) {
    return p ? p->slate : 0;
}

void set_slate(player p, int bet) {
    if (!p) return;
    p->slate = (bet == 1);
}

int get_bet_color(player p) { // E.2 : Implémentation de get_bet_color
    return p->bet_color;
}

void set_bet_color(player p, int color) { // E.2 : Implémentation de set_bet_color
    if (color >= COLOR_RED && color <= COLOR_MULTICOLOR) {
        p->bet_color = color;
    }
}

