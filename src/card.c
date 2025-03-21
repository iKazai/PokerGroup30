#include "card.h"

card cards[19]; //creation d'un tableau pour stocker les cartes presente sur le plateau 
int card_count = 0; // nb de carte présent
int card_id = 0; // initialisation d'un compteur pour attribuer un id unique

card create_card(){
    if (card_count>=20) return NULL;
    
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
    free(c);
}

