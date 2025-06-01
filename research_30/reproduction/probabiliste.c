#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/board.h"
#include "../../include/player.h"
#include "../../include/card.h"

/**
 * \brief Calcule la valeur moyenne des cartes jouées et mises de côté.
 * \param b Le plateau de jeu.
 * \param current_player_id ID du joueur qui fait le calcul.
 * \return La valeur moyenne des cartes observables.
 */
static float calculate_average_value(board b, int current_player_id) {
    int total_value = 0;
    int card_count = 0;
    int current_team = -1;
    
    // Trouver l'équipe du joueur actuel
    int num_teams = get_number_of_teams(b);
    for (int t = 0; t < num_teams && current_team == -1; t++) {
        int num_players = get_number_of_players_in_team(b, t);
        for (int p = 0; p < num_players; p++) {
            player pl = get_player(b, t, p);
            if (get_player_id(pl) == current_player_id) {
                current_team = t;
                break;
            }
        }
    }
    
    // Compter les cartes mises de côté
    int out_cards = get_number_of_out_of_game_cards(b);
    for (int i = 0; i < out_cards; i++) {
        card c = get_out_of_game_card(b, i);
        total_value += get_value(c);
        card_count++;
    }
    
    // Compter les cartes jouées par tous les joueurs
    for (int t = 0; t < num_teams; t++) {
        int num_players = get_number_of_players_in_team(b, t);
        for (int p = 0; p < num_players; p++) {
            player pl = get_player(b, t, p);
            
            // Ne pas compter les cartes du joueur actuel
            if (get_player_id(pl) == current_player_id) {
                continue;
            }
            
            int played_cards = get_number_of_played_cards(pl);
            for (int c = 0; c < played_cards; c++) {
                card played_card = get_played_card(pl, c);
                total_value += get_value(played_card);
                card_count++;
            }
        }
    }
    
    // S'il n'y a pas de cartes, utiliser une valeur par défaut (moyenne des valeurs possibles)
    return (card_count > 0) ? ((float)total_value / card_count) : 3.0f;
}

/**
 * \brief Trouve l'indice de la carte avec la plus grande valeur dans la main.
 * \param p Le joueur dont on examine la main.
 * \return L'indice de la carte avec la plus grande valeur.
 */
static int find_highest_card_index(player p) {
    int hand_size = get_size_of_hand(p);
    if (hand_size == 0) return -1;
    
    int highest_index = 0;
    int highest_value = get_value(get_card_in_hand(p, 0));
    
    for (int i = 1; i < hand_size; i++) {
        int current_value = get_value(get_card_in_hand(p, i));
        if (current_value > highest_value) {
            highest_value = current_value;
            highest_index = i;
        }
    }
    
    return highest_index;
}

/**
 * \brief Trouve l'indice de la carte avec la plus petite valeur dans la main.
 * \param p Le joueur dont on examine la main.
 * \return L'indice de la carte avec la plus petite valeur.
 */
static int find_lowest_card_index(player p) {
    int hand_size = get_size_of_hand(p);
    if (hand_size == 0) return -1;
    
    int lowest_index = 0;
    int lowest_value = get_value(get_card_in_hand(p, 0));
    
    for (int i = 1; i < hand_size; i++) {
        int current_value = get_value(get_card_in_hand(p, i));
        if (current_value < lowest_value) {
            lowest_value = current_value;
            lowest_index = i;
        }
    }
    
    return lowest_index;
}

/**
 * \brief Trouve les indices des deux meilleures cartes dans la main.
 * \param p Le joueur dont on examine la main.
 * \param first_index Pointeur pour stocker l'indice de la meilleure carte.
 * \param second_index Pointeur pour stocker l'indice de la deuxième meilleure carte.
 * \return true si deux cartes ont été trouvées, false sinon.
 */
static bool find_two_best_cards(player p, int *first_index, int *second_index) {
    int hand_size = get_size_of_hand(p);
    if (hand_size < 2) return false;
    
    *first_index = 0;
    *second_index = 1;
    
    int first_value = get_value(get_card_in_hand(p, *first_index));
    int second_value = get_value(get_card_in_hand(p, *second_index));
    
    // Ensure first is higher than second
    if (first_value < second_value) {
        int temp = *first_index;
        *first_index = *second_index;
        *second_index = temp;
        
        int temp_val = first_value;
        first_value = second_value;
        second_value = temp_val;
    }
    
    // Find the two highest cards
    for (int i = 2; i < hand_size; i++) {
        int current_value = get_value(get_card_in_hand(p, i));
        
        if (current_value > first_value) {
            *second_index = *first_index;
            second_value = first_value;
            *first_index = i;
            first_value = current_value;
        } else if (current_value > second_value) {
            *second_index = i;
            second_value = current_value;
        }
    }
    
    return true;
}

