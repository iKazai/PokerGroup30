#include "eval.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void simulate_games(int num_games, int num_rounds) {
    srand(time(NULL));  // Initialisation du générateur aléatoire

    clock_t start = clock();
    int count_win = 0;

    for (int game = 0; game < num_games; game++) {
        int total_score0 = 0;
        int total_score1 = 0;

        board b = create_board();
        if (!b) {
            perror("[simulate_games] : The board is null\n");
            exit(EXIT_FAILURE);
        }
        add_team(b);

        player p0 = create_player();
        player p1 = create_player();
        player p2 = create_player();
        player p3 = create_player();

        add_player_to_team(b, 0, p0);
        add_player_to_team(b, 1, p1);
        add_player_to_team(b, 0, p2);
        add_player_to_team(b, 1, p3);

        for (int round = 0; round < num_rounds; round++) {
            // Distribution aléatoire de cartes à chaque joueur
            for (int team = 0; team < 2; team++) {
                for (int j = 0; j < 2; j++) {
                    for (int card_index = 0; card_index < 2; card_index++) {
                        card c = create_card();
                        if (!c) {
                            fprintf(stderr, "Erreur: Impossible de créer une carte\n");
                            exit(EXIT_FAILURE);
                        }
                        set_value(c, rand() % 2 + 1);
                        add_card_to_hand(b->teams[team][j], c);
                    }
                }
            }

            // Phase de pari
            paris_aleatoire(p0);
            paris_aleatoire(p1);
            paris_aleatoire(p2);
            paris_aleatoire(p3);

            // Synchronisation d’un pari
            int a = get_slate(p0);
            set_slate(p2, a);

            // Phase d’action (joue une carte)
            agressive(p0);
            agressive(p1);
            agressive(p2);
            agressive(p3);

            // Calcul des valeurs de chaque équipe
            int val0 = 0;
            int val1 = 0;
            for (int j = 0; j < get_number_of_players_in_team(b, 0); j++) {
                player pl = b->teams[0][j];
                for (int k = 0; k < pl->laids_size; k++) {
                    val0 += get_value(pl->laids[k]);
                }
            }
            for (int j = 0; j < get_number_of_players_in_team(b, 1); j++) {
                player pl = b->teams[1][j];
                for (int k = 0; k < pl->laids_size; k++) {
                    val1 += get_value(pl->laids[k]);
                }
            }

            // Attribution des points selon les paris
            if (val0 > val1) {
                for (int i = 0; i < get_number_of_players_in_team(b, 0); i++) {
                    if (get_slate(b->teams[0][i]) == 1)
                        b->score[0]++;
                }
                for (int i = 0; i < get_number_of_players_in_team(b, 1); i++) {
                    if (get_slate(b->teams[1][i]) == 0)
                        b->score[1]++;
                }
            } else if (val0 < val1) {
                for (int i = 0; i < get_number_of_players_in_team(b, 0); i++) {
                    if (get_slate(b->teams[0][i]) == 0)
                        b->score[0]++;
                }
                for (int i = 0; i < get_number_of_players_in_team(b, 1); i++) {
                    if (get_slate(b->teams[1][i]) == 1)
                        b->score[1]++;
                }
            }

            // Libération des cartes de ce round
            for (int team = 0; team < 2; team++) {
                for (int j = 0; j < 2; j++) {
                    player pl = b->teams[team][j];

                    // Laids
                    for (int k = 0; k < pl->laids_size; k++) {
                        free_card(pl->laids[k]);
                    }
                    free(pl->laids);
                    pl->laids = calloc(2, sizeof(card));
                    pl->laids_size = 0;

                    // Deck
                    for (int k = 0; k < pl->deck_size; k++) {
                        free_card(pl->deck[k]);
                    }
                    free(pl->deck);
                    pl->deck = calloc(4, sizeof(card));
                    pl->deck_size = 0;
                }
            }
        }

        total_score0 = get_score_of_team(b, 0);
        total_score1 = get_score_of_team(b, 1);
        if (total_score0 > total_score1) {
            count_win++;
        }

        // Libération mémoire
        free_player(p0);
        free_player(p1);
        free_player(p2);
        free_player(p3);
        free_board(b);
    }

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Nombre de parties gagnées par l'équipe 0 : %d\n", count_win);
    printf("Pourcentage de victoires : %.2f%%\n", 100.0 * count_win / num_games);
    printf("Durée totale : %.2fs\n", duration);
}