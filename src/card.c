#include "card.h"

#define MAX_CARDS 20

static card cards[MAX_CARDS]; //creation d'un tableau pour stocker les cartes presente sur le plateau 
static int card_count = 0; // nb de carte présent
static int card_id = 0; // initialisation d'un compteur pour attribuer un id unique

card create_card() {
    if (card_count >= MAX_CARDS) {
        fprintf(stderr, "[create_card] Too many cards allocated\n");
        return NULL;
    }

    card new_card = malloc(sizeof(struct card_base));
    if (!new_card) return NULL;

    new_card->id = card_id++;
    new_card->value = -1;

    cards[card_count++] = new_card;

    return new_card;
}

void free_card(card c) {
    if (!c) return;

    // Trouver la carte dans le tableau
    int found = 0;
    for (int i = 0; i < card_count; i++) {
        if (cards[i] == c) {
            found = 1;
            for (int j = i; j < card_count - 1; j++) {
                cards[j] = cards[j + 1];
            }
            break;
        }
    }

    if (found) {
        card_count--;
        free(c);
    } else {
        fprintf(stderr, "[free_card] Card not found in registry\n");
    }
}

int get_card_id(card c) {
    return c ? c->id : -1;
}

card get_card_by_id(int id) {
    for (int i = 0; i < card_count; i++) {
        if (cards[i]->id == id) {
            return cards[i];
        }
    }
    return NULL;
}

int get_value(card c) {
    return c ? c->value : -1;
}

void set_value(card c, int val) {
    if (c) c->value = val;
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