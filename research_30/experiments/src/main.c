#include <stdlib.h>
#include "interface.h"
#include "constante.h" // E.2 : Ajout pour utiliser les constantes

int main() {
    board b = create_board();

    // Ajout des équipes
    for (int i = 0; i < NUM_TEAMS; i++) { // E.2 : Utilisation de NUM_TEAMS
        add_team(b);
    }

    // Création des joueurs
    for (int i = 0; i < NUM_PLAYERS; i++) { // E.2 : Utilisation de NUM_PLAYERS
        player p = create_player();
        add_player_to_team(b, i % 2, p);
    }
    distribute_initial_tokens(b);

    // Création et distribution des cartes
    for (int value = 1; value <= MAX_CARD_VALUE; value++) { // E.2 : Utilisation de MAX_CARD_VALUE
        for (int color = COLOR_RED; color <= COLOR_BLACK; color++) { // E.2 : Boucle sur les couleurs
            for (int i = 0; i < 2; i++) { // Deux cartes par valeur et couleur
                card c = create_card();
                set_value(c, value);
                set_color(c, color); // E.2 : Définition de la couleur
                int player_id = (value + color + i) % NUM_PLAYERS; // Distribution alternée
                player p = get_player(b, player_id / 2, player_id % 2);
                add_card_to_hand(p, c);
            }
        }
    }

    // Boucle de jeu
    for (int tour = 1; tour <= NUM_ROUNDS; tour++) { // E.2 : Utilisation de NUM_ROUNDS
        display_message("--- Début du tour ---");
        display_tokens(b);

        // Phase de paris
        for (int i = 0; i < NUM_PLAYERS; i++) {
            player p = get_player(b, i / 2, i % 2);
            int gamble = ask_gamble(p);
            set_slate(p, gamble); // Phase de placement des cartes
        }

    }
}
 