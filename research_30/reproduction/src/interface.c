    #include "../include/interface.h"
    #include <stdio.h>


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

    int ask_gamble(player p){
        printf("Joueur %d : Que voulez-vous parier ?\n", p->id);
        int gamble;
        scanf("%d", &gamble);
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