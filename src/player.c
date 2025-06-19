
#include <stdlib.h>
#include <stdbool.h>
#include "../include/player.h"

#define MAX_PLAYERS 4

static player players[MAX_PLAYERS]; //creation d'un tableau pour stocker les joueurs present sur le plateau 
static int player_count = 0;// nb de joueurs présent
static int player_id = 0; // initialisation d'un compteur pour attribuer un id unique

player create_player(void) {
    if (player_count >= MAX_PLAYERS) return NULL;

    player new_player = malloc(sizeof(struct player_base));
    if (!new_player) return NULL;

    new_player->deck = calloc(4, sizeof(card)); // initial capacité main
    new_player->deck_size = 0;

    new_player->laids = calloc(2, sizeof(card)); // capacité max fixée
    new_player->laids_size = 0;

    new_player->tokens=0; // E.3 : initialisation du nombre de jetons
    new_player->current_bet = 0; // E.3 : initialisation de la mise actuelle de jeton 

    new_player->slate = false;
    new_player->id = player_id++;
    new_player->team_id = -1;

    players[player_count++] = new_player;
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

//E.3 : récupère le nombre total de jetons du joueur
int get_tokens(player p) {
    return p->tokens;
}
//E.3 : définit nombre total de jetons du joueur
void set_tokens(player p, int tokens) {
    if (p && tokens >= 0) {
        p->tokens = tokens;
    }
}

//E.3 : ajoute des jetons au joueur 
void add_tokens(player p, int tokens) {
    if (p && tokens >= 0) {
        p->tokens += tokens;
    }
}

//E.3 retire des jetons du total du joueur
void remove_tokens(player p, int tokens) {
    if (p && tokens >= 0 && p->tokens >= tokens) {
        p->tokens -= tokens;
    }
}
//E.3 recupere le nombre de jeton misés
int get_current_bet(player p) {
    return p->current_bet;
}

//E.3 définit le nombre de jeton misés
void set_current_bet(player p, int tokens) {
    if (p && tokens >= 0) {
        p->current_bet = tokens;
    }
}
