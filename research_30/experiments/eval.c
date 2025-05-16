// eval.c

#include "eval.h"


void simulate_games(int n) {
    clock_t start = clock();
    int count_win = 0;
    for (int i=0;i<20;i++){ //20 parties
        int total_score0 = 0;
        int total_score1 = 0;
        
        board b = create_board();
        if(!b){
            perror("[simulate_games] : The board is null\n");
            exit(1);
        }
        add_team(b);

        player p0 = create_player();
        player p1 = create_player();
        player p2 = create_player();
        player p3 = create_player();

        add_player_to_team(b, 0, p0);
        add_player_to_team(b, 1, p1);
        add_player_to_team(b, 0, p2);
        add_player_to_team(b, 1, p3);
        for (int o = 0; o < n; o++) {// n tours 
            for(int k=0;k<2;k++){ // 4 joueurs
                for (int l = 0; l < 2; l++) { //l equipes
                    for (int j = 0; j < 2; j++) { //joueur j de l'equipe l
                        card c = create_card();
                        if (!c) {
                            fprintf(stderr, "Erreur: Impossible de créer une carte\n");
                            exit(EXIT_FAILURE);
                        }
                        set_value(c,rand() % 2 + 1);
                        add_card_to_hand(b->teams[l][j],c);
                    }
                }
            }
            
            paris_aleatoire(p0);
            paris_aleatoire(p1);
            paris_aleatoire(p2);
            paris_aleatoire(p3);
            
            int a = get_slate(p0);
            
            set_slate(p2,a);
            agressive(p0);
            agressive(p1);
            agressive(p2);
            agressive(p3);
            
            int val0 = 0;
            int val1 = 0;
            for (int j=0; j<get_number_of_players_in_team(b,0);j++){
                for (int i=0; i<b->teams[0][j]->laids_size;i++){
                    val0 += get_value(b->teams[0][j]->laids[i]);
                }
            }
            for (int j=0; j<get_number_of_players_in_team(b,1);j++){
                for (int i=0; i<b->teams[1][j]->laids_size;i++){
                    val1 += get_value(b->teams[1][j]->laids[i]);
                }
            }
            if(val0>val1){
                for(int i=0;i<get_number_of_players_in_team(b,0);i++ ){
                    if(get_slate(b->teams[0][i])==1){
                        b->score[0]+=1;
                    }
                    else if (get_slate(b->teams[1][i])==0){
                        b->score[1]+=1;
                    }
                }     
            }
            if(val0<val1){
                for(int i=0;i<get_number_of_players_in_team(b,0);i++ ){
                    if(get_slate(b->teams[0][i])==0){
                        b->score[0]+=1;
                    }
                    else if (get_slate(b->teams[1][i])==1){
                        b->score[1]+=1;
                    }
                }  
            }
            //free toutes les cartes sur le plateau et en main
            for (int l = 0; l < 2; l++) { //l equipes
                for (int j = 0; j < 2; j++) { //joueur j de l'equipe l
                    for (int k = 0; k < b->teams[l][j]->deck_size; k++) {
                        free_card(b->teams[l][j]->deck[k]);
                    }
                    for (int k = 0; k < b->teams[l][j]->laids_size; k++) {
                        printf("b->teams[l][j]->laids[k] %p ",b->teams[l][j]->laids[k]);
                        printf("b->teams[l][j]->laids %p ",b->teams[l][j]->laids);
                        printf("b->teams[l][j] %p ",b->teams[l][j]);
                        printf("j: %d k %d l %d teams[l][j]->laids_size %d\n",j,k,l,b->teams[l][j]->laids_size);
                        printf("-------TEst--------\n");
                        fflush(stdout);
                        free_card(b->teams[l][j]->laids[k]);
                    }
                } 
            }
        }
        
        total_score0 += get_score_of_team(b,0);
        total_score1 += get_score_of_team(b,1);
        if(total_score0>total_score1){
            count_win+=1;
        }
        free_board(b);
    }


    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total score: %d\n", count_win);
    printf("Average score per game: %.2f\n", (double)count_win / n);
    printf("Total time: %.2fs\n", duration);
    
}
