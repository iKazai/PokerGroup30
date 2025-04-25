#include <assert.h>
#include "../include/card.h"

int main() {
    // Création d'une carte
    card c1 = create_card();
    assert(c1 != NULL);

    // Vérification de l'id
    int id1 = get_card_id(c1);
    assert(id1 == 0); // si c'est la première carte créée

    // Set et get value
    set_value(c1, 42);
    assert(get_value(c1) == 42);

    // Récupération par id
    card c2 = get_card_by_id(id1);
    assert(c2 == c1);

    // Libération
    free_card(c1);

    printf("Tous les tests card.c sont passés ! ✅\n");
    return 0;
}
