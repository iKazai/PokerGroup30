#ifndef MIROIR_H
#define MIROIR_H

#include "card.h"
#include "player.h"
#include <stdbool.h>

/** 
* \brief Génère un pari aléatoire pour un joueur
* \param Un joueur
* \return rien
*/
void paris_aleatoire(player p);



/** 
* \brief Renvoie la carte avec la valeur minimale dans la main d'un joueur
* \param Un joueur
* \return Une carte correspondant à la carte avec valeur minimale dans la main du joueur
*/
card find_min_card(player p);

/** 
* \brief Renvoie la carte avec la valeur maximal dans la main d'un joueur
* \param Un joueur
* \return Une carte correspondant à la carte avec valeur maximale dans la main du joueur
*/
card find_max_card(player p);

/**
* \brief Implémente le style de jeu agressif
* \param Un joueur
* \return Un booléen qui renvoie vrai si la condition d'agressivité est remplie, faux sinon
*/
bool agressive(player p);

#endif