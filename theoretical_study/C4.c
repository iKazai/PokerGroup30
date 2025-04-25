#include "C:\Users\crisd\OneDrive\PokerGroup30\theoretical_study\C3.c"

int export_approx_1(int n){
    double* approx = P_approx_1_n(n);
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        perror("[export_approx_1] : Fichier invalide");
        return -1;
    }

    for (int i = 0; i < 6; i++) {
        fprintf(file, "%f\n", approx[i]);
    }

    fclose(file);
    return 0;
}

