#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "card.h" 

board create_board() {
    board b = malloc(sizeof(struct board_base));
    if (!b) return NULL;

    b->teams = calloc(2, sizeof(player*));
    if (!b->teams) {
        free(b);
        return NULL;
    }

    for (int i = 0; i < 2; i++) {
        b->teams[i] = calloc(2, sizeof(player));
        if (!b->teams[i]) {
            for (int j = 0; j < i; j++) free(b->teams[j]);
            free(b->teams);
            free(b);
            return NULL;
        }
    }

    b->score = calloc(2, sizeof(int));
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

void free_board(board b) {
    if (!b) return;

    for (int i = 0; i < 2; i++) {
        if (b->teams[i]) free(b->teams[i]);
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

    // Libération mémoire précédente
    if (b->teams) {
        for (int i = 0; i < 2; i++) {
            if (b->teams[i]) free(b->teams[i]);
        }
        free(b->teams);
    }

    if (b->score) free(b->score);

    // Réinitialisation
    b->teams = calloc(2, sizeof(player*));
    for (int i = 0; i < 2; i++) {
        b->teams[i] = calloc(2, sizeof(player));
    }

    b->score = calloc(2, sizeof(int));
    b->score[0] = 0;
    b->score[1] = 0;
}

void add_player_to_team(board b, int team_id, player p) {
    if (!b || team_id < 0 || team_id >= 2) return;

    for (int i = 0; i < 2; i++) {
        if (b->teams[team_id][i] == NULL) {
            b->teams[team_id][i] = p;
            return;
        }
    }
}

int get_number_of_teams() {
    return 2;
}

int get_number_of_players_in_team(board b, int team_id) {
    if (!b || team_id < 0 || team_id >= 2) return 0;

    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (b->teams[team_id][i] != NULL) count++;
    }
    return count;
}

player get_player(board b, int team_id, int player_index) {
    if (!b || team_id < 0 || team_id >= 2 || player_index < 0 || player_index >= 2)
        return NULL;
    return b->teams[team_id][player_index];
}

int get_score_of_team(board b, int team_id) {
    if (!b || team_id < 0 || team_id >= 2) return -1;
    return b->score[team_id];
}

void set_score_of_team(board b, int team_id, int score) {
    if (!b || team_id < 0 || team_id >= 2) return;
    b->score[team_id] = score;
}

void add_out_of_game_card(board b, card c) {
    if (!b || !c) return;

    int count = 0;
    while (b->c && b->c[count]) count++;

    card* new_cards = calloc(count + 2, sizeof(card));
    for (int i = 0; i < count; i++) {
        new_cards[i] = b->c[i];
    }
    new_cards[count] = c;
    new_cards[count + 1] = NULL;

    free(b->c);
    b->c = new_cards;
}

int get_number_of_out_of_game_cards(board b) {
    if (!b || !b->c) return 0;
    int count = 0;
    while (b->c[count]) count++;
    return count;
}

card get_out_of_game_card(board b, int card_index) {
    if (!b || card_index < 0) return NULL;
    int count = get_number_of_out_of_game_cards(b);
    if (card_index >= count) return NULL;
    return b->c[card_index];
}

void remove_out_of_game_card(board b, card c) {
    if (!b || !c) return;

    int count = get_number_of_out_of_game_cards(b);
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (get_card_id(b->c[i]) == get_card_id(c)) {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    free_card(b->c[index]);

    card* new_cards = calloc(count, sizeof(card)); // count - 1 + NULL
    int j = 0;
    for (int i = 0; i < count; i++) {
        if (i != index) {
            new_cards[j++] = b->c[i];
        }
    }
    new_cards[j] = NULL;

    free(b->c);
    b->c = new_cards;
}


/*************** AJout du lot_e ***************/




void apply_special_effect(board b, card c){//test
    if(!c->is_special){
        perror("[apply_special_effect]: The card is not special.");
        return;
    }
    switch (c->name)
    {
        case "Thuy Vo":
            name = "Choisissez une carte posée ce tour ci, cette carte devient un 1 rouge. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "David Roussel":
            name = "Choisissez une carte posée ce tour ci, cette carte devient un 2 noir. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "Abass Sagna":
            name = "Choisissez une carte posée ce tour ci, cette carte devient un 3 sans couleur. Elle n'est pas comptée dans les sommes relatives aux paris dont la couleur est noir ou rouge. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "Renaud Rioboo":
            name = "Choisissez une carte posée ce tour ci, cette carte devient un 4 rouge. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "Kevin Goilard":
            name = "Choisissez une carte posée ce tour ci, cette carte devient un 5 noir. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "Laurence Bourard":
            name = "Inversez le pari de toutes les joueuses. Les Victoire deviennent des Défaite et inversement. Les couleurs des paris restent inchangés.";
            break;
        case "Anne-Laure Ligozat":
            name = "Les cartes mises de côté lors des tours précédents sont redistribuées aléatoirement à toutes les joueuses.";
            break;
        case "Vincent Fagnon":
            name = "Lors de ce tour, les cartes de valeur 2 deviennent de valeur 5 et inversement.";
            break;
        case "Valentin Honoré":
            name = "Ajoutez un tour de jeu après celui ci.";
            break;
        case "Fetia Bannour":
            name = "Retirez un tour de jeu. Si ce tour était le dernier, le jeu s'arrête immédiatement, les mises ne sont pas rendues.";
            break;
        case "Christophe Mouilleron":
            name = "Si la somme des cartes en jeu est un nombre premier, vous gagnez votre pari, quel que soit le résultat.";
            break;
        case "Djibril-Aurelien Dembele-Cabot":
            name = "Choisissez une carte posée ce tour ci, mettez la de côté. Elle n'est pas comptée dans les sommes relatives aux paris de ce tour. S'il s'agit d'une carte spéciale, son pouvoir ne s'activera pas.";
            break;
        case "Lucienne Pacave":
            name = "Choisissez une carte mise de côté et mettez là devant un adversaire avec les cartes qu'il a joué ce tour-ci. Cette carte est comptée dans les sommes relatives aux paris de sa couleur.";
            break;
        case "Lawanda Gaydu":
            name = "Choisissez une carte mise de côté et mettez là devant vous avec les cartes que vous avez jouées ce tour-ci. Cette carte est comptée dans les sommes relatives aux paris de sa couleur.";
            break;
        case "Mathilde Mougeot":
            name = "Les paris de ce tour rapportent deux fois plus de jetons que prévu.";
            break;
        case "Dimitri Watel":
            name = "La couleur de tous les paris est remplacée par noir.";
            break;
        case "Cyril Benezet":
            name = "La couleur de tous les paris est remplacée par rouge.";
            break;
        case "Marie Szafranski":
            name = ""; // Aucun effet décrit
            break;
        default:
            name = "La couleur de tous les paris est remplacée par multicolore.";
            break;
    }
    
}

//E.3 : distribue 20 jetons à chaque joueur au début de la partie 
void distribute_initial_tokens(board b) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            player p = b->teams[i][j];
            if (p) {
                set_tokens(p, 20);
            }
        }
    }
}

//E.3 : calcule le score de l'équipe en sommant les jetons des joueurs
int get_score_of_team(board b, int team_id) 
{
    if (team_id < 0 || team_id >= 2) 
    {
        return -1;
    }
    int score = 0;
    for (int i = 0; i < 2; i++) {
        player p = b->teams[team_id][i];
        if (p) {
            score += get_tokens(p);
        }
    }
    return score;
}
