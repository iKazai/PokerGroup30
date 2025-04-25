#include "C:\Users\crisd\OneDrive\PokerGroup30\theoretical_study\C3.c"

int export_approx_1(int n) {
    double* approx = P_approx_1_n(n); 
    FILE *file = fopen("probabilites_mains.csv", "w");
    if (file == NULL) {
        perror("Erreur : fichier non créé");
        return -1;
    }

    // En-tête CSV
    fprintf(file, "Main;Probabilite\n");

    // Tableau des mains possibles (pour les labels)
    const char* mains[6] = {"1-1", "1-2", "1-3", "2-2", "2-3", "3-3"};

    // Boucle pour écrire les données
    for (int i = 0; i < 6; i++) {
        fprintf(file, "%s;%f\n", mains[i], approx[i]);
    }

    fclose(file);
    free(approx);
    return 0;
}

