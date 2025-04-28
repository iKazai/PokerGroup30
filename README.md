# PokerGroup30 - Research Experiments

## Lancement du projet

Pour compiler et lancer les expérimentations dans `PokerGroup30/research/experiments`, utilisez la commande suivante (en attendant la correction du Makefile) :

```bash
cd PokerGroup30/research/experiments
gcc -Wall -Wextra -g -Iinclude main.c eval.c miroir.c src/board.c src/card.c src/interface.c src/player.c -o test_eval
