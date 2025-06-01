#include "../include/card.h"
#include <stdlib.h>

#define MAX_CARDS 20

static card cards[MAX_CARDS];
static int card_count = 0;
static int card_id = 0;

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