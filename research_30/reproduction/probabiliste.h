/**
 * \file probabiliste.h
 * 
 * Ce fichier contient les signatures des fonctions implémentant les stratégies :
 * - La stratégie probabiliste, qui calcule une moyenne des cartes jouées pour décider du pari.
 * - La stratégie agressive, qui utilise les cartes extrêmes pour parier et jouer.
 */

 #ifndef PROBABILISTE_H
 #define PROBABILISTE_H
 
 #include "../../include/board.h"
 #include "../../include/player.h"
 
 /**
  * \brief Stratégie probabiliste qui décide du pari et des cartes à jouer.
  * 
  * Cette fonction calcule la valeur moyenne (M) des cartes déjà jouées et mises 
  * de côté, puis compare cette moyenne aux cartes dans la main du joueur pour
  * décider d'un pari et des cartes à jouer:
  * - Si le joueur peut dépasser M avec une ou deux cartes, il parie Victoire et joue ces cartes.
  * - Sinon, il parie Défaite et joue sa plus petite carte.
  *
  * \param p Le joueur qui doit prendre une décision.
  * \param b Le plateau de jeu actuel.
  * \return Le pari fait (0 pour Défaite, 1 pour Victoire).
  */
 int probabiliste(player p, board b);
 
 /**
  * \brief Stratégie agressive qui décide du pari et des cartes à jouer.
  * 
  * Cette fonction regarde la plus petite (A) et la plus grande (B) carte en main.
  * - Parie Victoire si A - 1 ≥ 5 - B, sinon parie Défaite.
  * - Si Victoire, joue les deux plus grandes cartes (ou une si une seule reste).
  * - Si Défaite, joue la plus petite carte.
  *
  * \param p Le joueur qui doit prendre une décision.
  * \param b Le plateau de jeu actuel.
  * \return Le pari fait (0 pour Défaite, 1 pour Victoire).
  */
 int agressive(player p, board b);
 
 #endif /* PROBABILISTE_H */