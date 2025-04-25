#include <stdlib.h>
#include "miroir.h"


void paris_aleatoire(player p){
    p->slate = (rand() % 2) == 0;
    return;
}


card find_min_card(player p){
    if (p->deck_size == 0) return NULL; 
    card minimum = p->deck[0];
    for (int i = 1; i < p->deck_size - 1; i++) {
        if (p->deck[i]->value < minimum->value) {
            minimum = p->deck[i];
        }
    }
    return minimum;
}

card find_max_card(player p){
    if (p->deck_size == 0) return NULL; 
    card maximum = p->deck[0];
    for (int i = 1; i < p->deck_size - 1; i++) {
        if (p->deck[i]->value > maximum->value) {
            maximum = p->deck[i];
        }
    }
    return maximum;
}


bool agressive(player p){
    card a = find_min_card_value(p);
    card b = find_max_card_value(p);
    if ((a->value) - 1 >= 5 - (b->value)) {
        set_slate(p,1);
        if(p->deck_size==1){
            play_card(p,p->deck[0]);
            remove_card_from_hand(p,p->deck[0]);
            return true;
        }
        else{
            card max_card = find_max_card_value(p);
            play_card(p,max_card);
            remove_card_from_hand(p,max_card);
            max_card = find_max_card_value(p);
            play_card(p,max_card);
            remove_card_from_hand(p,max_card);
            return true;
        }
    } else {
        set_slate(p,0);
        card min_card = find_min_card_value(p);
        play_card(p,min_card);
        remove_card_from_hand(p,min_card);
        return false;
    }
}

