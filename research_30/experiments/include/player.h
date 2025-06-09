#ifndef PLAYER_H
#define PLAYER_H

#include "card.h" 
#include "constante.h" // E.2 : Ajout pour utiliser les constantes
#include <stdbool.h>

struct player_base {
    int id;
    card* deck;
    int deck_size;
    card* laids; 
    int laids_size;   
    bool slate; // Pari Victoire (true) ou Défaite (false)
    int team_id;
    int bet_color; // E.2 : Couleur pariée (0 pour rouge, 1 pour noir, 2 pour multicolore)
};

/**
 * \brief Type abstrait player
*/
typedef struct player_base* player;

// ... (autres déclarations inchangées) ...

/**
 * \brief Renvoie la couleur pariée par le joueur.
 * \param p Un joueur
 * \return Un entier correspondant à la couleur pariée (0 pour rouge, 1 pour noir, 2 pour multicolore)
 */
int get_bet_color(player p); // E.2 : Nouvelle fonction pour récupérer la couleur pariée

/**
 * \brief Définit la couleur pariée par le joueur.
 * \param p Un joueur
 * \param color Un entier représentant la couleur pariée
 */
void set_bet_color(player p, int color); // E.2 : Nouvelle fonction pour définir la couleur pariée

// ... (déclarations des fonctions E.3 inchangées) ...

#endif