#include <stdlib.h>
#include "miroir.h"


bool paris_aleatoire(){
    return rand() % 2 == 0;
}


int find_min_card_value(player p){
    if (p->deck_size == 0) return -1; 
    int min_value = 1000;
    for (int i = 0; i < p->deck_size; i++) {
        if (p->deck[i]->value < min_value) {
            min_value = p->deck[i]->value;
        }
    }
    return min_value;
}

int find_max_card_value(player p){
    if (p->deck_size == 0) return -1;   
    int max_value = -1;
    for (int i = 0; i < p->deck_size; i++) {
        if (p->deck[i]->value > max_value) {
            max_value = p->deck[i]->value;
        }
    }
    return max_value;
}


bool agressive(player p){
    int a = find_min_card_value(p);
    int b = find_max_card_value(p);
    if (a - 1 >= 5 - b) {
        return true;
    } else {
        return false;
    }
}

