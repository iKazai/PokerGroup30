#include <stdio.h>
#include <stdlib.h>
#include "probabiliste.h"

int sum_played_cards_1(board b, int team_id) {
    int sum = 0;
    int nb_players = get_number_of_players_in_team(b, team_id);
    for (int i = 0; i < nb_players; i++) {
        player p = get_player(b, team_id, i);
        int nb_played = get_number_of_played_cards(p);
        for (int j = 0; j < nb_played; j++) {
            card c = get_played_card(p, j);
            sum += get_value(c);
        }
    }
    return sum;
}

void apply_points_1(board b, player players[2][2], int s0, int s1) {
    int winning_team = (s0 > s1) ? 0 : ((s1 > s0) ? 1 : -1);

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            int slate = get_slate(players[t][p]);
            if (winning_team == t && slate == 1) {
                add_point_to_team(b, t);
            } else if (winning_team != -1 && winning_team != t && slate == 0) {
                add_point_to_team(b, t);
            }
        }
    }
}

void free_all_cards_1(player p) {
    while (get_size_of_hand(p) > 0) {
        card c = get_card_in_hand(p, 0);
        remove_card_from_hand(p, c);
        destroy_card(c);
    }
}

void free_all_card_1(player p) {
    while (get_number_of_played_cards(p) > 0) {
        card c = get_played_card(p, 0);
        remove_played_card(p, c);
        destroy_card(c);
    }
}

int partie_1(int n) {
    board b = create_board();
    player players[2][2];

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            players[t][p] = create_player(100 * t + p);
            add_player_to_team(b, t, players[t][p]);
        }
    }

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            for (int i = 0; i < n; i++) {
                card c = create_card();
                if (c) {
                    set_value(c, (rand() % 2) + 1);
                    add_card_to_hand(players[t][p], c);
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        probabiliste(players[0][0], b);
        agressive(players[0][1], b);
        agressive(players[1][0], b);
        agressive(players[1][1], b);
    }

    int s0 = sum_played_cards_1(b, 0);
    int s1 = sum_played_cards_1(b, 1);
    apply_points_1(b, players, s0, s1);

    int result = (get_team_score(b, 0) > get_team_score(b, 1)) ? 1 : 0;

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            free_all_cards_1(players[t][p]);
            free_all_card_1(players[t][p]);
            destroy_player(players[t][p]);
        }
    }
    return result;
}

int partie_2(int n) {
    board b = create_board();
    player players[2][2];

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            players[t][p] = create_player();
            add_player_to_team(b, t, players[t][p]);
        }
    }

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            for (int i = 0; i < 5; i++) {
                card c = create_card();
                if (c) {
                    set_value(c, (rand() % 2) + 1);
                    add_card_to_hand(players[t][p], c);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        probabiliste(players[0][0], b);
        agressive(players[0][1], b);
        agressive(players[1][0], b);
        agressive(players[1][1], b);
    }

    int s0 = sum_played_cards_1(b, 0);
    int s1 = sum_played_cards_1(b, 1);
    apply_points_1(b, players, s0, s1);

    int result = (get_team_score(b, 0) > get_team_score(b, 1)) ? 1 : 0;

    for (int t = 0; t < 2; t++) {
        for (int p = 0; p < 2; p++) {
            free_all_cards_1(players[t][p]);
            free_all_card_1(players[t][p]);
            destroy_player(players[t][p]);
        }
    }
    return result;
}
