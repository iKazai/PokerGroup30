#include "interface.h"
#include "board.h"
#include "player.h"
#include "card.h"
#include "constante.h"
#include <stdio.h>


void display_board(board b) {
    for (int i = 0; i < NUM_TEAMS; i++) { // E.2 : Utilisation de NUM_TEAMS
        printf("Équipe %d:\n", b->team_id[i]);
        printf("Score : %d\n", b->score[i]);
        for (int j = 0; j < 2; j++) {
            player p = b->teams[i][j];
            printf("Joueur %d:\n", p->id);
            for (int k = 0; k < p->deck_size; k++) {
                card c = p->deck[k];
                printf("Carte %d : Valeur %d, Couleur %s\n", k, get_value(c),
                       get_color(c) == COLOR_RED ? "Rouge" : "Noir"); // E.2 : Affichage de la couleur
            }
        }
    }
}

int ask_gamble(player p) {
    int gamble;
    int color;

    printf("Joueur %d : Que voulez-vous parier ? (1 pour Victoire, 0 pour Défaite) : ", p->id);
    scanf("%d", &gamble);
    if (gamble != 0 && gamble != 1) {
        printf("Pari invalide. Pari fixé à Défaite (0).\n");
        gamble = 0;
    }

    // E.2 : Demander la couleur pariée
    printf("Joueur %d : Quelle couleur pariez-vous ? (0 pour Rouge, 1 pour Noir, 2 pour Multicolore) : ", p->id);
    scanf("%d", &color);
    if (color < COLOR_RED || color > COLOR_MULTICOLOR) {
        printf("Couleur invalide. Couleur fixée à Multicolore (2).\n");
        color = COLOR_MULTICOLOR;
    }
    set_bet_color(p, color);

}

int ask_number_of_played_cards(player p){
    printf("Joueur %d : Combien de cartes voulez-vous poser ?\n", p->id);
    int number;
    scanf("%d", &number);
    return number;
}

card ask_card(player p){
    printf("Joueur %d : Quelle carte voulez-vous jouer ?\n", p->id);
    int card_index;
    scanf("%d", &card_index);
    return get_card_in_hand(p, card_index);
}

void display_end_game(board b){
    printf("La partie est terminée.\n");
    int winner = b->score[0] > b->score[1] ? b->team_id[0] : b->team_id[1];
    printf("L'équipe gagnante est l'equipe : %d\n", winner);
    return;
}

void display_message(char* message){
    printf("%s\n", message);
    return;
}