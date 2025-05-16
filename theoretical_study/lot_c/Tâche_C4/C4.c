#include "C3.c"
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD:theoretical_study/Tache C4/C4.c

int export_approx_1(int n);

=======
#include <stdlib.h>
>>>>>>> b4567dc50abb59b5f5a38cd6d7a67a9617bbe3dc:theoretical_study/C4.c

int export_approx_1(int n) {
    double* approx = P_approx_1_n(n); 
    FILE *file = fopen("probabilites_mains.txt", "w");
    if (file == NULL) {
        perror("Erreur : fichier non créé");
        return -1;
    }
    

    // En-tête CSV
    fprintf(file, "Main;Probabilite\n");


    // Tableau des mains possibles (pour les labels)
    const char* mains[7] = {"1-1", "1-2", "1-3","2-1", "2-2", "2-3", "3-3"};

    // Boucle pour écrire les données
    for (int i = 0; i < 7; i++) {
        fprintf(file, "%s;%f\n", mains[i], approx[i]);
    }


    for (int n = 0; n <100000; n++){
        double P_emp = P_approx_1(1, 2, n);
        fprintf(file, ",,,%d,%f\n", n, P_emp);
    }

    fclose(file);
    free(approx);
    return 0;
}


int main() {
    export_approx_1(100000);
    return 0;  
}

