#ifndef INTERFACE_H
#define INTERFACE_H
#include "board.h"
#include "player.h"
#include "card.h"
#include "constants.h" // E.2 : Ajout pour utiliser les constantes
#include <stdio.h>


/**
 * \brief Affiche toutes les informations du jeu (plateau, joueuses, équipes, scores, mains, paris, etc.).
 * \param board Le plateau de jeu contenant l'état actuel de la partie.
 */
void display_board(board);

/**
 * \brief Demande à une joueuse de donner son pari (Victoire/Défaite et couleur).
 * \param player Le joueur qui doit entrer un pari.
 * \return int Le pari encodé sous forme d'un entier (Victoire/Défaite).
 */
int ask_gamble(player); // E.2 : Modifiée pour inclure le choix de la couleur

int ask_number_of_cards(player);

/**
 * \brief Demande à une joueuse de choisir une carte de sa main.
 * \param player Le joueur en cours.
 * \return card La carte choisie par la joueuse.
 */
card ask_card(player);

/**
 * \brief Affiche le message de fin de jeu avec les informations associées.
 * \param board Le plateau de jeu à afficher en fin de partie.
 */
void display_end_game(board);

/**
 * \brief Affiche un message à l'écran.
 * \param message Le message à afficher.
 */
void display_message(char*);

#endif