#ifndef CARD_H
#define CARD_H
#include "board.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct card_base {
    int id;
    int value;
    
    bool is_special;
    char* name; 
    char* desc;
    
};


/**
 * \brief Définition d'un type abstrait card. Une variable de type card permet d'accéder aux informations d'une carte.
 */
typedef struct card_base* card;

/**
 * \brief Crée une nouvelle carte sans valeur initiale
 * \ensures Un identifiant unique lui est attribué.
 * \return card La carte nouvellement créée.
 */
card create_card();

/**
 * \brief Libère toute la mémoire allouée à une carte.
 * \param card La carte à libérer.
 * \ensures La mémoire est libérée, 
 * \ensures si c'est une carte spéciale, la mémoire de son nom et sa description son libérée
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
void set_value(card , int);



/*************** AJout du lot_e ***************/



/**
 * \brief Affiche le nom d'une carte spéciale dans la console et renvoie un pointeur sur le nom.
 * \param sc La carte dont on veut le nom
 * \return Un pointeur vers le nom de type char*
 * \ensures Un pointeur vers le nom est renvoyé.
 */
char* get_special_card_name(card sc);

/**
 * \brief Affiche la description d'une carte spéciale dans la console.
 * \param sc La carte dont on veut la description
 * \return void
 */
void display_special_card_desc(card sc);

#endif