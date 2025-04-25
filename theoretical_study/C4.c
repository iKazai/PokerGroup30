#include "C3.c"
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
=======
>>>>>>> 9d8c42cb9ae32f4f7a7e71895b927af4ba340913

int export_approx_1(int n) {
    double* approx = P_approx_1_n(n); 
    FILE *file = fopen("probabilites_mains.txt", "w");
    if (file == NULL) {
        perror("Erreur : fichier non créé");
        return -1;
    }
    

    // En-tête CSV
    fprintf(file, "Main;Probabilite\n");


    double P_theo[6] = {1.0/3, 2.0/3, 2.0/3, 2.0/3, 4.0/15, 1.0/15};
    // Tableau des mains possibles (pour les labels)
    const char* mains[6] = {"1-1", "1-2", "1-3","2-1", "2-2", "2-3", "3-3"};

    // Boucle pour écrire les données
    for (int i = 0; i < 7; i++) {
        fprintf(file, "%s;%f\n", mains[i], approx[i]);
    }

    for (int n = 1; n <= 100000; n += 1000) {
        double P_emp = P_approx_1_main(1, 2, n);
        fprintf(file, ",,,%d,%f\n", n, P_emp);
    }

    fclose(file);
    free(approx);
    return 0;
}


int main() {
    int result = export_approx_1(100000);  // Exemple avec n = 100000
    if (result == 0) {
        printf("Fichier CSV généré avec succès !\n");
    } else {
        printf("Échec de la génération du CSV.\n");
    }
    return 0;
}

