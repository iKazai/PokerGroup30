#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "eval.h"
#include "miroir.h"





int main() {
    srand(time(0));
    int n =rand() % 18+3;
    simulate_games(n);
    printf("test");
    fflush(stdout);
    return -1;
}
