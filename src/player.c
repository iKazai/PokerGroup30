#include <stdlib.h>
#include <stdbool.h>
#include "../include/player.h"

player players[4]; //creation d'un tableau pour stocker les joueurs present sur le plateau 
int player_count = 0; // nb de joueurs présent
int player_id= 0; // initialisation d'un compteur pour attribuer un id unique
player create_player(void){
    if (player_count>=4) return NULL;
    
    player new_player = malloc(sizeof(struct player_base));
    if (!new_player) return NULL;
    
    new_player->deck = NULL;
    new_player->deck_size = 0;
    new_player->laids = NULL;
    new_player->slate = NULL;
    new_player->id = player_id;
    player_id++;
    new_player->team_id = -1;

    players[player_count]=new_player;
    
    player_count++;
    return new_player;
}


void free_player(player p){
    if (p->deck) {
        for (int i = 0; i < p->deck_size; i++) {
            free_card(p->deck[i]);
        }
        free(p->deck);
    }

    if (p->laids) {
        for (int i = 0; i < p->laids_size; i++) {
            free_card(p->laids[i]);
        }
        free(p->laids);
    }

    free(p);
}


int get_player_id(player p){
    return p->id;
}


player get_player_by_id(int player_id){
    for(int i=0;i<player_count;i++){
        if (players[i]->id == player_id){
            return players[i];
        }
    }
    return NULL;
} 


void add_card_to_hand(player p, card c){
    p->deck = realloc(p->deck,(p->deck_size+1)*sizeof(card));//reallouer la memoir car deck_size a changé
    if (p->deck==NULL) return;
    p->deck[p->deck_size] = c;
    p->deck_size++;
}


int get_size_of_hand(player p){
    return p->deck_size;
}


card get_card_in_hand(player p, int card_index){
    if (card_index>=0 && card_index<p->deck_size){
    return p->deck[card_index];
    }
    return NULL;
}


void remove_card_from_hand(player p, card c){
    
    int tmp = -1; // creation d'une variable pour trouver l'indice a laquel est la carte cherchée
    
    for (int i =0; i<p->deck_size;i++){
        if(p->deck[i]->id == c->id ){
            tmp = i;
            break;
        }
    }
    if (tmp == -1) return ;//si la carte n'est pas trouvée
    // free_card(p->deck[tmp]);
    for (int i = tmp; i < p->deck_size-1; i++) { //decaler les cartes après la carte supprimé pour réafecter les indices 
        p->deck[i] = p->deck[i+1];
    }
    p->deck_size--;
    if (p->deck_size == 0){
        free(p->deck);
        p->deck = NULL;
    } else {
        p->deck = realloc(p->deck, p->deck_size * sizeof(card)); //reallouer la memoir car deck_size a changé
        if (p->deck == NULL) return;
    }
}


void play_card(player p, card c){
    
    if (p==NULL || c==NULL) return ;
    if (p->laids_size>=2) return; // 2 cartes maximum sur la table par le joueur

    card* new_laids = realloc(p->laids, (p->laids_size + 1) * sizeof(card));
    if (new_laids == NULL) return;
    
    p->laids = new_laids;
    p->laids[p->laids_size] = c;
    p->laids_size++;
}

int get_number_of_played_cards(player p){
    return p->laids_size;
}


card get_played_card(player p, int card_index){
    if (card_index>=0 && card_index<=1){
        return p->laids[card_index];
    }
    return NULL;
}


void remove_played_card(player p, card c){
    int tmp = -1; // creation d'une variable pour trouver l'indice a laquel est la carte cherchée
    
    for (int i =0; i<p->laids_size;i++){
        if(p->laids[i]->id == c->id ){
        tmp = i;
        }
    }
    if (tmp == -1) return ;//si la carte n'est pas trouvée
    for (int i = tmp; i <p->laids_size-1; i++) { //decaler les cartes après la carte supprimé pour réafecter les indices 
        p->laids[i] = p->laids[i+1];
    }

    p->laids[p->laids_size-1]=NULL;//derniere carte de laids à NULL
    p->laids_size--;

    if (p->laids_size == 0){ // si aucune carte posé 
        free(p->laids);  //libere l'espace alloué
        p->laids = NULL;
    } 
    else{
        p->laids = realloc(p->laids, p->laids_size * sizeof(card));//reallouer la memoire car laids_size a changé
        if (p->laids == NULL) return;
    }
}


int get_slate(player p){
    return p->slate;
}

void set_slate(player p, int bet){
    if (bet == 1){
        p->slate = true; // en supposant que 1 représente Victoire 
    } 
    else{
        p->slate = false; // en supposant que 0 représente Défaite
    }
}
