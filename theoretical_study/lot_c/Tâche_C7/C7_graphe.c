#include "C6.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    FILE *f = fopen("convergence_resultats.txt", "w");
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    srand(time(NULL)); 

    int N = 100000;
    for (int n = 1; n <= N; n++)
    {
        double estimation = P_approx_2_1_main(2, 3, 1, 2, n);
        fprintf(f, "%d %f\n", n, estimation);
    }

    fclose(f);

    printf("Fichier convergence_resultats.txt créé avec succès.\n");
    return 0;
}