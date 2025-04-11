// eval.c
#include <stdio.h>
#include <time.h>
#include "miroir.h" // ou antimiroir.h / probabiliste.h
#include "board.h"
#include "player.h"
#include "card.h"
#include <stdlib.h>

void simulate_games(int nb_games) {
    int total_score = 0;
    clock_t start = clock();

    for (int i = 0; i < nb_games; i++) {
        // Crée un plateau
        board b = create_board();
        add_team(b);
        add_team(b);

        // Ajoute 2 joueuses par équipe
        player p0 = create_player();
        player p1 = create_player();
        player p2 = create_player();
        player p3 = create_player();

        add_player_to_team(b, 0, p0);
        add_player_to_team(b, 1, p1);
        add_player_to_team(b, 0, p2);
        add_player_to_team(b, 1, p3);

        // Simule une partie selon ta méthode
        int score = miroir(b); // ou antimiroir(b), probabiliste(b)
        total_score += score;

        // Nettoyage
        free_board(b);
    }

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total score: %d\n", total_score);
    printf("Average score per game: %.2f\n", (double)total_score / nb_games);
    printf("Total time: %.2fs\n", duration);
}