/**
 * \brief Stratégie probabiliste pour prendre une décision de jeu.
 * 
 * Calcule la valeur moyenne des cartes visibles (jouées et mises de côté),
 * puis compare cette moyenne aux cartes dans la main du joueur pour décider
 * d'un pari et des cartes à jouer.
 *
 * \param p Le joueur qui doit prendre une décision.
 * \param b Le plateau de jeu actuel.
 * \return Le pari fait (0 pour Défaite, 1 pour Victoire).
 */
int probabiliste(player p, board b) {
    int player_id = get_player_id(p);
    float avg_value = calculate_average_value(b, player_id);
    int hand_size = get_size_of_hand(p);
    
    // Si pas de cartes en main, parier Défaite par défaut
    if (hand_size == 0) {
        set_slate(p, 0);
        return 0;
    }
    
    // Vérifier si on peut dépasser la moyenne avec une ou deux cartes
    if (hand_size >= 2) {
        int first_index, second_index;
        if (find_two_best_cards(p, &first_index, &second_index)) {
            int first_value = get_value(get_card_in_hand(p, first_index));
            int second_value = get_value(get_card_in_hand(p, second_index));
            
            // Si la somme des deux meilleures cartes dépasse deux fois la moyenne
            if (first_value + second_value > 2 * avg_value) {
                // Parier Victoire
                set_slate(p, 1);
                
                // Jouer les deux meilleures cartes
                card best_card = get_card_in_hand(p, first_index);
                play_card(p, best_card);
                remove_card_from_hand(p, best_card);
                
                // L'index de la seconde meilleure carte a pu changer
                int new_best_index = find_highest_card_index(p);
                if (new_best_index != -1) {
                    card second_best = get_card_in_hand(p, new_best_index);
                    play_card(p, second_best);
                    remove_card_from_hand(p, second_best);
                }
                
                return 1;
            }
        }
    }
    
    // Vérifier si la meilleure carte dépasse la moyenne
    int best_index = find_highest_card_index(p);
    int best_value = get_value(get_card_in_hand(p, best_index));
    
    if (best_value > avg_value) {
        // Parier Victoire et jouer la meilleure carte
        set_slate(p, 1);
        card best_card = get_card_in_hand(p, best_index);
        play_card(p, best_card);
        remove_card_from_hand(p, best_card);
        return 1;
    } else {
        // Parier Défaite et jouer la plus petite carte
        set_slate(p, 0);
        int lowest_index = find_lowest_card_index(p);
        card lowest_card = get_card_in_hand(p, lowest_index);
        play_card(p, lowest_card);
        remove_card_from_hand(p, lowest_card);
        return 0;
    }
}

/**
 * \brief Stratégie agressive pour prendre une décision de jeu.
 * 
 * Regarde la plus petite (A) et la plus grande (B) carte en main.
 * Parie Victoire si A - 1 ≥ 5 - B, sinon parie Défaite.
 * Si Victoire, joue les deux plus grandes cartes (ou une si une seule reste).
 * Si Défaite, joue la plus petite carte.
 * 
 * \param p Le joueur qui doit prendre une décision.
 * \param b Le plateau de jeu actuel.
 * \return Le pari fait (0 pour Défaite, 1 pour Victoire).
 */
int agressive(player p, board b) {
    int hand_size = get_size_of_hand(p);
    
    // Si pas de cartes en main, parier Défaite par défaut
    if (hand_size == 0) {
        set_slate(p, 0);
        return 0;
    }
    
    // Trouver la plus petite et la plus grande carte
    int lowest_index = find_lowest_card_index(p);
    int highest_index = find_highest_card_index(p);
    
    int A = get_value(get_card_in_hand(p, lowest_index));  // Plus petite valeur
    int B = get_value(get_card_in_hand(p, highest_index)); // Plus grande valeur
    
    // Décider du pari selon la formule A - 1 ≥ 5 - B
    if (A - 1 >= 5 - B) {
        // Parier Victoire
        set_slate(p, 1);
        
        if (hand_size >= 2) {
            // Jouer les deux meilleures cartes
            int first_index, second_index;
            if (find_two_best_cards(p, &first_index, &second_index)) {
                // Jouer la meilleure carte
                card best_card = get_card_in_hand(p, first_index);
                play_card(p, best_card);
                remove_card_from_hand(p, best_card);
                
                // L'index de la seconde meilleure carte a pu changer
                int new_best_index = find_highest_card_index(p);
                if (new_best_index != -1) {
                    card second_best = get_card_in_hand(p, new_best_index);
                    play_card(p, second_best);
                    remove_card_from_hand(p, second_best);
                }
            }
        } else {
            // Jouer la seule carte disponible
            card only_card = get_card_in_hand(p, 0);
            play_card(p, only_card);
            remove_card_from_hand(p, only_card);
        }
        
        return 1;
    } else {
        // Parier Défaite
        set_slate(p, 0);
        
        // Jouer la plus petite carte
        card lowest_card = get_card_in_hand(p, lowest_index);
        play_card(p, lowest_card);
        remove_card_from_hand(p, lowest_card);
        
        return 0;
    }
}