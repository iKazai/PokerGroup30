#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C10.c"

int main() {
    int n = 100000;
    srand(time(NULL));

    //utilisation fonctions
    double* b = P_approx_2(n);
    double* a = P_approx_2_alter(n);

    //CSV
    FILE *f1 = fopen("P_empirique.csv", "w");
    FILE *f2 = fopen("P_empirique_alter.csv", "w");
    FILE *f3 = fopen("P_theorique.csv", "w");//apres c8 fini (j'ai pas fini les calculs )

    for (int i = 1; i <= 3; i++) {
        fprintf(f1, "%d,%d,%.6f\n", i, b[i]);
        fprintf(f2, "%d,%d,%.6f\n", i, a[i]);
        //fprintf(f3, "%d,%d,%.6f\n", i, ); pour theorique
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("fin\n");

    return 0;
}