
#include "miroir.h"


void paris_aleatoire(player p){
    p->slate = (rand() % 2) == 0;
    return;
}


card find_min_card(player p){
    if (p->deck_size == 0){
        perror("[find_min_card] : No cards in hand");
        return NULL;
    }
    if (!p) {
        perror("[find_min_card] : Player is NULL");
        return NULL;
    }
    card minimum = p->deck[0];
    for (int i = 1; i < p->deck_size; i++) {
        if (p->deck[i] !=NULL){
            printf("////////////value %d\n\n",p->deck[i]->value);
            if (p->deck[i]->value < minimum->value) {
                minimum = p->deck[i];
        }
        }
    }
    return minimum;
}

card find_max_card(player p){
    if (p->deck_size == 0){
        perror("[find_max_card] : No cards in hand");
        return NULL;
    }
    if (!p) {
        perror("[find_max_card] : Player is NULL");
        return NULL;
    }
    card maximum = p->deck[0];
    for (int i = 1; i < p->deck_size; i++) {
        if (p->deck[i] !=NULL){
            if (p->deck[i]->value > maximum->value) {
                maximum = p->deck[i];
        }
    }
    }
    return maximum;
}


bool agressive(player p){
    card a = find_min_card(p);
    card b = find_max_card(p);
    if ((a->value) - 1 >= 5 - (b->value)) {
        set_slate(p,1);
        if(p->deck_size==1){
            play_card(p,p->deck[0]);
            remove_card_from_hand(p,p->deck[0]);
            return true;
        }
        else{
            card max_card = find_max_card(p);
            play_card(p,max_card);
            remove_card_from_hand(p,max_card);
            max_card = find_max_card(p);
            play_card(p,max_card);
            remove_card_from_hand(p,max_card);
            return true;
        }
    } else {
        set_slate(p,0);
        card min_card = find_min_card(p);
        play_card(p,min_card);
        remove_card_from_hand(p,min_card);
        return false;
    }
}

