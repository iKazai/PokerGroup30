# Instructions pour lancer les expériences (Tâche D.2)

Ce répertoire contient les fichiers nécessaires pour exécuter les expériences de la tâche D. Les expériences évaluent la performance de l'algorithme implémenté dans `miroir.c`, mesurant le temps de calcul et le nombre de victoires d'une équipe utilisant cet algorithme.


## Structure du répertoire
- `main.c`, `eval.c`, `miroir.c` : Fichiers sources dans `research_30/experiments/`.
- `src/` : Contient `board.c`, `player.c`, `card.c`,`interface.c`(bien que pas utile ici) .
- `include/` : Contient les fichiers d'en-tête (`board.h`, `player.h`, `card.h` et `interface.c`(bien que pas utile ici)).
- `Makefile` : Fichier pour la compilation et l'exécution.

## Instructions pour lancer les expériences
1. Placez-vous dans le répertoire `research_30/experiments/` :
   ```bash
   cd research_30/experiments/
   ```
2. Compilez et exécutez les expériences avec la commande suivante :
   ```bash
   make run
   ```
   Cette commande :
   - Compile les fichiers sources en un exécutable nommé `poker_simulate`.
   - Exécute l'exécutable, qui lance une simulation de 20 parties avec un nombre de tours variant aléatoirement entre 3 et 20.
   - Affiche le nombre de parties gagnées par l'équipe 0 (utilisant l'algorithme de `miroir.c`), le pourcentage de victoires, et la durée totale de calcul.


4. Pour nettoyer l'exécutable généré:
   ```bash
   make clean
   ```
   Cela devrait supprimer `poker_simulate.exe`.

## Sortie des expériences
L'exécution affiche :
- Le nombre de parties gagnées par l'équipe 0 (utilisant l'algorithme de `miroir.c`).
- Le pourcentage de victoires.
- La durée totale de calcul (en secondes).

Exemple de sortie :
```
Nombre de parties gagnées par l'équipe 0 : 6
Pourcentage de victoires : 30.00%
Durée totale : 0.00s
```