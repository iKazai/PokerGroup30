#include <stdlib.h>
#include "../include/interface.h"

int main() {
    // Initialisation du plateau
    board b = create_board();

    // Ajout des équipes (2 équipes)
    add_team(b);
    add_team(b);

    // Création des joueurs (4 joueurs, 2 par équipe)
    for (int i = 0; i < 4; i++) {
        player p = create_player();
        int team_id = i % 2; // Alternance des équipes
        add_player_to_team(b, team_id, p);
    }

    // Création et distribution des cartes (20 cartes, 5 par joueur)
    for (int i = 0; i < 20; i++) {
        card c = create_card();
        set_value(c, (i % 5) + 1); // Cartes de 1 à 5
        int player_id = i % 4; // Distribution alternée aux joueurs
        player p = get_player(b, player_id / 2, player_id % 2);
        add_card_to_hand(p, c);
    }

    // Boucle de jeu (3 tours)
    for (int tour = 1; tour <= 3; tour++) {
        display_message("--- Début du tour ---");

        // Phase de paris
        for (int i = 0; i < 4; i++) {
            player p = get_player(b, i / 2, i % 2);
            int gamble = ask_gamble(p); // Demande le pari (1 pour Victoire, 0 pour Défaite)
            set_slate(p, gamble); // Enregistre le pari sur l'ardoise
        }

        // Phase de placement des cartes
        for (int i = 0; i < 4; i++) {
            player p = get_player(b, i / 2, i % 2);
            int nb_cards = ask_number_of_played_cards(p); // Demande combien de cartes poser (1 ou 2)
            for (int j = 0; j < nb_cards; j++) {
                card c = ask_card(p); // Demande quelle carte poser
                play_card(p, c); // Pose la carte sur la table
            }
        }

        // Calcul des points des équipes
        int score_team1 = 0;
        int score_team2 = 0;

        // Somme des valeurs des cartes posées par chaque équipe
        for (int i = 0; i < 4; i++) {
            player p = get_player(b, i / 2, i % 2);
            for (int j = 0; j < get_number_of_played_cards(p); j++) {
                card c = get_played_card(p, j);
                if (i < 2) { // Équipe 1 (joueurs 0 et 1)
                    score_team1 += get_value(c);
                } else { // Équipe 2 (joueurs 2 et 3)
                    score_team2 += get_value(c);
                }
            }
        }

        // Détermination de l'équipe gagnante et perdante du tour
        int winning_team = -1; // -1 signifie égalité
        if (score_team1 > score_team2) {
            winning_team = 0; // Équipe 1 gagne
        } else if (score_team2 > score_team1) {
            winning_team = 1; // Équipe 2 gagne
        }

        // Attribution des points en fonction des paris
        for (int i = 0; i < 4; i++) {
            player p = get_player(b, i / 2, i % 2);
            int gamble = get_slate(p);
            if (gamble == 1) { // Pari "Victoire"
                if (winning_team == i / 2) { // Si l'équipe du joueur a gagné
                    set_score_of_team(b, i / 2, get_score_of_team(b, i / 2) + 1);
                }
            } else { // Pari "Défaite"
                if (winning_team != -1 && winning_team != i / 2) { // Si l'équipe du joueur a perdu
                    set_score_of_team(b, i / 2, get_score_of_team(b, i / 2) + 1);
                }
            }
        }

        // Mise de côté des cartes jouées
        for (int i = 0; i < 4; i++) {
            player p = get_player(b, i / 2, i % 2);
            for (int j = 0; j < get_number_of_played_cards(p); j++) {
                card c = get_played_card(p, j);
                add_out_of_game_card(b, c); // Ajoute la carte aux cartes mises de côté
                remove_played_card(p, c); // Retire la carte de la table
            }
        }

        // Affichage du plateau après le tour
        display_board(b);
    }

    // Fin du jeu
    display_message("--- Fin du jeu ---");

    // Affichage des scores finaux
    int score_team1 = get_score_of_team(b, 0);
    int score_team2 = get_score_of_team(b, 1);

    // Détermination du vainqueur
    if (score_team1 > score_team2) {
        display_message("L'équipe 1 a gagné !");
    } else if (score_team2 > score_team1) {
        display_message("L'équipe 2 a gagné !");
    } else {
        display_message("Égalité ! La victoire est partagée.");
    }

    // Libération de la mémoire
    free_board(b);

    return 0;
}
