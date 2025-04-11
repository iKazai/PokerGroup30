#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "eval.h"




int main() {
    srand(time(0));
    int n =rand() % 18+3;
    simulate_games(n);
    return -1;
}
