#ifndef EVAL_H
#define EVAL_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "miroir.h"
#include "board.h"

/**
 * \brief Simule 20 jeux à n tours
 * \param n le nombre de tours
 * \ensures Affiche le temps mit
 */
void simulate_games(int n);

#endif
