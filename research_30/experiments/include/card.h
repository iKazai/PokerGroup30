#ifndef CARD_H
#define CARD_H
#include <stdio.h>
#include "constants.h" // E.2 : Ajout pour utiliser les constantes de couleur

/**
 * \brief Définition d'un type abstrait card. Une variable de type card permet d'accéder aux informations d'une carte.
 */
struct card_base {
    int id;
    int value;
    int color; // E.2 : Ajout du champ pour la couleur (0 pour rouge, 1 pour noir)
};

typedef struct card_base* card;

/**
 * \brief Crée une nouvelle carte sans valeur ni couleur initiales
 * \ensures Un identifiant unique lui est attribué.
 * \return card La carte nouvellement créée.
 */
card create_card();

/**
 * \brief Libère toute la mémoire allouée à une carte.
 * \param card La carte à libérer.
 */
void free_card(card);

/**
 * \brief Récupère l'identifiant unique d'une carte.
 * \param card La carte dont on veut connaître l'ID.
 * \return int L'identifiant unique de la carte.
 */
int get_card_id(card);

/**
 * \brief Récupère une carte à partir de son identifiant unique.
 * \param int L'identifiant de la carte recherchée.
 * \return card La carte correspondant à l'ID donné.
 */
card get_card_by_id(int);

/**
 * \brief Récupère la valeur inscrite sur une carte.
 * \param card La carte dont on veut connaître la valeur.
 * \return int La valeur de la carte.
 */
int get_value(card);

/**
 * \brief Modifie la valeur d'une carte.
 * \param card La carte dont on veut changer la valeur.
 * \param int La nouvelle valeur de la carte.
 */
void set_value(card, int);

/*************** AJout du lot_e ***************/

/**
 * \brief Récupère la couleur d'une carte.
 * \param card La carte dont on veut connaître la couleur.
 * \return int La couleur de la carte (0 pour rouge, 1 pour noir).
 */
int get_color(card); // E.2 : Nouvelle fonction pour récupérer la couleur

/*************** AJout du lot_e ***************/

/**
 * \brief Modifie la couleur d'une carte.
 * \param card La carte dont on veut changer la couleur.
 * \param int La nouvelle couleur de la carte (0 pour rouge, 1 pour noir).
 */
void set_color(card, int); // E.2 : Nouvelle fonction pour définir la couleur

#endif