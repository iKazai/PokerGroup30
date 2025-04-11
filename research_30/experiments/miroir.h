#ifndef MIROIR_H
#define MIROIR_H

#include "card.h"
#include "player.h"

/*
* \brief Génère un pari aléatoire pour un joueur
* \param Un joueur
* \return aléatoire un paris : true (Victoire) ou false (Défaite)
*/
bool paris_aleatoire(player p);



/*
* \brief Renvoie la valeur minimale d'une carte dans la main d'un joueur
* \param Un joueur
* \return Un entier correspondant à la valeur minimale d'une carte dans la main du joueur
*/
int find_min_card_value(player p);

/*
* \brief Renvoie la valeur maximale d'une carte dans la main d'un joueur
* \param Un joueur
* \return Un entier correspondant à la valeur maximale d'une carte dans la main du joueur
*/
int find_max_card_value(player p);

/*
* \brief Implémente le style de jeu agressif
* \param Un joueur
* \return Un booléen qui renvoie vrai si la condition d'agressivité est remplie, faux sinon
*/
bool agressive(player p);

#endif