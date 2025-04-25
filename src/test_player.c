#include <assert.h>
#include <stdio.h>
#include "../include/player.h"
#include "../include/card.h"

int main() {
    // Création du joueur
    player p = create_player();
    assert(p != NULL);  // Vérifie que le joueur a bien été créé
    assert(p->deck_size == 0);  // Vérifie que le joueur n'a pas de cartes au début

    // Création d'une carte
    card c = create_card();
    assert(c != NULL);  // Vérifie que la carte a bien été créée

    // Ajouter une carte à la main du joueur
    add_card_to_hand(p, c);
    assert(get_size_of_hand(p) == 1);  // Vérifie qu'il y a une carte dans la main du joueur
    assert(get_card_in_hand(p, 0) == c);  // Vérifie que la carte ajoutée est bien la bonne

    // Supprimer une carte de la main du joueur
    remove_card_from_hand(p, c);
    assert(get_size_of_hand(p) == 0);  // Vérifie que la main du joueur est vide

    // Ajouter à nouveau une carte à la main
    card c2 = create_card();
    assert(c2 != NULL);
    add_card_to_hand(p, c2);
    assert(get_size_of_hand(p) == 1);  // Vérifie qu'il y a encore une carte dans la main

    // Jouer une carte
    play_card(p, c2);
    assert(get_number_of_played_cards(p) == 1);  // Vérifie qu'une carte a été jouée
    assert(get_played_card(p, 0) == c2);  // Vérifie que la carte jouée est la bonne

    // Supprimer une carte jouée
    remove_played_card(p, c2);
    assert(get_number_of_played_cards(p) == 0);  // Vérifie qu'il n'y a plus de cartes jouées

    printf("Tests player.c ✅\n");
    return 0;
}
