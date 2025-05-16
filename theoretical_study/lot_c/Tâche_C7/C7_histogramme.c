#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    FILE *f = fopen("resultats_C6.txt", "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return 1;
    }

    int pioche[] = {1, 1, 2, 2, 3, 3};
    int taille = sizeof(pioche)/sizeof(pioche[0]);
    int n = 10000;

    srand(time(NULL));
    for (int k = 0; k < n; k++) {
        int carte1, carte2;
        main_J1(pioche, taille, &carte1, &carte2);
        if ((carte1 == 1 && carte2 == 2) || (carte1 == 2 && carte2 == 1)) {
            int carteJ2_1, carteJ2_2;
            main_J2(pioche, taille, (int[]){carte1, carte2}, &carteJ2_1, &carteJ2_2);
            fprintf(f, "%d %d\n", carteJ2_1, carteJ2_2);
        }
    }

    fclose(f);
    return 0;
}