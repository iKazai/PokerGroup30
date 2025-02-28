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
    return;
}

void display_message(char* message){
    printf("%s\n", message);
    return;
}