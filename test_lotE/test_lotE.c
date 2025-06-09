#include <stdio.h>
#include "player.h"
#include "card.h"
#include "board.h"

void test_gain_si_pari_reussi() {
    player p = create_player();
    set_slate(p, 1); // pari réussi
    int score = 0;

    if (get_slate(p) == 1) score++;

    if (score == 1) {
        printf("[OK] Gain en cas de pari réussi.\n");
    } else {
        printf("[ERREUR] Gain en cas de pari réussi.\n");
    }
    free_player(p);
}

void test_perte_si_pari_rate() {
    player p = create_player();
    set_slate(p, 0); // pari raté
    int score = 0;

    if (get_slate(p) == 0) score--;

    if (score == -1) {
        printf("[OK] Perte en cas de pari raté.\n");
    } else {
        printf("[ERREUR] Perte en cas de pari raté.\n");
    }
    free_player(p);
}

void test_equilibre_rouge_noir() {
    int rouge = 0, noir = 0;

    for (int i = 0; i < 100; i++) {
        card c = create_card();
        int val = get_value(c);
        if (val == 1) rouge++;
        else noir++;
        free_card(c);
    }

    float ratio = (float)rouge / (rouge + noir);
    if (ratio > 0.4 && ratio < 0.6) {
        printf("[OK] Equilibre rouge/noir à la création des cartes.\n");
    } else {
        printf("[ERREUR] Mauvais équilibre rouge/noir : %.2f\n", ratio);
    }
}

void test_effet_thuy_vo() {
    card c = create_card();
    set_value(c, 2);
    set_special(c, 1); // Carte spéciale active
    int effet = get_special(c);

    if (effet == 1) {
        printf("[OK] Carte spéciale Thuy Vo activée correctement.\n");
    } else {
        printf("[ERREUR] Carte spéciale Thuy Vo non activée.\n");
    }
    free_card(c);
}

int main() {
    printf("\n=== Début des tests du Lot E ===\n\n");
    test_gain_si_pari_reussi();
    test_perte_si_pari_rate();
    test_equilibre_rouge_noir();
    test_effet_thuy_vo();
    printf("\n=== Fin des tests Lot E. ===\n");
    return 0;
}