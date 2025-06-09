#include "card.h"
#include "constante.h"
#include <stdlib.h>

card cards[TOTAL_CARDS]; // E.2 : Utilisation de la constante TOTAL_CARDS
int card_count = 0;
int card_id = 0;

card create_card() {
    if (card_count >= TOTAL_CARDS) { // E.2 : Utilisation de TOTAL_CARDS
        printf("Erreur : nombre maximum de cartes atteint\n");
        return NULL;
    }
    
    card new_card = malloc(sizeof(struct card_base));
    if (!new_card) return NULL;

    new_card->id = card_id++;
    new_card->value = -1;
    new_card->color = -1; // E.2 : Initialisation de la couleur à -1 (non définie)
    
    cards[card_count] = new_card;
    card_count++;
    return new_card;
}

void free_card(card c) {
    for (int i = 0; i < card_count; i++) {
        if (cards[i] == c) {
            cards[i] = cards[card_count - 1];
            cards[card_count - 1] = NULL;
            card_count--;
            break;
        }
    }
    free(c);
}

int get_card_id(card c) {
    return c->id;
}

card get_card_by_id(int card_id) {
    for (int i = 0; i < card_count; i++) {
        if (cards[i]->id == card_id) {
            return cards[i];
        }
    }
    return NULL;
}

int get_value(card c) {
    return c->value;
}

void set_value(card c, int val) {
    c->value = val;
}

int get_color(card c) { // E.2 : Implémentation de get_color
    return c->color;
}

void set_color(card c, int color) { // E.2 : Implémentation de set_color
    if (color == COLOR_RED || color == COLOR_BLACK) {
        c->color = color;
    }
}