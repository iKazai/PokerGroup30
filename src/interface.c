#include "interface.h"
#include "board.h"
#include "player.h"
#include "card.h"
#include <stdio.h>

void display_card(card c){
    printf("ID de la carte : %d\n
        Valeur de la carte : %d\n", c->id, c->value);
    return;
}

void display_board(board b){
    for(int i = 0; i < 4; i++){
        printf("Le joueur %d:\n",b->p[i]);
        printf("Cartes en main : ");
        for(int j = 0; j < b->p[i]->deck_size; i++){
            printf("Carte %d : %d \n", j, get_value(b->p[i]->deck[j]));
        }

    }
    return;
}

int ask_gamble(player p){
    printf("Combien voulez-vous miser ?\n");
    int gamble;
    scanf("%d", &gamble);
    return gamble;
}

int ask_number_of_played_cards(player p){
    printf("Combien de cartes voulez-vous poser ?\n");
    int number;
    scanf("%d", &number);
    return number;
}

card ask_card(player p){
    printf("Quelle carte voulez-vous jouer ?\n");
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