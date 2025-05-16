#include "interface.h"
#include "board.h"
#include "player.h"
#include "card.h"
#include <stdio.h>

void display_card(card c){
    printf("ID de la carte : %d\n Valeur de la carte : %d\n", c->id, c->value);
    return;
}

void display_board(board b){
    for(int i = 0; i < 2; i++){
        printf("L'équipe %d:\n", b->team_id[i]);
        printf("Score : %d\n", b->score[i]);
        for(int j = 0; j < 2; j++){
            printf("Le joueur %d:\n", b->teams[i][j]->id);
            for (int k = 0; k < b->teams[i][j]->deck_size; k++){
                printf("Carte %d : %d \n", k, get_value(b->teams[i][j]->deck[k]));
            }
                
        }
    }
    return;
}

//E.3 : demande au joueur son pari (Victoire/Défaite) et le nombre de jetons à miser
int ask_gamble(player p) {
    int gamble;
    int tokens;

    printf("Joueur %d : Que voulez-vous parier ? (1 pour Victoire, 0 pour Défaite) : ", p->id);
    scanf("%d", &gamble);
    if (gamble != 0 && gamble != 1) {
        printf("Pari invalide. Pari fixé à Défaite (0).\n");
        gamble = 0;
    }

    //E3 : demander le nombre de jetons à miser
    printf("Joueur %d : Combien de jetons voulez-vous miser ? (minimum 1, vous avez %d jetons) : ", p->id, get_tokens(p));
    scanf("%d", &tokens);
    if (tokens < 1 || tokens > get_tokens(p)) {
        printf("Mise invalide. Mise fixée à 1 jeton.\n");
        tokens = 1;
    }

    //E3 : enregistrer la mise et retirer les jetons
    set_current_bet(p, tokens);
    remove_tokens(p, tokens);

    return gamble;
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

//E.3 : affiche le nombre de jetons de chaque joueur 
void display_tokens(board b) {
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        player p = b->teams[i][j];
        printf("Joueur %d (Équipe %d) : %d jetons\n", p->id, b->team_id[i], get_tokens(p));
    }
}
}