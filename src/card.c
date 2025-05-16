#include "card.h"

card cards[20]; //creation d'un tableau pour stocker les cartes presente sur le plateau 
int card_count = 0; // nb de carte présent
int card_id = 0; // initialisation d'un compteur pour attribuer un id unique

card create_card(){
    if (card_count>=20){
    printf("erreur");
    return NULL;
    }
    
    card new_card = malloc(sizeof(struct card_base));
    if (!new_card) return NULL;

    new_card->id=card_id;
    card_id++;
    new_card->value=-1;
    
    cards[card_count]=new_card;
    
    card_count++;
    return new_card;
}

void free_card(card c){
    for (int i = 0; i < card_count; i++) {
        if (cards[i] == c) {
            cards[i] = cards[card_count - 1];
            cards[card_count - 1] = NULL;
            card_count--;
            break;
        }
    }
    free(c);
    card_count--;
}

int get_card_id(card c){
    return c->id;
}

card get_card_by_id(int card_id){
    for(int i=0;i<card_count;i++){
        if (cards[i]->id == card_id){
            return cards[i];
        }
    }
    return NULL;
}

int get_value(card c){
    return c->value;
}

void set_value(card c , int val){
    c->value=val;
}





/*************** AJout du lot_e ***************/


void free_card(card sc){
    if(sc->is_special){
        free(sc->name);
        free(sc->desc);
    }
    free(sc);
    return;
}

char* get_special_card_name(card sc){
    if(!sc->is_special){
        perror("[get_special_card_name] : The card is not special.");
        return;
    }
    char* n = sc->name;
    printf("Carte spéciale %d: %s\n",sc->id, n);
    return n;
}

void display_special_card_desc(card sc){
    if(!sc->is_special){
        perror("[display_special_card_desc] : The card is not special.");
        return;
    }
    printf("Carte spéciale: %d: %s\n",sc->id, sc->desc);
    return;
}