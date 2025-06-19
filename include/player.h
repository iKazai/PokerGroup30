#ifndef PLAYER_H
#define PLAYER_H

#include "card.h" 
#include <stdbool.h>

struct player_base{
    int id;
    card* deck;
    int deck_size;
    card* laids; 
    int laids_size;   
    bool slate;
    int team_id;

    int tokens; // E.3 : nombre de jetons
    int current_bet; // E.3 : nombre de jetons misés
};

/**
 * \brief Type abstrait player
*/
typedef struct player_base* player;

/**
 * \brief Initialise un joueur sans carte en main, sans carte posée sur la table et avec une ardoise vide.
 * \return Un joueur
 * \assign La joueuse se voit attribuer un identifiant unique entier. Cette fonction devra allouer la mémoire nécessaire pour créer un nouveau plateau.
*/
player create_player(void);

/**
 * \brief Libère la mémoire d'un joueur
 * \param Un joueur
*/
void free_player(player);

/**
 * \brief Renvoie l'identifiant du joueur.
 * \param Un joueur
 * \return Un entier correspondant à l'identifiant du player
*/
int get_player_id(player);

/**
 * \brief Renvoie le joueur correspondant à l'identifiant
 * \param Un identifiant
 * \return Un joueur
*/
player get_player_by_id(int); 

/**
 * \brief Ajoute une carte dans la main d'un joueur
 * \param Un joueur et une carte
*/
void add_card_to_hand(player, card); 

/**
 * \brief Renvoie la taille de la main d'un joueur
 * \param Un joueur
 * \return Un entier correspondant à la taille de la main du joueur
*/
int get_size_of_hand(player);

/**
 * \brief Renvoie la carte d'index \a card_index du joueur
 * \param Un joueur et un entier \a card_index
 * \return Une carte
*/
card get_card_in_hand(player, int card_index);

/**
 * \brief Retire une carte d'un joueur
 * \param Un joueur et une carte
*/
void remove_card_from_hand(player, card);

/**
 * \brief Ajoute la carte aux cartes jouées sur la table par le joueur.
 * \param Un joueur et une carte
 * \assign Cette fonction ne modifie pas les cartes mises de côté ou les cartes en main. Chaque carte se voit attribuer un index.
*/
void play_card(player, card); 

/**
 * \brief  Renvoie le nombre de cartes jouées posées sur la table du joueur.
 * \param Un joueur
 * \return Un entier 
*/
int get_number_of_played_cards(player);

/**
 * \brief  Renvoie la carte jouée et posée sur la table par le joueur dont l'indice est card_index
 * \param Un joueur et un entier card_index
 * \return Une carte 
*/
card get_played_card(player, int card_index);

/**
 * \brief Supprime la carte de la table du joueur
 * \param Un joueur et une carte
 * \assign Les cartes se voient alors réattribuer un indice
*/
void remove_played_card(player, card);

/**
 * \brief Renvoie le pari de la joueuse écrit sur son ardoise
 * \param Un joueur
 * \return Un entier
*/
int get_slate(player);

/**
 * \brief Remplace le pari du joueur par le pari codé avec l'entier donné en entrée.
 * \param Un joueur et un entier
*/
void set_slate(player, int);  



/*************** AJout du lot_e ***************/


/* E.3 : Récupère le nombre total de jetons du joueur */
/**
 * \brief Renvoie le nombre total de jetons possédés par le joueur.
 * \param p Un joueur
 * \return Un entier correspondant au nombre de jetons
 */
int get_tokens(player p);

/* E.3 : Définit le nombre total de jetons du joueur */
/**
 * \brief Définit le nombre total de jetons du joueur.
 * \param p Un joueur
 * \param tokens Un entier représentant le nouveau nombre de jetons
 */
void set_tokens(player p, int tokens);

/* E.3 : Ajoute des jetons au total du joueur */
/**
 * \brief Ajoute un nombre de jetons au total du joueur.
 * \param p Un joueur
 * \param tokens Un entier représentant le nombre de jetons à ajouter
 */
void add_tokens(player p, int tokens);

/* E.3 : Définit le nombre de jetons misés dans le tour actuel */
/**
 * \brief Définit le nombre de jetons misés par le joueur dans le tour actuel.
 * \param p Un joueur
 * \param tokens Un entier représentant le nombre de jetons misés
 */
void set_current_bet(player p, int tokens);

/* E.3 : Récupère le nombre de jetons misés dans le tour actuel */
/**
 * \brief Renvoie le nombre de jetons misés par le joueur dans le tour actuel.
 * \param p Un joueur
 * \return Un entier correspondant au nombre de jetons misés
 */
int get_current_bet(player p);

/* E.3 : Retire des jetons du total du joueur */
/**
 * \brief Retire un nombre de jetons du total du joueur.
 * \param p Un joueur
 * \param tokens Un entier représentant le nombre de jetons à retirer
 */
void remove_tokens(player p, int tokens);

#endif
