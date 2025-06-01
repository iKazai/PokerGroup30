#include "miroir.h"
#include <stdio.h>
#include <stdlib.h>

void paris_aleatoire(player p) {
    if (!p) return;
    p->slate = (rand() % 2) == 0;
}

card find_min_card(player p) {
    if (!p) {
        perror("[find_min_card] : Player is NULL");
        return NULL;
    }
    if (p->deck_size == 0) {
        perror("[find_min_card] : No cards in hand");
        return NULL;
    }

    card minimum = p->deck[0];
    for (int i = 1; i < p->deck_size; i++) {
        if (p->deck[i] && p->deck[i]->value < minimum->value) {
            minimum = p->deck[i];
        }
    }
    return minimum;
}

card find_max_card(player p) {
    if (!p) {
        perror("[find_max_card] : Player is NULL");
        return NULL;
    }
    if (p->deck_size == 0) {
        perror("[find_max_card] : No cards in hand");
        return NULL;
    }

    card maximum = p->deck[0];
    for (int i = 1; i < p->deck_size; i++) {
        if (p->deck[i] && p->deck[i]->value > maximum->value) {
            maximum = p->deck[i];
        }
    }
    return maximum;
}

bool agressive(player p) {
    if (!p || p->deck_size == 0) return false;

    card a = find_min_card(p);
    card b = find_max_card(p);
    if (!a || !b) return false;

    if ((a->value - 1) >= (5 - b->value)) {
        set_slate(p, 1);

        if (p->deck_size == 1) {
            card to_play = p->deck[0];
            play_card(p, to_play);
            remove_card_from_hand(p, to_play);
        } else {
            for (int i = 0; i < 2 && p->deck_size > 0; i++) {
                card to_play = find_max_card(p);
                if (to_play) {
                    play_card(p, to_play);
                    remove_card_from_hand(p, to_play);
                }
            }
        }
        return true;
    } else {
        set_slate(p, 0);
        card to_play = find_min_card(p);
        if (to_play) {
            play_card(p, to_play);
            remove_card_from_hand(p, to_play);
        }
        return false;
    }
}