#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Représentation des mains possibles de J2 après la main (1,3) de J1
int mains_J2[6][2] = {
    {1, 1}, {1, 2}, {1, 3}, {2, 2}, {2, 3}, {3, 3}
};

// Probabilité que J2 parie (V) en fonction de sa main
double proba_pari_J2(int c1, int c2) {
    if ((c1 == 1 && c2 == 1)) return 0.1;
    if ((c1 == 1 && c2 == 2)) return 0.3;
    if ((c1 == 1 && c2 == 3)) return 0.6;
    if ((c1 == 2 && c2 == 2)) return 0.4;
    if ((c1 == 2 && c2 == 3)) return 0.8;
    if ((c1 == 3 && c2 == 3)) return 0.9;
    return 0.5;
}

// Simule une manche et retourne les gains sous forme de tableau
void simulate_one_game(double p1, int* g1, int* g2) {
    // Main fixée de J1
    int j1_low = 1;
    int j1_high = 3;

    // Tirage d’une main possible pour J2
    int k = rand() % 6;
    int j2_low = mains_J2[k][0];
    int j2_high = mains_J2[k][1];

    // Détermination du pari de J1
    int pari_j1 = ((double) rand() / RAND_MAX) < p1;

    // Détermination du pari de J2 selon sa main
    double q = proba_pari_J2(j2_low, j2_high);
    int pari_j2 = ((double) rand() / RAND_MAX) < q;

    // Cartes jouées selon le pari
    int carte_j1 = pari_j1 ? j1_high : j1_low;
    int carte_j2 = pari_j2 ? j2_high : j2_low;

    // Calcul des gains
    *g1 = 0;
    *g2 = 0;
    if (pari_j1 && carte_j1 > carte_j2) (*g1)++;
    if (!pari_j1 && carte_j1 < carte_j2) (*g1)++;
    if (pari_j2 && carte_j2 > carte_j1) (*g2)++;
    if (!pari_j2 && carte_j2 < carte_j1) (*g2)++;
}

// Simulation Monte Carlo
void monte_carlo(int n, double p1) {
    int sum_g1 = 0, sum_g2 = 0;
    for (int i = 0; i < n; i++) {
        int g1, g2;
        simulate_one_game(p1, &g1, &g2);
        sum_g1 += g1;
        sum_g2 += g2;
    }

    printf("Résultats sur %d simulations avec p1 = %.2f\n", n, p1);
    printf("Espérance de gain J1 : %.4f\n", (double) sum_g1 / n);
    printf("Espérance de gain J2 : %.4f\n", (double) sum_g2 / n);
}

int main() {
    srand(time(NULL));
    monte_carlo(100000, 0.6);   
    return 0;
}