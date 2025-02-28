#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "card.h"

typedef struct board_base* board;
struct board_base {
    player* p;
    card* c;
    int team_id[2];
    int score[2];
};


/**
 * \brief initialise un plateau sans joueur et sans carte 
 * \return un plateau sans joueur et sans carte
 */
board create_board();

/**
 * \brief libère l'espace allouée à un plateau
 * \param b : un plateau
 */
void free_board(board b);

/**
 * \brief Ajouter une équipe sur un plateau
 * \param b : un plateau

 */
void add_team(board b);

/**
 * \brief libère l'espace allouée à un plateau
 * \param b : un plateau
 * \return le nombre d'équipes présentes dans un plateau
 */
int get_number_of_teams(board b);

/**
 * \brief ajoute une joueuse à l'équipe dont l'idée 
 * \param b : un plateau
 * \param team_id : l'identifiant de l'équipe choisie
 * \param p : un joueur

 */
void add_player_to_team(board b, int team_id, player p);

/**
 * \brief renvoie le nombre de joueuses dans l'équipe dont l'id est team_id 
 * \param b : un plateau
 * \param team_id : l'identifiant de l'équipe choisie
 * \return un entier
 */
int get_number_of_players_in_team(board b, int* team_id);

/**
 * \brief renvoie la joueuse de l'équipe dont l'id est team_id et dont l'indice dans l'équipe est player_index.
 * \param b : un plateau
 * \param team_id : l'identifiant de l'équipe choisie
 * \param player_index : l'index d'un joueur
 * \return un joueur
 */
player get_player(board b, int team_id, int player_index);

/**
 * \brief renvoie le score de l'équipe dont l'id est team_id
 * \param b : un plateau
 * \param team_id : l'identifiant de l'équipe choisie
 * \return un entier, le socre de l'équipe
 */
int get_score_of_team(board b, int team_id);

/**
 * \brief remplace le score de l'équipe dont l'id est team_id par la valeur donnée en entrée
 * \param b : un plateau
 * \param team_id : l'identifiant de l'équipe choisie
 * \param n : un entier postif

 */
void set_score_of_team(board b, int team_id, int n);

/**
 * \brief ajoute la carte à l'ensemble des cartes mises de côté
 * \param b : un plateau
 * \param card : carte de jeu

 */
void add_out_of_game_card(board b, card c);

/**
 * \brief renvoie le nombre de cartes mises de côté
 * \param b : un plateau
 * \param team_id : carte de jeu
 * \return un entier, le nombre de cartes mises de côté
 */
int get_number_of_out_of_game_cards(board b, int team_id);

/**
 * \brief renvoie la carte mise de côté dont l'indice est card_index
 * \param b : un plateau
 * \param card_index : l'index d'une carte
 * \return une carte
 */
card get_out_of_game_card(board b, int card_index);

/**
 * \brief supprime la carte de l'ensemble des cartes mises de côté
 * \param b : un plateau
 * \param c : une carte
 */
void remove_out_of_game_card(board b, card c);


#endif